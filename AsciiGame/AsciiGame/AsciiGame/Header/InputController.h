#pragma once

#include <windows.h>
#include <cstdlib>

#include <stack>
#include "Event.h"
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class InputController
{
private:
	std::stack<Event> * event;
	bool isPressed = false;

	std::map<int, int> stateKey;

public:
	InputController(std::stack<Event> * event);
	InputController();
	~InputController();

	void update();
};

