#include "../Headers/Window.h"
Window Window::instance = Window();

/*explicit*/ Window::Window()
{
	
}

/*virtual*/ Window::~Window()
{

}

/*static*/ Window* Window::getInstance()
{
	return &instance;
}

///
/// affiche la console
///
void Window::open(std::string title)
{
	HWND console = GetConsoleWindow();
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	// Set title
	SetConsoleTitle(title.c_str());
	Sleep(10);

	// Change font size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = FONT_SIZE;
	cfi.dwFontSize.Y = FONT_SIZE;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOutput, FALSE, &cfi);

	console = FindWindow(NULL, title.c_str());
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

void Window::clear(Vector2ui position, Vector2ui dimension)
{
	for (unsigned int i = position.y; i < position.y + dimension.y ; ++i)
	{
		for (unsigned int j = position.x; j < position.x + dimension.x; ++j)
		{
			buffer[i][j].Attributes = 15;
			buffer[i][j].Char.AsciiChar = ' ';
		}
	}
}

void Window::drawChar(unsigned int x, unsigned int y, char c, int color)
{
	if (y < 0 || y >= SCREEN_HEIGHT || x < 0 || x >= SCREEN_WIDTH)
		return;
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
