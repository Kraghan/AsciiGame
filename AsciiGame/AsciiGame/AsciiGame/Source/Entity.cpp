#include "..\Header\Entity.h"



Entity::Entity()
{

}

Entity::Entity(Vector2 pos, Vector2 dim)
	: pos(pos)
	, dimension(dim)
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