#pragma once			//que pour VS

#include <iostream>
#include <sstream>
using namespace std;

class GraphicEngine
{
	//variable
public:
	char **mapGameCurrent;							//map 2D du jeu (contenant des char)
	char **mapGameLoading;							//map 2D du jeu (contenant des char)

	int width;
	int height;

	//fonction
public:
	GraphicEngine(int width, int height);	//alloc la map
	~GraphicEngine();

	void display();							//affiche la map sur la console
	void Swap();
};

