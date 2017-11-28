#include "../Header/GameStatePause.h"

/*virtual*/ GameStatePause::~GameStatePause(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStatePause::init(Window* wind)
{
	window = wind;
	position = Vector2(125,35);
}

// Update the game logic
/*virtual*/ void GameStatePause::update()
{

}

// Process the input
/*virtual*/ bool GameStatePause::processInput(void)
{
	Event* e = window->popEvent();
	while (e != nullptr)
	{
		// Quit game if escape pressed
		if (e->input == Event::INPUT::KB_ESCAPE
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
			stateMachine->activeState("game");

		// Change focus if down or s pressed
		if ((e->input == Event::INPUT::KB_DOWN || e->input == Event::INPUT::KB_S)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_RESUME)
				focus = FB_NEWGAME;
			else if (focus == FB_NEWGAME)
				focus = FB_QUIT;
			else if (focus == FB_QUIT)
				focus = FB_RESUME;
		}

		// Change focus if up or z is pressed
		if ((e->input == Event::INPUT::KB_UP || e->input == Event::INPUT::KB_Z)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_RESUME)
				focus = FB_QUIT;
			else if (focus == FB_NEWGAME)
				focus = FB_RESUME;
			else if (focus == FB_QUIT)
				focus = FB_NEWGAME;
		}

		// Valid choice if space or enter pressed
		if ((e->input == Event::INPUT::KB_SPACE || e->input == Event::INPUT::KB_ENTER)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_RESUME)
				stateMachine->activeState("game");
			else if (focus == FB_QUIT)
				return false;
			else if (focus == FB_NEWGAME)
				stateMachine->activeState("preparation", true);
		}

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStatePause::display()
{
	window->clear(position, Vector2(150, 150));
	drawContour();

	AlphabetDrawer::drawWord(window, Vector2(position.x + 10, position.y + 10), "ASCII GAME", 3, 'X', 0x09);
	AlphabetDrawer::drawWord(window, Vector2(position.x + 40, position.y + 35), "PAUSE", 3, 'X', 0x09);

	switch (focus)
	{
	case FB_RESUME:
		AlphabetDrawer::drawWord(window, Vector2(position.x + 20, position.y + 75), "Resume game", 2, 'X', 0x0E);
		AlphabetDrawer::drawWord(window, Vector2(position.x + 55, position.y + 100), "New game");
		AlphabetDrawer::drawWord(window, Vector2(position.x + 55, position.y + 125), "Quit game");
		break;

	case FB_NEWGAME:
		AlphabetDrawer::drawWord(window, Vector2(position.x + 45, position.y + 75), "Resume game");
		AlphabetDrawer::drawWord(window, Vector2(position.x + 35, position.y + 100), "New game", 2, 'X', 0x0E);
		AlphabetDrawer::drawWord(window, Vector2(position.x + 55, position.y + 125), "Quit game");
		break;

	case FB_QUIT:
		AlphabetDrawer::drawWord(window, Vector2(position.x + 45, position.y + 75), "Resume game");
		AlphabetDrawer::drawWord(window, Vector2(position.x + 55, position.y + 100), "New game");
		AlphabetDrawer::drawWord(window, Vector2(position.x + 35, position.y + 125), "Quit game", 2, 'X', 0x0E);
		break;
	}

}

// Called when the state is set to active
/*virtual*/ void GameStatePause::onEnter(void)
{
	focus = FocusButton::FB_RESUME;
}

// Called when the state is set to inactive
/*virtual*/ void GameStatePause::onExit(void)
{

}

void GameStatePause::drawContour()
{
	for (unsigned int x = 0; x < 150; ++x)
	{
		window->changePixel(position.x + x, position.y, 'X', 0x0B);
		window->changePixel(position.x + x, position.y + 1, 'X', 0x0B);
		window->changePixel(position.x + x, position.y + 149, 'X', 0x0B);
		window->changePixel(position.x + x, position.y + 148, 'X', 0x0B);
	}

	for (unsigned int y = 0; y < 150; ++y)
	{
		window->changePixel(position.x, position.y + y, 'X', 0x0B);
		window->changePixel(position.x + 1, position.y + y, 'X', 0x0B);
		window->changePixel(position.x + 149, position.y + y, 'X', 0x0B);
		window->changePixel(position.x + 148, position.y + y, 'X', 0x0B);
	}
}