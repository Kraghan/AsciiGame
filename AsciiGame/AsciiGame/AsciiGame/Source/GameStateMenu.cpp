#include "../Header/GameStateMenu.h"

/*virtual*/ GameStateMenu::~GameStateMenu(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateMenu::init(Window* wind)
{
	window = wind;
	focus = FB_PLAY;
	window->clear();
	drawContour();
	drawTitle();
}

// Update the game logic
/*virtual*/ void GameStateMenu::update()
{
	if (focus == FB_PLAY)
		drawPlayFocused();
	else
		drawPlay();

	if (focus == FB_QUIT)
		drawQuitFocused();
	else
		drawQuit();
}

// Process the input
/*virtual*/ bool GameStateMenu::processInput(void)
{
	Event* e = window->popEvent();
	while (e != nullptr)
	{
		// Quit game if escape pressed
		if (e->input == Event::INPUT::KB_ESCAPE
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
			return false;

		// Change focus if down or s pressed
		if ((e->input == Event::INPUT::KB_DOWN || e->input == Event::INPUT::KB_S)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_PLAY)
				focus = FB_QUIT;
			else if (focus == FB_QUIT)
				focus = FB_PLAY;
		}

		// Change focus if up or z is pressed
		if ((e->input == Event::INPUT::KB_UP || e->input == Event::INPUT::KB_Z)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_PLAY)
				focus = FB_QUIT;
			else if (focus == FB_QUIT)
				focus = FB_PLAY;
		}

		// Valid choice if space or enter pressed
		if ((e->input == Event::INPUT::KB_SPACE || e->input == Event::INPUT::KB_A)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			if (focus == FB_PLAY)
				stateMachine->activeState("game", true);
			else if (focus == FB_QUIT)
				return false;
		}

		e = window->popEvent();
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
	for (unsigned int i = 0; i < Window::SCREEN_WIDTH; ++i)
	{
		window->changePixel(i, 0, 'N');
		window->changePixel(i, 1, 'N');

		window->changePixel(i, Window::SCREEN_HEIGHT - 1, 'N');
		window->changePixel(i, Window::SCREEN_HEIGHT - 2, 'N');
	}

	for (unsigned int i = 0; i < Window::SCREEN_HEIGHT; ++i)
	{
		if (i == 0 || i == 1)
		{
			window->changePixel(0, i, '\\');
			window->changePixel(1, i, '\\');
			window->changePixel(2, i, '\\');

			window->changePixel(Window::SCREEN_WIDTH - 1, i, '/');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, '/');
			window->changePixel(Window::SCREEN_WIDTH - 3, i, '/');
		}
		else if (i == Window::SCREEN_HEIGHT - 1 || i == Window::SCREEN_HEIGHT - 2)
		{
			window->changePixel(0, i, '/');
			window->changePixel(1, i, '/');
			window->changePixel(2, i, '/');

			window->changePixel(Window::SCREEN_WIDTH - 1, i, '\\');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, '\\');
			window->changePixel(Window::SCREEN_WIDTH - 3, i, '\\');
		}
		else
		{
			window->changePixel(0, i, 'Z');
			window->changePixel(1, i, 'Z');
			window->changePixel(2, i, 'Z');

			window->changePixel(Window::SCREEN_WIDTH - 1, i, 'Z');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, 'Z');
			window->changePixel(Window::SCREEN_WIDTH - 3, i, 'Z');
		}

	}
}

void GameStateMenu::drawTitle()
{
	AlphabetDrawer::drawA(window, Vector2(20, 10));
	AlphabetDrawer::drawS(window, Vector2(25, 10));
	AlphabetDrawer::drawC(window, Vector2(30, 10));
	AlphabetDrawer::drawI(window, Vector2(35, 10));
	AlphabetDrawer::drawI(window, Vector2(37, 10));

	AlphabetDrawer::drawG(window, Vector2(42, 10));
	AlphabetDrawer::drawA(window, Vector2(47, 10));
	AlphabetDrawer::drawM(window, Vector2(52, 10));
	AlphabetDrawer::drawE(window, Vector2(57, 10));

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