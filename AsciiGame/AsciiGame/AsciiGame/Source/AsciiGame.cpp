// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Header/GraphicEngine.h"
#include "../Header/InputController.h"
#include "../Header/Timer.h"
#include "../Header/GameStateMachine.h"

#include "../Header/GameStateGame.h"
#include "../Header/GameStateMenu.h"
#include "../Header/GameStatePause.h"

using namespace std;

Timer timer;

GraphicEngine graphic;
GameStateMachine stateMachine;

// Return the time elapsed since the timer start
double getCurrentTime()
{
	return timer.getElapsedSeconds();
}

// Function used to processed all the input
bool processInput()
{
	return stateMachine.getActiveState()->processInput();
}

// Function used to update the game logic
void update()
{
	graphic.update();
	stateMachine.getActiveState()->update();
}

// Main function
int main()
{	
	// Initialization
	graphic = GraphicEngine(157, 44);
	stateMachine = GameStateMachine(&graphic);
	stateMachine.registerGameState("menu", (GameState*) new GameStateMenu());
	stateMachine.registerGameState("game", (GameState*) new GameStateGame());
	stateMachine.registerGameState("pause", (GameState*) new GameStatePause());
	stateMachine.activeState("game");
	//input = InputController();
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
		while (lag >= Timer::SECONDS_PER_UPDATE)
		{
			update();
			lag -= Timer::SECONDS_PER_UPDATE;

		}
		graphic.display();
	}
	// End gameloop

	system("pause");

    return (EXIT_SUCCESS);
}
