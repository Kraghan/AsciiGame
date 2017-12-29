#include "../Headers/Laser.h"

/*explicit*/ Laser::Laser(void)
	: Weapon("Laser",10)
{
	radius = 2;
	timeBetweenShot = 1;
}

/*virtual*/ Laser::~Laser(void)
{

}

/*virtual*/ std::vector<Bullet> Laser::shoot(Vector2f playerPosition, MoveDirection orientation)
{
	float sqrt2 = sqrt(2);
	Vector2f sens = Vector2f(0, 0);
	switch (orientation)
	{
		case MoveDirection::LEFT:
			sens = Vector2f(-1, 0);
			break;
		case MoveDirection::RIGHT:
			sens = Vector2f(1, 0);
			break;
		case MoveDirection::UP:
			sens = Vector2f(0, -1);
			break;
		case MoveDirection::DOWN:
			sens = Vector2f(0, 1);
			break;
		case MoveDirection::UP_LEFT:
			sens = Vector2f(-1 / sqrt2, -1 / sqrt2);
			break;
		case MoveDirection::UP_RIGHT:
			sens = Vector2f(1 / sqrt2, -1 / sqrt2);
			break;
		case MoveDirection::DOWN_LEFT:
			sens = Vector2f(-1 / sqrt2, 1 / sqrt2);
			break;
		case MoveDirection::DOWN_RIGHT:
			sens = Vector2f(1 / sqrt2, 1 / sqrt2);
			break;
	}

	std::vector<Bullet> vec = std::vector<Bullet>();
	for (int i = 0; i < 10; ++i)
	{
		Bullet bul = Bullet(playerPosition,Vector2f(4,4),2,sens);
		bul.setDelay(i);
		vec.push_back(bul);

	}
	return vec;
}