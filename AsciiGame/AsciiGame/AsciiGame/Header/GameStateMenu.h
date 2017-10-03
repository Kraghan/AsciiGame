#pragma once
#include "GameState.h"

class GameStateMenu : GameState
{
private:

public:
	virtual ~GameStateMenu(void);

	// Used to initialize the state
	void virtual init(GraphicEngine* engine);

	// Update the game logic
	void virtual update();

	// Process the input
	bool virtual processInput(void);

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);
};