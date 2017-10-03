#pragma once

#include <windows.h>
#include <cstdlib>

#include <stack>
#include "Event.h"

class InputController
{
	std::stack<Event> * event;
public:
	InputController(std::stack<Event> * event);
	InputController();
	~InputController();

	void update();
};

