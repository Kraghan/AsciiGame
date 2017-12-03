#include "../Header/Laser.h"

/*explicit*/ Laser::Laser(void)
	: Weapon("Laser",10)
{
	radius = 2;
	timeBetweenShot = 1;
}

/*virtual*/ Laser::~Laser(void)
{

}

/*virtual*/ std::vector<Bullet> Laser::shoot(Vector2 playerPosition, int addShootHoriz, int addShootVerti)
{
	std::vector<Bullet> vec = std::vector<Bullet>();
	for (int i = 0; i < 10; ++i)
	{
		Bullet bul = Bullet(playerPosition, addShootHoriz, addShootVerti);
		bul.setDelay(i);
		vec.push_back(bul);

	}
	return vec;
}