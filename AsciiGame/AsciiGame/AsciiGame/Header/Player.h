#pragma once

#include "Vector2.h"

class Player
{
	Vector2 pos;

public:
	Player();
	~Player();
private:
	void move();					//déplace le joueur

};

