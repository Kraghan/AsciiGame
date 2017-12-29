#pragma once
#include "Weapon.h"

class BombThrower : public Weapon
{
private:

public:
	explicit BombThrower();
	virtual ~BombThrower();
	virtual std::vector<Bullet> shoot(Vector2f playerPosition, MoveDirection orientation);
};