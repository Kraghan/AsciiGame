#include "../Header/GraphicEngine.h"

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
			mapGame[i][j] = 'a';
		}
	}
	ShowConsoleCursor(false);
}

GraphicEngine::~GraphicEngine()
{

}

int GraphicEngine::getRand(int min, int max)
{
	static bool init = false;

	if (!init) {
		srand(time(NULL));
		init = true;
	}

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
///change randomly un pixel de la map
///
void GraphicEngine::changeRandomPixel()
{
	changePixel(getRand(0, width), getRand(0, height), 'b');
}

///
/// set la position du curseur
///
void GraphicEngine::gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
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
