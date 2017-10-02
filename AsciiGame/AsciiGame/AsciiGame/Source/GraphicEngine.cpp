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
}

GraphicEngine::~GraphicEngine()
{

}

///
/// set la position du curseur
///
void GraphicEngine::gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

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
	if (!isChanged)
		return;
	gotoxy(0, 0);
	//cout.flush()
	//system("cls");								//clear console
	string map = "";
	for (int i = 0; i < this->height; ++i)		//parcourt les Y...
	{
		for (int j = 0; j < this->width; ++j)	//parcourt les X..
		{
			map += mapGame[i][j];				//affiche le caractère [y][x]
		}
		map += '\n';							//fin de ligne
	}
	cout << map << endl;
	gotoxy(0, this->height);
	this->isChanged = false;
	//this->Swap();
}
