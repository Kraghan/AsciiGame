#pragma once

//the following line is necessary for the
//  GetConsoleWindow() function to work!
//it basically says that you are running this
//  program on Windows 2000 or higher
//to call BEFORE window.h

// Undef to remove warning
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0500

#include <Windows.h>
#include <string>
#include "Event.h"
#include "InputController.h"
#include "Vector2.h"
#include "ColorHelper.h"
#include "AlphabetDrawer.h"


/* /!\  Singleton /!\ */
class Window
{
private : 
	explicit Window(void);
	virtual ~Window(void);

	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	// Must be equal to SCREEN_WIDTH and SCREEN_HEIGHT
	CHAR_INFO buffer[240][400];

	InputController input;					//input controller
	stack<Event*> eventStack;
public :
	const static unsigned int SCREEN_WIDTH = 400;
	const static unsigned int SCREEN_HEIGHT = 240;
	const static unsigned int UI_HEIGHT = 25;
	const static unsigned int FONT_SIZE = 3;
	const static unsigned int MAX_WIDTH = 1235;
	const static unsigned int MAX_HEIGHT = 760;

	static Window instance;
	static Window* getInstance();

	void open(std::string title);

	void display();
	void clear(Vector2ui position = Vector2ui(0,0), Vector2ui dimension = Vector2ui(SCREEN_WIDTH, SCREEN_HEIGHT));
	void drawChar(unsigned int x, unsigned int y, char c, int color = ColorHelper::WHITE + ColorHelper::BRIGHT);
	void update();

	Event* popEvent();
};