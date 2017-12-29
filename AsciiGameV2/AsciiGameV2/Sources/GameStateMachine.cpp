#include "../Headers/GameStateMachine.h"

/*explicit*/ GameStateMachine::GameStateMachine()
	: currentState(nullptr)
{
	// Nothing to do
}

/*virtual*/ GameStateMachine::~GameStateMachine()
{
	// Nothing to do
}

bool GameStateMachine::registerGameState(std::string name, GameState* state)
{
	if (stateMap.count(name) == 1)
		return false;
	state->linkStateMachine(this);
	stateMap.insert(std::pair<std::string,GameState*>(name, state));
	return true;
}

bool GameStateMachine::activeState(std::string name, bool resetState)
{
	if (stateMap.count(name) == 0)
		return false;

	if(currentState != NULL)
		currentState->onExit();	

	currentState = stateMap.find(name)->second;

	if (resetState)
		currentState->init();

	currentState->onEnter();
	return true;
}

GameState* GameStateMachine::getActiveState()
{
	return currentState;
}