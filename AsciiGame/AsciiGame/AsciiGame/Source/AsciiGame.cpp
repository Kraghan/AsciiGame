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
	stateMachine.registerGameState("game", (GameState*) new GameStateGame());
	stateMachine.registerGameState("pause", (GameState*) new GameStatePause());
	stateMachine.activeState("game", true);
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
	AlphabetDrawer::drawB(&window, Vector2(105, 34));
	AlphabetDrawer::drawY(&window, Vector2(110, 34));
	AlphabetDrawer::drawE(&window, Vector2(114, 34));

	AlphabetDrawer::drawB(&window, Vector2(124, 34));
	AlphabetDrawer::drawY(&window, Vector2(129, 34));
	AlphabetDrawer::drawE(&window, Vector2(134, 34));

	AlphabetDrawer::drawT(&window, Vector2(79, 44));
	AlphabetDrawer::drawH(&window, Vector2(84, 44));
	AlphabetDrawer::drawA(&window, Vector2(89, 44));
	AlphabetDrawer::drawN(&window, Vector2(94, 44));
	AlphabetDrawer::drawK(&window, Vector2(99, 44));
	AlphabetDrawer::drawS(&window, Vector2(104, 44));

	AlphabetDrawer::drawF(&window, Vector2(114, 44));
	AlphabetDrawer::drawO(&window, Vector2(119, 44));
	AlphabetDrawer::drawR(&window, Vector2(124, 44));

	AlphabetDrawer::drawP(&window, Vector2(134, 44));
	AlphabetDrawer::drawL(&window, Vector2(139, 44));
	AlphabetDrawer::drawA(&window, Vector2(144, 44));
	AlphabetDrawer::drawY(&window, Vector2(149, 44));
	AlphabetDrawer::drawI(&window, Vector2(153, 44));
	AlphabetDrawer::drawN(&window, Vector2(155, 44));
	AlphabetDrawer::drawG(&window, Vector2(160, 44));
	window.display();
	system("pause");

    return (EXIT_SUCCESS);
}
