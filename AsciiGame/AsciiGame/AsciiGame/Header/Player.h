#pragma once

#include "Vector2.h"

class Player
{
	Vector2 pos;

public:
	Player();
	~Player();
private:
	void move();					//d�place le joueur

};

