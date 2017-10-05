#include "../Header/GameStatePause.h"

/*virtual*/ GameStatePause::~GameStatePause(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStatePause::init(Window* wind)
{
	window = wind;
}

// Update the game logic
/*virtual*/ void GameStatePause::update()
{

}

// Process the input
/*virtual*/ bool GameStatePause::processInput(void)
{
	return true;
}

/*virtual*/ void GameStatePause::display()
{

}

// Called when the state is set to active
/*virtual*/ void GameStatePause::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStatePause::onExit(void)
{

}