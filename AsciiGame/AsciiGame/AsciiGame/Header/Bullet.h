#pragma once

#include "Vector2.h"

class Bullet
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

	Vector2 pos;
	int addHoriz = 1;
	int addVerti = 1;
	int speedBullet = 1;

private:
	MOVE_TYPE moveType = M_NOTHING;				//le type de mouvement à faire dans l'update !

public:
	Bullet(Vector2 pos, MOVE_TYPE moveTry);
	~Bullet();

	void update(); //selon move, change pos;

private:
	void changeHorizVerti();
};

