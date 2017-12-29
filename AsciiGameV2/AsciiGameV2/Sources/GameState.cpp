#include "../Headers/GameState.h"

GameState::GameState()
{
	// Nothing to do
}

GameState::~GameState()
{
	// Nothing to do
}

void GameState::linkStateMachine(GameStateMachine* machine)
{
	stateMachine = machine;
}