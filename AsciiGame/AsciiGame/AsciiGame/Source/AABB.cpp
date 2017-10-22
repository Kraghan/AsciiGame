#include "../Header/AABB.h"

/*explicit*/ AABB::AABB()
{

};

/*explicit*/ AABB::AABB(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	: position(x, y)
	, dimension(width, height)
{

}

/*explicit*/ AABB::AABB(Vector2 pos, Vector2 dim)
	: position(pos)
	, dimension(dim)
{

}

/*virtual*/ AABB::~AABB() {}

bool AABB::contains(Vector2 point)
{
	return position.x <= point.x && point.x <= position.x + dimension.x
		&& position.y <= point.y && point.y <= position.y + dimension.y;
}

bool AABB::contains(AABB box)
{
	return contains(box.position) 
		&& contains(Vector2(box.position.x + box.dimension.x, box.position.y + box.dimension.y));
}

bool AABB::intersect(AABB box)
{
	return contains(box.position)
		|| contains(Vector2(box.position.x + box.dimension.x, box.position.y + box.dimension.y));
}