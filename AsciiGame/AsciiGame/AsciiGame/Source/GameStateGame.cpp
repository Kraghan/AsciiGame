#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(GraphicEngine* e)
{
	engine = e;
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	engine->changeRandomPixel();
}

// Process the input
/*virtual*/ bool GameStateGame::processInput(void)
{
	Event* e = engine->popEvent();
	while (e != nullptr)
	{
		if (e->input == Event::INPUT::KB_ESCAPE 
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			cout << "Pause" << endl;
			stateMachine->activeState("pause");
		}
		e = engine->popEvent();
	}
	return true;
}

// Called when the state is set to active
/*virtual*/ void GameStateGame::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateGame::onExit(void)
{

}