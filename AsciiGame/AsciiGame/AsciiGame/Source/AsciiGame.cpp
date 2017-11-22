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
	AlphabetDrawer::drawWord(&window, Vector2(Window::SCREEN_WIDTH / 2 - 70,Window::SCREEN_HEIGHT / 2 - 20),"BYE BYE", 4, 'X', 0x09);
	AlphabetDrawer::drawWord(&window, Vector2(Window::SCREEN_WIDTH / 2 - 170, Window::SCREEN_HEIGHT / 2 + 10), "Thanks for playing", 4, 'X', 0x09);

	window.display();
	system("pause");

    return (EXIT_SUCCESS);
}
