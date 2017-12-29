#include "../Headers/Weapon.h"

/*explicit*/ Weapon::Weapon(std::string n, unsigned int bullets)
{
	name = n;
	bulletPerShot = bullets;
	timer.start();
}

/*virtual*/ Weapon::~Weapon()
{

}

int Weapon::getRadius()
{
	return radius * 4;
}

double Weapon::getTimeBetweenShoot()
{
	return timeBetweenShot;
}

std::string Weapon::getName()
{
	return name;
}

unsigned int Weapon::getBulletPerShot()
{
	return bulletPerShot;
}

bool Weapon::canShoot()
{
	return timer.getElapsedSeconds() >= timeBetweenShot;
}

void Weapon::resetTimer()
{
	timer.start();
}