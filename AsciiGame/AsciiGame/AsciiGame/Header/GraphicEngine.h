#pragma once			//que pour VS

#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

class GraphicEngine
{
	//variable
private:
	char **mapGame;							//map 2D du jeu (contenant des char)

	int width;
	int height;
	bool isChanged = true;


	//fonction
public:
	GraphicEngine(int width, int height);	//alloc la map
	~GraphicEngine();

	void display();							//affiche la map sur la console
	void gotoxy(int x, int y);				//set la position du curseur
	void changePixel(int x, int y, char c);	//change un pixel
};

