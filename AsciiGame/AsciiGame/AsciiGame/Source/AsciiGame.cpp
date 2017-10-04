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

// Main function
int main()
{	
	Timer timer;
	GraphicEngine graphic;
	GameStateMachine stateMachine;
	// Initialization
	graphic = GraphicEngine(GraphicEngine::TILE_WIDTH, GraphicEngine::TILE_HEIGHT);
	stateMachine = GameStateMachine(&graphic);
	stateMachine.registerGameState("menu", (GameState*) new GameStateMenu());
	stateMachine.registerGameState("game", (GameState*) new GameStateGame());
	stateMachine.registerGameState("pause", (GameState*) new GameStatePause());
	stateMachine.activeState("game");
	//input = InputController();
	timer = Timer();
	timer.start();
	double previous = timer.getElapsedSeconds();
	bool keepRunning = true;
	double lag = 0.0;

	// Start gameloop
	while (keepRunning)
	{
		// Time elapsed calculation since the last loop
		double current = timer.getElapsedSeconds();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		keepRunning = stateMachine.getActiveState()->processInput();

		// Lag compensation + FPS limitation
		while (lag >= Timer::SECONDS_PER_UPDATE)
		{
			graphic.update();
			stateMachine.getActiveState()->update();
			lag -= Timer::SECONDS_PER_UPDATE;

		}
		graphic.display();
	}
	// End gameloop

	system("pause");

    return (EXIT_SUCCESS);
}
