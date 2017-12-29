#include "../Headers/Block.h"

/*explicit*/ Block::Block(void)
	: Block(true, false, ColorHelper::WHITE, Vector2ui(0,0), Vector2ui(0, 0))
{
	
}

/*explicit*/ Block::Block(bool solid, bool unbreakable, int col, Vector2ui position, Vector2ui dimension)
{
	bounds = AABBui(position, dimension);
	isSolid = solid;
	isUnbreakable = unbreakable;
	color = col;
	disabled = false;
}

/*virtual*/ Block::~Block(void)
{

}

/*virtual*/ void Block::display(Vector2f cameraPosition)
{
	if (disabled)
		return;
	for (unsigned int x = 0; x < bounds.getWidth(); ++x)
	{
		for (unsigned int y = 0; y < bounds.getHeight(); ++y)
		{
			Window::getInstance()->drawChar(bounds.getX() - cameraPosition.x + x, bounds.getY() - cameraPosition.y + y, 'X', color);
		}
	}
}

Vector2ui Block::getPosition()
{
	return bounds.position;
}

Vector2ui Block::getDimension()
{
	return bounds.dimension;
}

AABBui Block::getBounds()
{
	return bounds;
}


bool Block::solid()
{
	return isSolid;
}

bool Block::unbreakable()
{
	return isUnbreakable;
}


/*virtual*/ void Block::collect(Player* player)
{
	
}