#include "../Header/GameStateMenu.h"

/*virtual*/ GameStateMenu::~GameStateMenu(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateMenu::init(GraphicEngine* e)
{
	engine = e;
}

// Update the game logic
/*virtual*/ void GameStateMenu::update()
{

}

// Process the input
/*virtual*/ bool GameStateMenu::processInput(void)
{
	return true;
}

// Called when the state is set to active
/*virtual*/ void GameStateMenu::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateMenu::onExit(void)
{

}