#include "../Header/GameStateGamePreparation.h"

/*virtual*/ GameStateGamePreparation::~GameStateGamePreparation(void)
{

}

/*virtual*/ void GameStateGamePreparation::init(Window* wind)
{
	window = wind;
}

/*virtual*/ void GameStateGamePreparation::update()
{

}

/*virtual*/ bool GameStateGamePreparation::processInput(void)
{
	return true;
}

/*virtual*/ void GameStateGamePreparation::display()
{


	for (unsigned int x = 0; x < Window::SCREEN_WIDTH; ++x)
	{
		window->changePixel(x, 0, 'X', 0x05);
		window->changePixel(x, 1, 'X', 0x05);
		window->changePixel(x, 2, 'X', 0x05);
		window->changePixel(x, 3, 'X', 0x05);

		window->changePixel(x, Window::SCREEN_HEIGHT - 1, 'X', 0x05);
		window->changePixel(x, Window::SCREEN_HEIGHT - 2, 'X', 0x05);
		window->changePixel(x, Window::SCREEN_HEIGHT - 3, 'X', 0x05);
		window->changePixel(x, Window::SCREEN_HEIGHT - 4, 'X', 0x05);
	}
	for (unsigned int y = 4; y < Window::SCREEN_HEIGHT; ++y)
	{
		window->changePixel(0, y, 'X', 0x05);
		window->changePixel(1, y, 'X', 0x05);
		window->changePixel(2, y, 'X', 0x05);
		window->changePixel(3, y, 'X', 0x05);

		window->changePixel(Window::SCREEN_WIDTH - 1, y, 'X', 0x05);
		window->changePixel(Window::SCREEN_WIDTH - 2, y, 'X', 0x05);
		window->changePixel(Window::SCREEN_WIDTH - 3, y, 'X', 0x05);
		window->changePixel(Window::SCREEN_WIDTH - 4, y, 'X', 0x05);
	}
}

/*virtual*/ void GameStateGamePreparation::onEnter(void)
{

}

/*virtual*/ void GameStateGamePreparation::onExit(void)
{

}