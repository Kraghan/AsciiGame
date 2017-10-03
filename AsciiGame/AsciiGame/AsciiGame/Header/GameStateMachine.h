#pragma once
#include "GameState.h"
#include <string>
#include <map>

class GameStateMachine
{
private:
	//std::map<std::string, GameState> stateMap;

public:
	explicit GameStateMachine(void);
	virtual ~GameStateMachine(void) = 0;

	//bool registerGameState(std::string name, GameState state);
	bool activeState(std::string name, bool resetState = false);
};