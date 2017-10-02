#pragma once			//que pour VS

#include <iostream>
using namespace std;

class GraphicEngine
{
	//variable
public:
	char **mapGame;							//map 2D du jeu (contenant des char)
	int width;
	int height;

	//fonction
public:
	GraphicEngine(int width, int height);	//alloc la map
	~GraphicEngine();

	void display();							//affiche la map sur la console
};

