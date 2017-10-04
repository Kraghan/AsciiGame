﻿#include "../Header/GraphicEngine.h"

GraphicEngine::GraphicEngine(int width, int height)
	: width(width), height(height)
{
	//initialise les width/height/mapGameCurrent/mapGameLoading variable
	this->mapGame = new char*[height];
	for (int i = 0; i < height; ++i)
	{
		mapGame[i] = new char[width];
		for (int j = 0; j < width; ++j)
		{
			mapGame[i][j] = ' ';
		}
	}

	input = InputController();
	//SetSizePolice();
	SetWindowConsoleSize();				//change la size de la window console
	
	ShowConsoleCursor(false);			//cache le pointeur APRES
	
}

///
///	destructor
///
GraphicEngine::~GraphicEngine()
{

}

///
/// remplie le tableau avec un seul caractère
///
void GraphicEngine::fillEverythingWith(char c)
{
	for (int i = 0; i < height; ++i)
	{
		mapGame[i] = new char[width];
		for (int j = 0; j < width; ++j)
		{
			mapGame[i][j] = c;
		}
	}
	isChanged = true;
}

///
///	Set la console window à une taille définie
///
void GraphicEngine::SetWindowConsoleSize()
{
	HWND console = GetConsoleWindow();						//get la console window

	////////////////////////////////////////////////////change texte
	SetConsoleTitle("AsciiGame");
	Sleep(10);												//Let the window to update the Title!
	console = FindWindow(NULL, "AsciiGame");				//change le nom

	////////////////////////////////////////////////////disable maximise
	HMENU hMenu = GetSystemMenu((HWND)console, FALSE);		//disable Maximize
	::DeleteMenu(hMenu, 4, MF_BYPOSITION);

	////////////////////////////////////////////////////change la size de la window

	
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, maxWidth, maxHeight, TRUE);
}

///
/// Change la taiill edu texte
///

void GraphicEngine::SetSizePolice()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 15;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

///
/// renvoi un nombre entier aléatoire entre min et max (inclu)
///
int GraphicEngine::getRand(int min, int max)
{
	static bool init = false;

	if (!init) {
		srand(time(NULL));
		init = true;
	}
	if (!((max - min) + min))
		return (0);
	return rand() % (max - min) + min;
}

void GraphicEngine::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

///
/// set la position du curseur
///
void GraphicEngine::gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////// fonction public /////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///
///	set la position du player
///
void GraphicEngine::displayPlayer(Vector2 pos)
{
	changePixel(pos.x, pos.y, 'P', 5);
}
///
/// set la position courante à un couloir, et la suivante à la position du player
///
void GraphicEngine::displayPlayer(Vector2 oldPos, Vector2 newPos)
{
	changePixel(oldPos.x, oldPos.y, ' ');
	changePixel(newPos.x, newPos.y, 'P', 5);
}

void GraphicEngine::displayBullet(Vector2 oldPos, Vector2 newPos)
{
	changePixel(oldPos.x, oldPos.y, ' ');
	changePixel(newPos.x, newPos.y, '*', 7);
}

void GraphicEngine::update()
{
	stack<Event*> e = input.pollEvent();

	while (!e.empty())
	{
		eventStack.push(e.top());
		e.pop();
	}
}

///
/// change un "pixel" du tableau
/// et dis à la classe qu'on a changé le tableau (il va changé dans display)
///
void GraphicEngine::changePixel(int x, int y, char c)
{
	this->mapGame[y][x] = c;
	isChanged = true;
}
void GraphicEngine::changePixel(int x, int y, char c, int color)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);				//get la console window
	SetConsoleTextAttribute(Console, color);

	this->mapGame[y][x] = c;
	isChanged = true;
}

///
///change randomly un pixel de la map
///
void GraphicEngine::changeRandomPixel()
{
	int x = getRand(2, width - 2);
	int y = getRand(2, height - 2);
	changePixel(x, y, ' ');
	changePixel(x + 1, y, ' ');
	changePixel(x - 1, y, ' ');
	changePixel(x, y - 1, ' ');
	changePixel(x, y + 1, ' ');
}

void GraphicEngine::clear()
{
	fillEverythingWith(' ');
}

///
///	affiche le tableau sur la console
///
void GraphicEngine::display()
{
	if (!isChanged)								//si on a changé, on affiche
		return;
	gotoxy(0, 0);								//on set le pointeur au début
	string map = "";
	for (int i = 0; i < this->height; ++i)		//parcourt les Y...
	{
		for (int j = 0; j < this->width; ++j)	//parcourt les X..
		{
			map += mapGame[i][j];				//affiche le caractère [y][x]
		}
		map += '\n';							//fin de ligne
	}
	cout << map << endl;						//affiche tout
	gotoxy(0, this->height);					//met le curseur à la fin
	this->isChanged = false;					//reset le changement
	//this->Swap();
}

Event* GraphicEngine::popEvent()
{
	Event* e = nullptr;
	if (!eventStack.empty())
	{
		e = eventStack.top();
		eventStack.pop();

	}
		
	return e;
}
