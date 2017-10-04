#pragma once
#include "Window.h"
#include "GameState.h"
#include <string>
#include <map>

class GameStateMachine
{
private:
	std::map<std::string, GameState*> stateMap;
	GameState* currentState;
	Window* window;

public:
	explicit GameStateMachine();
	explicit GameStateMachine(Window * graphic);
	virtual ~GameStateMachine(void);

	// Allow to add a game state to the state machine.
	// Return false if a state registered with name exists.
	bool registerGameState(std::string name, GameState* state);

	// Set the state registered with name as currentState.
	// ResetState allow you to reinitialize the state when set to active.
	// Return false if the name state isn't registered.
	bool activeState(std::string name, bool resetState = false);

	// Return the active state
	GameState* getActiveState();
};