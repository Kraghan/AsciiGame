#pragma once

//the following line is necessary for the
//  GetConsoleWindow() function to work!
//it basically says that you are running this
//  program on Windows 2000 or higher
//to call BEFORE window.h
#define _WIN32_WINNT 0x0500

#include <Windows.h>
#include <string>
#include "Event.h"
#include "InputController.h"

class Window
{
private : 
	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	// Must be equal to SCREEN_WIDTH and SCREEN_HEIGHT
	CHAR_INFO buffer[150][150];

	InputController input;					//input controller
	stack<Event*> eventStack;
public : 
	const static unsigned int SCREEN_WIDTH = 150;
	const static unsigned int SCREEN_HEIGHT = 150;
	const static unsigned int FONT_SIZE = 15;

	explicit Window();
	virtual ~Window();

	void open(char* title);

	void display();
	void clear();
	void changePixel(int x, int y, char c, int color = 15);
	void update();

	void drawColorWithCode();
	Event* popEvent();
};