#include "../Header/BombThrower.h"

/*explicit*/ BombThrower::BombThrower()
	: Weapon("Bomb Thrower",1)
{
	radius = 12;
	timeBetweenShot = 0.3;
}

/*virtual*/ BombThrower::~BombThrower()
{

}

/*virtual*/ std::vector<Bullet> BombThrower::shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti)
{
	std::vector<Bullet> vec = std::vector<Bullet>();
	vec.push_back(Bullet(playerPosition,addShootHoriz,addShootVerti));
	return vec;
}