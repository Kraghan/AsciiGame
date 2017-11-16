#pragma once
#include "GameState.h"

class GameStateGamePreparation : GameState
{
private:

public:
	virtual ~GameStateGamePreparation(void);

	// Used to initialize the state
	void virtual init(Window* wind);

	// Update the game logic
	void virtual update();

	// Process the input
	bool virtual processInput(void);

	// Called just before update in the gameloop
	void virtual display();

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);
};