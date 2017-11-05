#pragma once

#include "Vector2.h"
#include "AABB.h"

class Entity
{
public:
	enum MOVE_TYPE
	{
		M_NOTHING = -1,	//rien, etat initial
		M_UP = 0,
		M_DOWN = 1,
		M_RIGHT = 2,
		M_LEFT = 3,
		//diag
		M_UP_RIGHT = 4,
		M_UP_LEFT = 5,
		M_DOWN_RIGHT = 6,
		M_DOWN_LEFT = 7
	};

	AABB bounds;

	Vector2 oldPos;

	int speed = 1;

	int addHoriz = 0;
	int addVerti = 0;

	MOVE_TYPE moveType = M_NOTHING;				//le type de mouvement à faire dans l'update !

public:
	Entity();
	Entity(Vector2 pos, Vector2 dim);
	virtual ~Entity();
};

