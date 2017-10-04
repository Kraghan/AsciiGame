#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(GraphicEngine* e)
{
	engine = e;
	gameMap = GameMap(150,25);
	BorderInitializer borderInit = BorderInitializer();
	borderInit.initialize(&gameMap);
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	gameMap.update();
	std::vector<std::vector<Block>> blocks = gameMap.getBlocks();

	for (unsigned int i = 0; i < blocks.size(); ++i)
	{
		for (unsigned int j = 0; j < blocks[i].size(); ++j)
		{
			engine->changePixel(i, j, blocks[i][j].getSprite());
		}
	}
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