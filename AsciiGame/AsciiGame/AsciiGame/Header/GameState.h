#pragma once
#include "GraphicEngine.h"
class GameState
{
private :

protected : 
	GraphicEngine * engine;

public :
	explicit GameState(void);
	virtual ~GameState(void);

	// Used to initialize the state
	void virtual init(GraphicEngine* engine) = 0;

	// Update the game logic
	void virtual update() = 0;

	// Process the input
	bool virtual processInput(void) = 0;

	// Called when the state is set to active
	void virtual onEnter(void) = 0;

	// Called when the state is set to inactive
	void virtual onExit(void) = 0;
};