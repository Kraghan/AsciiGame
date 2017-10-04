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