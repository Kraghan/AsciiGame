// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Header/GraphicEngine.h"

using namespace std;
const double MS_PER_UPDATE = 0.0333;

double getCurrentTime()
{
	return 0.0;
}

bool processInput()
{
	return true;
}

void update()
{

}

int main()
{	

	GraphicEngine graphic = GraphicEngine(50,50);

	double previous = getCurrentTime();
	bool keepRunning = true;
	double lag = 0.0;
	while (keepRunning)
	{
		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		keepRunning = processInput();

		while (lag >= MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}
		graphic.display();
	}

    return (EXIT_SUCCESS);
}
