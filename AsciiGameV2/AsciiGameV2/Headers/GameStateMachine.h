#pragma once
#include "Window.h"
#include "GameState.h"
#include <string>
#include <map>

class GameStateMachine
{
private:
	// Storage of game state
	std::map<std::string, GameState*> stateMap;
	
	// Pointer to the active state
	GameState* currentState;

public:
	// Constructor
	explicit GameStateMachine(void);

	// Destructor
	virtual ~GameStateMachine(void);

	// Allow to add a game state to the state machine.
	// Return false if a state registered with name exists.
	bool registerGameState(std::string name, GameState* state);

	// Set the state registered with name as currentState.
	// ResetState allow you to reinitialize the state when set to active.
	// Return false if the name state isn't registered.
	bool activeState(std::string name, bool resetState = false);

	// Return the active state
	GameState* getActiveState(void);
};