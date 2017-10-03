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

// Return the time elapsed since the timer start
double getCurrentTime()
{
	return timer.getElapsedSeconds();
}

// Function used to processed all the input
bool processInput()
{
	return (input.inputController());
}

// Function used to update the game logic
void update()
{
	graphic.changeRandomPixel();
}

// Main function
int main()
{	
	// Initialization
	graphic = GraphicEngine(119,29);
	input = InputController();
	timer = Timer();
	timer.start();
	double previous = getCurrentTime();
	bool keepRunning = true;
	double lag = 0.0;

	// Start gameloop
	while (keepRunning)
	{
		// Time elapsed calculation since the last loop
		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		keepRunning = processInput();

		// Lag compensation + FPS limitation
		while (lag >= SECONDS_PER_UPDATE)
		{
			update();
			lag -= SECONDS_PER_UPDATE;

		}
		graphic.display();
	}
	// End gameloop

	system("pause");

    return (EXIT_SUCCESS);
}
