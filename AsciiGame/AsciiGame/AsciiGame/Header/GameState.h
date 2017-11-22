#pragma once
#include "Window.h"
// Forward declaration, used to fix cyclic inclusion issues
class GameStateMachine;

class GameState
{
protected : 
	// Pointer to the window object
	Window * window;

	// Pointer to the state machine 
	GameStateMachine* stateMachine;

public :
	// Constructor
	explicit GameState(void);

	// Destructor
	virtual ~GameState(void);

	// Used to initialize the state
	void virtual init(Window* wind) = 0;

	// Update the game logic
	void virtual update(void) = 0;

	// Process the input
	bool virtual processInput(void) = 0;

	// Called just before update in the gameloop
	void virtual display(void) = 0;

	// Called when the state is set to active
	void virtual onEnter(void) = 0;

	// Called when the state is set to inactive
	void virtual onExit(void) = 0;

	// Setter of the stateMachine
	void linkStateMachine(GameStateMachine* machine);
};

// Forward declaration, used to fix cyclic import issues
#include "GameStateMachine.h"