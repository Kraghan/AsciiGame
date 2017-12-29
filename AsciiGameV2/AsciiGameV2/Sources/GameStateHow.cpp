#include "../Headers/GameStateHow.h"

/*virtual*/ GameStateHow::~GameStateHow(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateHow::init(void)
{
	window = Window::getInstance();
}

// Update the game logic
/*virtual*/ void GameStateHow::update()
{

}

// Process the input
/*virtual*/ bool GameStateHow::processInput(void)
{
	Event* e = window->popEvent();
	while (e != nullptr)
	{
		// Quit game if escape pressed
		if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
			stateMachine->activeState("menu");

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStateHow::display()
{
	window->clear();

	for (unsigned int i = 0; i < Window::SCREEN_WIDTH; ++i)
	{
		window->drawChar(i, 0, 'X', ColorHelper::BLUE);
		window->drawChar(i, 1, 'X', ColorHelper::BLUE);
		window->drawChar(i, 2, 'X', ColorHelper::BLUE);
		window->drawChar(i, 3, 'X', ColorHelper::BLUE);

		window->drawChar(i, Window::SCREEN_HEIGHT - 1, 'X', ColorHelper::BLUE);
		window->drawChar(i, Window::SCREEN_HEIGHT - 2, 'X', ColorHelper::BLUE);
		window->drawChar(i, Window::SCREEN_HEIGHT - 3, 'X', ColorHelper::BLUE);
		window->drawChar(i, Window::SCREEN_HEIGHT - 4, 'X', ColorHelper::BLUE);
	}

	for (unsigned int i = 4; i < Window::SCREEN_HEIGHT - 4; ++i)
	{
		window->drawChar(0, i, 'X', ColorHelper::BLUE);
		window->drawChar(1, i, 'X', ColorHelper::BLUE);
		window->drawChar(2, i, 'X', ColorHelper::BLUE);
		window->drawChar(3, i, 'X', ColorHelper::BLUE);

		window->drawChar(Window::SCREEN_WIDTH - 1, i, 'X', ColorHelper::BLUE);
		window->drawChar(Window::SCREEN_WIDTH - 2, i, 'X', ColorHelper::BLUE);
		window->drawChar(Window::SCREEN_WIDTH - 3, i, 'X', ColorHelper::BLUE);
		window->drawChar(Window::SCREEN_WIDTH - 4, i, 'X', ColorHelper::BLUE);
	}

	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH/2 - 80, 10), "how to play", 3, 'X', ColorHelper::BLUE + ColorHelper::BRIGHT);

	AlphabetDrawer::drawWord(Vector2ui(20, 40), "controls", 2, 'X', ColorHelper::BLUE + ColorHelper::BRIGHT);

	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 4 - 30, 60), "move", 2, 'X', ColorHelper::BLUE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawZ(Vector2ui(Window::SCREEN_WIDTH / 4 - 15, 75), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawQ(Vector2ui(Window::SCREEN_WIDTH / 4 - 30, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawS(Vector2ui(Window::SCREEN_WIDTH / 4 - 15, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawD(Vector2ui(Window::SCREEN_WIDTH / 4, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);

	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 4 * 3 - 30, 60), "shoot", 2, 'X', ColorHelper::BLUE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawUp(Vector2ui(Window::SCREEN_WIDTH / 4 * 3 - 10, 75), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawLeft(Vector2ui(Window::SCREEN_WIDTH / 4 * 3 - 25, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawDown(Vector2ui(Window::SCREEN_WIDTH / 4 * 3 - 10, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);
	AlphabetDrawer::drawRight(Vector2ui(Window::SCREEN_WIDTH / 4 * 3 + 5, 90), 2, 'X', ColorHelper::BACK_WHITE + ColorHelper::BRIGHT);

	AlphabetDrawer::drawWord(Vector2ui(20, 120), "RULES", 2, 'X', ColorHelper::BLUE + ColorHelper::BRIGHT);
	for (unsigned int x = 20; x < 30; ++x)
		for (unsigned int y = 138; y < 148; ++y)
			window->drawChar(x, y, 'X', ColorHelper::YELLOW + ColorHelper::BRIGHT);
	AlphabetDrawer::drawWord(Vector2ui(40, 140), "Score pick up : pick them all to complete the level", 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	for (unsigned int x = 20; x < 30; ++x)
		for (unsigned int y = 153; y < 163; ++y)
			window->drawChar(x, y, 'X', ColorHelper::RED + ColorHelper::BRIGHT);
	AlphabetDrawer::drawWord(Vector2ui(40, 155), "Life pick up : pick them to heal yourself", 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	for (unsigned int x = 20; x < 30; ++x)
		for (unsigned int y = 168; y < 178; ++y)
			window->drawChar(x, y, 'X', ColorHelper::GREEN);
	AlphabetDrawer::drawWord(Vector2ui(40, 170), "Ammo pick up : pick them to get some ammo", 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	

	AlphabetDrawer::drawWord(Vector2ui(30, 200), "Shoot on walls to dig", 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);

	AlphabetDrawer::drawWord(Vector2ui(60, 220), "Press any key to return menu", 2, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
}

// Called when the state is set to active
/*virtual*/ void GameStateHow::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateHow::onExit(void)
{

}