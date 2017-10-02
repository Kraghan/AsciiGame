#include "../Header/GraphicEngine.h"

GraphicEngine::GraphicEngine(int width, int height)
	: width(width), height(height)
{
	//initialise les width/height/mapGameCurrent/mapGameLoading variable
	this->mapGameLoading = new char*[height];
	for (int i = 0; i < height; ++i)
	{
		mapGameLoading[i] = new char[width];
		for (int j = 0; j < width; ++j)
		{
			mapGameLoading[i][j] = 'a';
		}
	}

	this->mapGameCurrent = new char*[height];
	for (int i = 0; i < height; ++i)
	{
		mapGameCurrent[i] = new char[width];
		for (int j = 0; j < width; ++j)
		{
			mapGameCurrent[i][j] = 'a';
		}
	}

}

GraphicEngine::~GraphicEngine()
{

}

void GraphicEngine::Swap()
{
	
	char **tmp = mapGameCurrent;
	mapGameCurrent = mapGameLoading;
	mapGameLoading = tmp;
}


///
///	affiche le tableau sur la console
///
void GraphicEngine::display()
{
	//cout.flush()
	system("cls");								//clear console
	string map = "";
	for (int i = 0; i < this->height; ++i)		//parcourt les Y...
	{
		for (int j = 0; j < this->width; ++j)	//parcourt les X..
		{
			map += mapGameLoading[i][j];				//affiche le caractère [y][x]
		}
		map += '\n';							//fin de ligne
	}
	cout << map << endl;
	//this->Swap();
}
