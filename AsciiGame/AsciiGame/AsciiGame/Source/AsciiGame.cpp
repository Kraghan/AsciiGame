// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Header/GraphicEngine.h"
#include "../Header/InputController.h"
#include "../Header/Timer.h"

using namespace std;

const double SECONDS_PER_UPDATE = 1.0 / 60.0;
Timer timer;
InputController input;
GraphicEngine graphic;
//GraphicEngine graphic;

double getCurrentTime()
{
	return timer.getElapsedSeconds();
}

bool processInput()
{
	return (input.inputController());
}

void update()
{
	graphic.changeRandomPixel();
}

int main()
{	
	graphic = GraphicEngine(50,10);
	input = InputController();

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
