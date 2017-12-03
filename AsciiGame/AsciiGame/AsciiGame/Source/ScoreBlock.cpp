#include "../Header/ScoreBlock.h"
unsigned int ScoreBlock::numberOfBlock = 0;
unsigned int ScoreBlock::level = 1;

/*virtual*/ void ScoreBlock::collect(Player* player)
{

	AudioHelper::getAudioHelper()->play("pickup");
	player->score += ScoreBlock::level * 100;
	ScoreBlock::numberOfBlock--;
}

/*virtual*/ void ScoreBlock::display(Window* window)
{
	Vector2 dimension = getDimension();
	Vector2 position = getPosition();
	char sprite = getSprite();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			window->changePixel(position.x * dimension.x + x, position.y * dimension.y + Window::UI_HEIGHT + y, sprite, 0x0E);
		}
	}
}