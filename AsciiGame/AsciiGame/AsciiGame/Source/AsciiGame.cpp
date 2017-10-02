// AsciiGame.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Header/GraphicEngine.h"
#include "../Header/Timer.h"

using namespace std;

const double SECONDS_PER_UPDATE = 1.0 / 60.0;
Timer timer;

double getCurrentTime()
{
	return timer.getElapsedSeconds();
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
	GraphicEngine graphic = GraphicEngine(50,10);
	timer = Timer();
	timer.start();
	double previous = getCurrentTime();
	bool keepRunning = true;
	double lag = 0.0;
	while (keepRunning)
	{
		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		//keepRunning = false;
		keepRunning = processInput();

		while (lag >= SECONDS_PER_UPDATE)
		{
			update();
			lag -= SECONDS_PER_UPDATE;
		}
		graphic.display();
	}

	system("pause");

    return (EXIT_SUCCESS);
}
