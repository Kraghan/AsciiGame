#include "..\Header\Entity.h"



Entity::Entity()
{

}

Entity::Entity(Vector2 pos, Vector2 dim)
	: bounds(pos,dim)
{
	oldPos = pos;
}

/* virtual */ Entity::~Entity()
{

}