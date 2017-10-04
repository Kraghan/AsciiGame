#include "../Header/GameStateMenu.h"

/*virtual*/ GameStateMenu::~GameStateMenu(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateMenu::init(GraphicEngine* e)
{
	engine = e;
	focus = FB_PLAY;
	e->clear();
	
}

// Update the game logic
/*virtual*/ void GameStateMenu::update()
{

}

// Process the input
/*virtual*/ bool GameStateMenu::processInput(void)
{
	Event* e = engine->popEvent();
	while (e != nullptr)
	{
		// Quit game if escape pressed
		if (e->input == Event::INPUT::KB_ESCAPE
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			return false;
		}

		// Change focus if down or s pressed
		if ((e->input == Event::INPUT::KB_DOWN || e->input == Event::INPUT::KB_S)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_PLAY)
			{
				focus = FB_QUIT;
			}
			else if (focus == FB_QUIT)
			{
				focus = FB_PLAY;
			}
		}

		// Change focus if up or z is pressed
		if ((e->input == Event::INPUT::KB_UP || e->input == Event::INPUT::KB_Z)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_PLAY)
			{
				focus = FB_QUIT;
			}
			else if (focus == FB_QUIT)
			{
				focus = FB_PLAY;
			}
		}

		// Valid choice if space or enter pressed
		if ((e->input == Event::INPUT::KB_SPACE || e->input == Event::INPUT::KB_A)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{

		}


		e = engine->popEvent();
	}
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

void GameStateMenu::drawContour()
{
	for (unsigned int i = 0; i < GraphicEngine::TILE_WIDTH; ++i)
	{
		engine->changePixel(i, 0, 'N');
		engine->changePixel(i, 1, 'N');

		engine->changePixel(i, GraphicEngine::TILE_HEIGHT - 1, 'N');
		engine->changePixel(i, GraphicEngine::TILE_HEIGHT - 2, 'N');
	}

	for (unsigned int i = 0; i < GraphicEngine::TILE_HEIGHT; ++i)
	{
		if (i == 0 || i == 1)
		{
			engine->changePixel(0, i, '\\');
			engine->changePixel(1, i, '\\');
			engine->changePixel(2, i, '\\');

			engine->changePixel(GraphicEngine::TILE_WIDTH - 1, i, '/');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 2, i, '/');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 3, i, '/');
		}
		else if (i == GraphicEngine::TILE_HEIGHT - 1 || i == GraphicEngine::TILE_HEIGHT - 2)
		{
			engine->changePixel(0, i, '/');
			engine->changePixel(1, i, '/');
			engine->changePixel(2, i, '/');

			engine->changePixel(GraphicEngine::TILE_WIDTH - 1, i, '\\');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 2, i, '\\');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 3, i, '\\');
		}
		else
		{
			engine->changePixel(0, i, 'Z');
			engine->changePixel(1, i, 'Z');
			engine->changePixel(2, i, 'Z');

			engine->changePixel(GraphicEngine::TILE_WIDTH - 1, i, 'Z');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 2, i, 'Z');
			engine->changePixel(GraphicEngine::TILE_WIDTH - 3, i, 'Z');
		}

	}
}

void GameStateMenu::drawTitle()
{

}

void GameStateMenu::drawPlay()
{

}

void GameStateMenu::drawPlayFocused()
{

}

void GameStateMenu::drawQuit()
{

}

void GameStateMenu::drawQuitFocused()
{

}