// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{	
	double lastTime = getCurrentTime();
	bool keepRunning = true;
	while (keepRunning)
	{
		double current = getCurrentTime();
		double elapsed = current - lastTime;
		keepRunning = processInput();
		update(elapsed);
		render();
		lastTime = current;
	}

    return (EXIT_SUCCESS);
}

double getCurrentTime()
{
	return 0.0;
}

bool processInput()
{
	return true;
}

void update(double elapsed)
{

}

void render()
{

}
