#pragma once
#include "Vector2.h"

class AABB
{
public : 
	Vector2 position;
	Vector2 dimension;

	explicit AABB();

	explicit AABB(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	explicit AABB(Vector2 pos, Vector2 dim);

	virtual ~AABB();

	bool contains(Vector2 point);
	bool contains(AABB box);
	bool intersect(AABB box);
};