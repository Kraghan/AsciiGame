#pragma once
#include "Weapon.h"

class Shotgun : public Weapon
{
private : 

public : 
	explicit Shotgun(void);
	virtual ~Shotgun(void);
	virtual std::vector<Bullet> shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti);
};