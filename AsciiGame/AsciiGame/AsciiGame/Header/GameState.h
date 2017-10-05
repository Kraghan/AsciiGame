#pragma once
#include "Window.h"
// Forward declaration, used to fix cyclic import issues
class GameStateMachine;

class GameState
{
protected : 
	Window * window;
	GameStateMachine* stateMachine;

public :
	explicit GameState(void);
	virtual ~GameState(void);

	// Used to initialize the state
	void virtual init(Window* wind) = 0;

	// Update the game logic
	void virtual update() = 0;

	// Process the input
	bool virtual processInput(void) = 0;

	// Called just before update in the gameloop
	void virtual display() = 0;

	// Called when the state is set to active
	void virtual onEnter(void) = 0;

	// Called when the state is set to inactive
	void virtual onExit(void) = 0;

	// Setter of the stateMachine
	void linkStateMachine(GameStateMachine* machine);
};

// Forward declaration, used to fix cyclic import issues
#include "GameStateMachine.h"