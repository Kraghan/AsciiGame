// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Header/InputController.h"
#include "../Header/Timer.h"
#include "../Header/GameStateMachine.h"

#include "../Header/GameStateGame.h"
#include "../Header/GameStateMenu.h"
#include "../Header/GameStatePause.h"
#include "../Header/GameStateGamePreparation.h"
#include "../Header/Window.h"

using namespace std;

// Main function
int main()
{	
	Window window = Window();
	window.open("Ascii Game");
	window.display();

	Timer timer;
	GameStateMachine stateMachine;
	// Initialization
	stateMachine = GameStateMachine(&window);
	stateMachine.registerGameState("menu", (GameState*) new GameStateMenu());
	stateMachine.registerGameState("preparation", (GameState*) new GameStateGamePreparation());
	stateMachine.registerGameState("game", (GameState*) new GameStateGame());
	stateMachine.registerGameState("pause", (GameState*) new GameStatePause());
	stateMachine.activeState("menu", true);
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
			window.update();
			stateMachine.getActiveState()->update();
			lag -= Timer::SECONDS_PER_UPDATE;

		}
		stateMachine.getActiveState()->display();
		window.display();
	}
	// End gameloop
	window.clear();

	// Bonus ;)
	AlphabetDrawer::drawB(&window, Vector2(105, 34), 1, 'X');
	AlphabetDrawer::drawY(&window, Vector2(110, 34), 1, 'X');
	AlphabetDrawer::drawE(&window, Vector2(114, 34), 1, 'X');

	AlphabetDrawer::drawB(&window, Vector2(124, 34), 1, 'X');
	AlphabetDrawer::drawY(&window, Vector2(129, 34), 1, 'X');
	AlphabetDrawer::drawE(&window, Vector2(134, 34), 1, 'X');

	AlphabetDrawer::drawT(&window, Vector2(79, 44), 1, 'X');
	AlphabetDrawer::drawH(&window, Vector2(84, 44), 1, 'X');
	AlphabetDrawer::drawA(&window, Vector2(89, 44), 1, 'X');
	AlphabetDrawer::drawN(&window, Vector2(94, 44), 1, 'X');
	AlphabetDrawer::drawK(&window, Vector2(99, 44), 1, 'X');
	AlphabetDrawer::drawS(&window, Vector2(104, 44), 1, 'X');

	AlphabetDrawer::drawF(&window, Vector2(114, 44), 1, 'X');
	AlphabetDrawer::drawO(&window, Vector2(119, 44), 1, 'X');
	AlphabetDrawer::drawR(&window, Vector2(124, 44), 1, 'X');

	AlphabetDrawer::drawP(&window, Vector2(134, 44), 1, 'X');
	AlphabetDrawer::drawL(&window, Vector2(139, 44), 1, 'X');
	AlphabetDrawer::drawA(&window, Vector2(144, 44), 1, 'X');
	AlphabetDrawer::drawY(&window, Vector2(149, 44), 1, 'X');
	AlphabetDrawer::drawI(&window, Vector2(153, 44), 1, 'X');
	AlphabetDrawer::drawN(&window, Vector2(155, 44), 1, 'X');
	AlphabetDrawer::drawG(&window, Vector2(160, 44), 1, 'X');
	window.display();
	system("pause");

    return (EXIT_SUCCESS);
}
