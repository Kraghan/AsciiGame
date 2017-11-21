#include "../Header/Weapon.h"

/*explicit*/ Weapon::Weapon(std::string n, unsigned int bullets)
{
	name = n;
	bulletPerShot = bullets;
}

/*virtual*/ Weapon::~Weapon()
{

}

int Weapon::getRadius()
{
	return radius;
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