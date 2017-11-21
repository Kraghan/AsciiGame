#pragma once
#include "Weapon.h"

class Laser : public Weapon
{
private:

public:
	explicit Laser(void);
	virtual ~Laser(void);
	virtual std::vector<Bullet> shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti);
};