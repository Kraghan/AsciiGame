#include "../Header/GraphicEngine.h"

GraphicEngine::GraphicEngine(int width, int height)
	: width(width), height(height)
{
	//initialise les width/height/mapGame variable
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
///	affiche le tableau sur la console
///
void GraphicEngine::display()
{
	if (cout)									//revient � la ligne si le cout contient something
		cout << endl;
	for (int i = 0; i < this->height; ++i)		//parcourt les Y...
	{
		for (int j = 0; j < this->width; ++j)	//parcourt les X..
		{
			cout << mapGame[i][j];				//affiche le caract�re [y][x]
		}
		cout << endl;							//fin de ligne
	}
}
