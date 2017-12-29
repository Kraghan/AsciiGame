#pragma once
#include "GameState.h"
#include "AlphabetDrawer.h"
#include "AudioHelper.h"

class GameStateHow : GameState
{
private:

public:
	// Destructor
	virtual ~GameStateHow(void);

	// Used to initialize the state
	void virtual init(void);

	// Update the game logic
	void virtual update(void);

	// Process the input
	bool virtual processInput(void);

	// Called just before update in the gameloop
	void virtual display(void);

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);
};
