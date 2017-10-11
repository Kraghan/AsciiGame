#include "../Header/Block.h"

//constructor
Block::Block()
{

}

Block::Block(unsigned int x, unsigned int y, char representation, bool solid)
	: position(Vector2(x,y))
	, sprite(representation)
	, isSolid(solid)
{

}

Block::Block(Vector2 pos, char representation, bool solid)
	: position(pos)
	, sprite(representation)
	, isSolid(solid)
{

}

//destructor
Block::~Block()
{

}

char Block::getSprite()
{
	return sprite;
}

Vector2 Block::getPosition()
{
	return position;
}

bool Block::getIsSolid()
{
	return isSolid;
}

void Block::setSprite(char representation)
{
	sprite = representation;
}

void Block::setPosition(Vector2 pos)
{
	position = pos;
}

void Block::setIsSolid(bool solid)
{
	isSolid = solid;
}

Vector2 Block::getDimension()
{
	return Vector2(4, 4);
}

void Block::display(Window* window)
{
	Vector2 dimension = getDimension();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			window->changePixel(position.x * dimension.x + x, position.y * dimension.y + Window::UI_HEIGHT + y, sprite);
		}
	}
}