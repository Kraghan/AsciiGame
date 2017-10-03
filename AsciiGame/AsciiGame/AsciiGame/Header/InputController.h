#pragma once

#include <windows.h>
#include <cstdlib>

#include "Event.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class InputController
{
private:
	bool isPressed = false;

	map<int, int> stateKey;

public:
	InputController();
	~InputController();

	stack<Event*> pollEvent();
};

