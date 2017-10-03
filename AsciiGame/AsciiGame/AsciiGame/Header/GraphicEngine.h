#pragma once			//que pour VS

#include <iostream>
#include <sstream>
#include <stack>

//the following line is necessary for the
//  GetConsoleWindow() function to work!
//it basically says that you are running this
//  program on Windows 2000 or higher
//to call BEFORE window.h
#define _WIN32_WINNT 0x0500

#include <windows.h>
#include <ctime>
#include "Event.h"
#include "InputController.h"


using namespace std;

class GraphicEngine
{
	//variable
private:
	char **mapGame;							//map 2D du jeu (contenant des char)

	int width;								//size en x de la map
	int height;								//size en x de la map
	bool isChanged = true;					//l'affichage est-il chang� ?
	int maxWidth = 1300;					//size de la window en x
	int maxHeight = 800;					//size de la window en y

	InputController input;					//input controller
	stack<Event*> eventStack;

	//fonction
public:
	GraphicEngine() {};
	GraphicEngine(int width, int height);	//alloc la map
	~GraphicEngine();

	void display();							//affiche la map sur la console
	void clear();							//clear la console
	void changeRandomPixel();				//change un pixel random dans la map
	void changePixel(int x, int y, char c);	//change un pixel
	void changePixel(int x, int y, char c, int color);	//change un pixel
	void update();
	Event* popEvent();						// Retourne le sommet de la pile d'�v�nement. Retourne nullptr si vide

private:
	void gotoxy(int x, int y);				//set la position du curseur
	
	void ShowConsoleCursor(bool showFlag);	//cache le curseur de la console
	void SetWindowConsoleSize();				//resize la console window
	int getRand(int min, int max);			//retourne un nombre random entre min et max
	void fillEverythingWith(char c);		//remplie le tableau avec un seul caract�re
};

