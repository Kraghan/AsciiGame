// AsciiGame.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <iostream>
#include "../Headers/Timer.h"
#include "../Headers/Window.h"
#include "../Headers/AudioHelper.h"

#include "../Headers/InputController.h"
#include "../Headers/GameStateMachine.h"

#include "../Headers/GameStateHow.h"
#include "../Headers/GameStateGame.h"
#include "../Headers/GameStateMenu.h"
#include "../Headers/GameStatePause.h"
#include "../Headers/GameStateGamePreparation.h"

using namespace std;

// Main function
int main()
{

	// Init Singletons
	AudioHelper::getAudioHelper();

	Window* window = Window::getInstance();
	window->open("Ascii Game");
	window->display();

	Timer timer;
	GameStateMachine stateMachine;
	// Initialization
	stateMachine = GameStateMachine();
	stateMachine.registerGameState("menu", (GameState*) new GameStateMenu());
	stateMachine.registerGameState("how", (GameState*) new GameStateHow());
	stateMachine.registerGameState("preparation", (GameState*) new GameStateGamePreparation());
	stateMachine.registerGameState("game", (GameState*) new GameStateGame());
	stateMachine.registerGameState("pause", (GameState*) new GameStatePause());
	stateMachine.activeState("menu", true);

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
			window->update();
			stateMachine.getActiveState()->update();
			lag -= Timer::SECONDS_PER_UPDATE;

		}
		stateMachine.getActiveState()->display();
		window->display();
	}
	// End gameloop
	window->clear();

	// Bonus ;)
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 70, Window::SCREEN_HEIGHT / 2 - 20), "BYE BYE", 4, 'X', 0x09);
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 170, Window::SCREEN_HEIGHT / 2 + 10), "Thanks for playing", 4, 'X', 0x09);

	window->display();
	system("pause");

	return (EXIT_SUCCESS);
}
