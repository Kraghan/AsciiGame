// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>

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

void render()
{

}

int main()
{	

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
		render();
	}

    return (EXIT_SUCCESS);
}
