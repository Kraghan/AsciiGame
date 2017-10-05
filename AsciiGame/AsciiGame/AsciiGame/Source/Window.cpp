#include "../Header/Window.h"

/*explicit*/ Window::Window()
{
	
}

/*virtual*/ Window::~Window()
{

}

///
/// affiche la console
///
void Window::open(char* title)
{
	HWND console = GetConsoleWindow();

	// Set title
	SetConsoleTitle(title);
	Sleep(10);

	// Initialize window and buffer
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

	// !!!!!!!!!!!!!!!!!!!!!!!!! DOESN'T WORK !!!!!!!!!!!!!!!!!!!!
	// Disable resize
	console = FindWindow(NULL, "AsciiGame");

	HMENU hMenu = GetSystemMenu((HWND)console, FALSE);		//disable Maximize
	::DeleteMenu(hMenu, 4, MF_BYPOSITION);

	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	int maxWidth = 1300;
	int maxHeight = 800;
	MoveWindow(console, r.left, r.top, maxWidth, maxHeight, TRUE);

	// !!!!!!!!!!!!!!!!!!!!!!!!! END DOESN'T WORK !!!!!!!!!!!!!!!!
}


void Window::display()
{
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

void Window::clear()
{
	for (unsigned int i = 0; i < SCREEN_HEIGHT ; ++i)
	{
		for (unsigned int j = 0; j < SCREEN_WIDTH; ++j)
		{
			buffer[i][j].Attributes = 15;
			buffer[i][j].Char.AsciiChar = ' ';
		}
	}
}

void Window::changePixel(int x, int y, char c, int color)
{
	buffer[y][x].Attributes = color;
	buffer[y][x].Char.AsciiChar = c;
}

///
/// 
///
void Window::update()
{
	stack<Event*> e = input.pollEvent();

	while (!e.empty())
	{
		eventStack.push(e.top());
		e.pop();
	}
}

///
/// enlève un seul event
///
Event* Window::popEvent()
{
	Event* e = nullptr;
	if (!eventStack.empty())
	{
		e = eventStack.top();
		eventStack.pop();
	}
	return e;
}

///
/// fonction debug pour afficher tout les caractère coloré
///
void Window::drawColorWithCode()
{
	int col = 0, row = 0;
	for (int i = 0; i < 256; ++i)
	{
		if (i > 99)
		{
			if (col > SCREEN_WIDTH - 4)
			{
				++row;
				col = 0;
			}
			char const *chaine = std::to_string(i).c_str(); 
			changePixel(col, row, chaine[0] , i);
			changePixel(col, row, chaine[1], i);
			changePixel(col, row, chaine[2], i);
			col += 3;
		}
		else if (i > 9)
		{
			if (col > SCREEN_WIDTH - 3)
			{
				++row;
				col = 0;
			}
			char const *chaine = std::to_string(i).c_str();
			changePixel(col, row, chaine[0], i);
			changePixel(col, row, chaine[1], i);
			col += 2;
		}
		else
		{
			if (col > SCREEN_WIDTH - 2)
			{
				++row;
				col = 0;
			}
			char const *chaine = std::to_string(i).c_str();
			changePixel(col, row, chaine[0], i);
			col += 2;
		}
		changePixel(col, row, ' ', i);
	}
}