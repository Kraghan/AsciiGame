#include "../Headers/GameStateMenu.h"

/*virtual*/ GameStateMenu::~GameStateMenu(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateMenu::init(void)
{
	window = Window::getInstance();
	focus = FB_PLAY;
	hasChange = false;
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

			AudioHelper::getAudioHelper()->play("navigationMenu");
			if (focus == FB_PLAY)
				focus = FB_HOW;
			else if (focus == FB_HOW)
				focus = FB_QUIT;
			else if (focus == FB_QUIT)
				focus = FB_PLAY;
		}

		// Change focus if up or z is pressed
		if ((e->input == Event::INPUT::KB_UP || e->input == Event::INPUT::KB_Z)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{

			AudioHelper::getAudioHelper()->play("navigationMenu");
			if (focus == FB_PLAY)
				focus = FB_QUIT;
			else if (focus == FB_HOW)
				focus = FB_PLAY;
			else if (focus == FB_QUIT)
				focus = FB_HOW;
		}

		// Valid choice if space or enter pressed
		if ((e->input == Event::INPUT::KB_SPACE || e->input == Event::INPUT::KB_ENTER)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			AudioHelper::getAudioHelper()->play("navigationMenu");
			if (focus == FB_PLAY)
				stateMachine->activeState("preparation", true);
			else if (focus == FB_HOW)
				stateMachine->activeState("how", true);
			else if (focus == FB_QUIT)
				return false;
		}

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStateMenu::display()
{
	window->clear();
	drawContour();
	drawTitle();

	if (focus == FB_PLAY)
		drawPlayFocused();
	else
		drawPlay();

	if (focus == FB_HOW)
		AlphabetDrawer::drawWord(Vector2ui(60, 120), "How to play", 5, 'X', ColorHelper::YELLOW + ColorHelper::BRIGHT);
	else
		AlphabetDrawer::drawWord(Vector2ui(82, 122), "How to play", 4, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);

	if (focus == FB_QUIT)
		drawQuitFocused();
	else
		drawQuit();
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
		window->drawChar(i, 0, 'N');
		window->drawChar(i, 1, 'N');

		window->drawChar(i, Window::SCREEN_HEIGHT - 1, 'N');
		window->drawChar(i, Window::SCREEN_HEIGHT - 2, 'N');
	}

	for (unsigned int i = 0; i < Window::SCREEN_HEIGHT; ++i)
	{
		if (i == 0 || i == 1)
		{
			window->drawChar(0, i, '\\');
			window->drawChar(1, i, '\\');

			window->drawChar(Window::SCREEN_WIDTH - 1, i, '/');
			window->drawChar(Window::SCREEN_WIDTH - 2, i, '/');
		}
		else if (i == Window::SCREEN_HEIGHT - 1 || i == Window::SCREEN_HEIGHT - 2)
		{
			window->drawChar(0, i, '/');
			window->drawChar(1, i, '/');

			window->drawChar(Window::SCREEN_WIDTH - 1, i, '\\');
			window->drawChar(Window::SCREEN_WIDTH - 2, i, '\\');
		}
		else
		{
			window->drawChar(0, i, 'Z');
			window->drawChar(1, i, 'Z');

			window->drawChar(Window::SCREEN_WIDTH - 1, i, 'Z');
			window->drawChar(Window::SCREEN_WIDTH - 2, i, 'Z');
		}

	}
}

void GameStateMenu::drawTitle()
{
	unsigned int fontSize = 6;
	char caractere = 'X';
	Vector2ui initPos = Vector2ui(60, 10);
	AlphabetDrawer::drawWord(initPos, "ascii game", fontSize, caractere, ColorHelper::BLUE + ColorHelper::BRIGHT);
}

void GameStateMenu::drawPlay()
{
	unsigned int fontSize = 4;
	char caractere = 'X';
	Vector2ui initPos = Vector2ui(100, 92);

	AlphabetDrawer::drawWord(initPos, "play game", fontSize, caractere);
}

void GameStateMenu::drawPlayFocused()
{
	unsigned int fontSize = 5;
	char caractere = 'X';
	Vector2ui initPos = Vector2ui(80, 90);

	AlphabetDrawer::drawWord(initPos, "play game", fontSize, caractere, ColorHelper::YELLOW + ColorHelper::BRIGHT);
}

void GameStateMenu::drawQuit()
{
	unsigned int fontSize = 4;
	char caractere = 'X';
	Vector2ui initPos = Vector2ui(110, 152);
	
	AlphabetDrawer::drawWord(initPos, "quit game", fontSize, caractere);
}

void GameStateMenu::drawQuitFocused()
{
	unsigned int fontSize = 5;
	char caractere = 'X';
	Vector2ui initPos = Vector2ui(90, 150);

	AlphabetDrawer::drawWord(initPos, "quit game", fontSize, caractere, ColorHelper::YELLOW + ColorHelper::BRIGHT);
}