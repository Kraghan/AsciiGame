#pragma once
#include "Weapon.h"

class BombThrower : public Weapon
{
private:

public:
	explicit BombThrower();
	virtual ~BombThrower();
	virtual std::vector<Bullet> shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti);
};