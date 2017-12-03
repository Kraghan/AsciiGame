#include "../Header/Shotgun.h"

/*explicit*/ Shotgun::Shotgun()
	: Weapon("Shotgun",3)
{
	radius = 3;
	timeBetweenShot = 0.5;
}

/*virtual*/ Shotgun::~Shotgun(void)
{

}

/*virtual*/ std::vector<Bullet> Shotgun::shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti)
{
	std::vector<Bullet> vec = std::vector<Bullet>();
	vec.push_back(Bullet(playerPosition, addShootHoriz, addShootVerti));
	if (addShootHoriz != 0 && addShootVerti == 0)
	{
		vec.push_back(Bullet(playerPosition, addShootHoriz, 1));
		vec.push_back(Bullet(playerPosition, addShootHoriz, -1));
	}
	else if (addShootHoriz == 0 && addShootVerti != 0)
	{
		vec.push_back(Bullet(playerPosition, 1, addShootVerti));
		vec.push_back(Bullet(playerPosition, -1, addShootVerti));
	}
	else if (addShootHoriz != 0 && addShootVerti != 0)
	{
		vec.push_back(Bullet(playerPosition, 0, addShootVerti));
		vec.push_back(Bullet(playerPosition, addShootHoriz, 0));
	}
	return vec;
}