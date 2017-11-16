#include "../Header/Block.h"

//constructor
Block::Block()
{

}

Block::Block(unsigned int x, unsigned int y, char representation, bool solid, bool collectable, bool unbreakable)
	: position(Vector2(x,y))
	, sprite(representation)
	, isSolid(solid)
	, isCollectable(collectable)
	, isUnbreakable(unbreakable)
{

}

Block::Block(Vector2 pos, char representation, bool solid, bool collectable, bool unbreakable)
	: position(pos)
	, sprite(representation)
	, isSolid(solid)
	, isCollectable(collectable)
	, isUnbreakable(unbreakable)
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

bool Block::getIsCollectable()
{
	return isCollectable;
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

/*virtual*/ void Block::display(Window* window)
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

/*virtual*/ void Block::collect(Player* player)
{
	
}

bool Block::getIsUnbreakable()
{
	return isUnbreakable;
}