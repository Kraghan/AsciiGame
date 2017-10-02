#pragma once			//que pour VS

#include <iostream>

class GraphicEngine
{
	//variable
public:
	char **mapGame;							//map 2D du jeu (contenant des char)

	//fonction
public:
	GraphicEngine(int width, int height);	//alloc la map
	~GraphicEngine();

	void display();							//affiche la map sur la console
};

