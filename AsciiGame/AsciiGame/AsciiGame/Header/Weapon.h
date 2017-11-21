#pragma once
#include "Bullet.h"
#include "Timer.h"
#include <vector>

class Weapon
{
protected : 
	int radius;
	unsigned int bulletPerShot;
	double timeBetweenShot;
	std::string name;

public : 
	explicit Weapon(std::string name, unsigned int bullets);
	virtual ~Weapon();

	unsigned int getBulletPerShot();
	int getRadius();
	double getTimeBetweenShoot();
	virtual std::vector<Bullet> shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti) = 0;
	std::string getName();

};