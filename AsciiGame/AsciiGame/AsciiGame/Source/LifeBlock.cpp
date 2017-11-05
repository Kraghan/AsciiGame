#include "../Header/LifeBlock.h"

/*virtual*/ void LifeBlock::collect(Player* player)
{
	player->addLifePoint(2);
}

/*virtual*/ void LifeBlock::display(Window* window)
{
	Vector2 dimension = getDimension();
	Vector2 position = getPosition();
	char sprite = getSprite();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			window->changePixel(position.x * dimension.x + x, position.y * dimension.y + Window::UI_HEIGHT + y, sprite, 0x0C);
		}
	}
}