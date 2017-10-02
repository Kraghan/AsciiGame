#include "GraphicEngine.h"

GraphicEngine::GraphicEngine(int width, int height)
{
	//this->mapGame = new char[width][height];
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

void GraphicEngine::display()
{

}
