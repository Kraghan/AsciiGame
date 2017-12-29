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
	Timer timer;
	std::string name;

public : 
	explicit Weapon(std::string name, unsigned int bullets);
	virtual ~Weapon();

	unsigned int getBulletPerShot();
	int getRadius();
	double getTimeBetweenShoot();
	bool canShoot();
	virtual std::vector<Bullet> shoot(Vector2f playerPosition, MoveDirection orientation) = 0;
	std::string getName();
	void resetTimer();
};