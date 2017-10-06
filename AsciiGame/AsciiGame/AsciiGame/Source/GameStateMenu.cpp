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
	hasChange = true;
}

// Update the game logic
/*virtual*/ void GameStateMenu::update()
{
	
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
			hasChange = true;
			if (focus == FB_PLAY)
				focus = FB_QUIT;
			else if (focus == FB_QUIT)
				focus = FB_PLAY;
		}

		// Change focus if up or z is pressed
		if ((e->input == Event::INPUT::KB_UP || e->input == Event::INPUT::KB_Z)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			hasChange = true;
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

/*virtual*/ void GameStateMenu::display()
{
	if (hasChange)
	{

		window->clear();
		drawContour();
		drawTitle();

		if (focus == FB_PLAY)
			drawPlayFocused();
		else
			drawPlay();

		if (focus == FB_QUIT)
			drawQuitFocused();
		else
			drawQuit();

		hasChange = false;
	}
	
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

			window->changePixel(Window::SCREEN_WIDTH - 1, i, '/');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, '/');
		}
		else if (i == Window::SCREEN_HEIGHT - 1 || i == Window::SCREEN_HEIGHT - 2)
		{
			window->changePixel(0, i, '/');
			window->changePixel(1, i, '/');

			window->changePixel(Window::SCREEN_WIDTH - 1, i, '\\');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, '\\');
		}
		else
		{
			window->changePixel(0, i, 'Z');
			window->changePixel(1, i, 'Z');

			window->changePixel(Window::SCREEN_WIDTH - 1, i, 'Z');
			window->changePixel(Window::SCREEN_WIDTH - 2, i, 'Z');
		}

	}
}

void GameStateMenu::drawTitle()
{
	unsigned int fontSize = 6;
	char caractere = 'X';
	Vector2 initPos = Vector2(60, 10);

	AlphabetDrawer::drawA(window, initPos, fontSize, caractere, 0x09);
	AlphabetDrawer::drawS(window, Vector2(initPos.x + 5 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawC(window, Vector2(initPos.x + 10 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawI(window, Vector2(initPos.x + 15 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawI(window, Vector2(initPos.x + 17 * fontSize, initPos.y), fontSize, caractere, 0x09);

	AlphabetDrawer::drawG(window, Vector2(initPos.x + 22 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 27 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawM(window, Vector2(initPos.x + 32 * fontSize, initPos.y), fontSize, caractere, 0x09);
	AlphabetDrawer::drawE(window, Vector2(initPos.x + 37 * fontSize, initPos.y), fontSize, caractere, 0x09);

}

void GameStateMenu::drawPlay()
{
	unsigned int fontSize = 4;
	char caractere = 'X';
	Vector2 initPos = Vector2(100, 92);

	AlphabetDrawer::drawP(window, initPos, fontSize, caractere);
	AlphabetDrawer::drawL(window, Vector2(initPos.x + 5 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 10 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawY(window, Vector2(initPos.x + 15 * fontSize, initPos.y), fontSize, caractere);

	AlphabetDrawer::drawG(window, Vector2(initPos.x + 23 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 28 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawM(window, Vector2(initPos.x + 33 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawE(window, Vector2(initPos.x + 38 * fontSize, initPos.y), fontSize, caractere);
}

void GameStateMenu::drawPlayFocused()
{
	unsigned int fontSize = 5;
	char caractere = 'X';
	Vector2 initPos = Vector2(80, 90);

	AlphabetDrawer::drawP(window, initPos, fontSize, caractere, 0x0E);
	AlphabetDrawer::drawL(window, Vector2(initPos.x + 5 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 10 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawY(window, Vector2(initPos.x + 15 * fontSize, initPos.y), fontSize, caractere, 0x0E);

	AlphabetDrawer::drawG(window, Vector2(initPos.x + 23 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 28 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawM(window, Vector2(initPos.x + 33 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawE(window, Vector2(initPos.x + 38 * fontSize, initPos.y), fontSize, caractere, 0x0E);
}

void GameStateMenu::drawQuit()
{
	unsigned int fontSize = 4;
	char caractere = 'X';
	Vector2 initPos = Vector2(110, 122);

	AlphabetDrawer::drawQ(window, initPos, fontSize, caractere);
	AlphabetDrawer::drawU(window, Vector2(initPos.x + 5 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawI(window, Vector2(initPos.x + 10 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawT(window, Vector2(initPos.x + 12 * fontSize, initPos.y), fontSize, caractere);

	AlphabetDrawer::drawG(window, Vector2(initPos.x + 20 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 25 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawM(window, Vector2(initPos.x + 30 * fontSize, initPos.y), fontSize, caractere);
	AlphabetDrawer::drawE(window, Vector2(initPos.x + 35 * fontSize, initPos.y), fontSize, caractere);
}

void GameStateMenu::drawQuitFocused()
{
	unsigned int fontSize = 5;
	char caractere = 'X';
	Vector2 initPos = Vector2(90, 120);

	AlphabetDrawer::drawQ(window, initPos, fontSize, caractere, 0x0E);
	AlphabetDrawer::drawU(window, Vector2(initPos.x + 5 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawI(window, Vector2(initPos.x + 10 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawT(window, Vector2(initPos.x + 12 * fontSize, initPos.y), fontSize, caractere, 0x0E);

	AlphabetDrawer::drawG(window, Vector2(initPos.x + 20 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawA(window, Vector2(initPos.x + 25 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawM(window, Vector2(initPos.x + 30 * fontSize, initPos.y), fontSize, caractere, 0x0E);
	AlphabetDrawer::drawE(window, Vector2(initPos.x + 35 * fontSize, initPos.y), fontSize, caractere, 0x0E);
}