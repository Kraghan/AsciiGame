#include "..\Header\Entity.h"



Entity::Entity()
{

}

Entity::Entity(Vector2 pos)
	: pos(pos)
{
	oldPos = pos;
}

/* virtual */ Entity::~Entity()
{

}

///
/// actualise la position pour les colisions
///
void Entity::setupRealPos()
{
	position.x = pos.x - (dimension.x / 2);
	position.y = pos.y - (dimension.y / 2);
}