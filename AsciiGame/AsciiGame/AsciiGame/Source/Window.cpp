#include "../Header/Window.h"

/*explicit*/ Window::Window()
{
	
}

/*virtual*/ Window::~Window()
{

}

void Window::open(char* title)
{
	HWND console = GetConsoleWindow();
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	// Set title
	SetConsoleTitle(title);
	Sleep(10);

	// Change font size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = FONT_SIZE;
	cfi.FontFamily = FF_ROMAN;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOutput, FALSE, &cfi);

	console = FindWindow(NULL, title);
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, MAX_WIDTH, MAX_HEIGHT, FALSE);

	// Remove resize border + vertical scroll bar + maximize button
	LONG lStyle = GetWindowLong(console, GWL_STYLE);
	lStyle &= ~(WS_VSCROLL | WS_SIZEBOX | WS_MAXIMIZEBOX);
	SetWindowLong(console, GWL_STYLE, lStyle);

	// Applique les changements
	SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);

	// Initialize window and buffer
	dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

	// Hide cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOutput, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &cursorInfo);
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

void Window::update()
{
	stack<Event*> e = input.pollEvent();

	while (!e.empty())
	{
		eventStack.push(e.top());
		e.pop();
	}
}

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