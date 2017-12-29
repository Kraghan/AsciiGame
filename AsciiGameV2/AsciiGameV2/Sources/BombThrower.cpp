#include "../Headers/BombThrower.h"

/*explicit*/ BombThrower::BombThrower()
	: Weapon("Bomb Thrower",1)
{
	radius = 4;
	timeBetweenShot = 0.3;
}

/*virtual*/ BombThrower::~BombThrower()
{

}

/*virtual*/ std::vector<Bullet> BombThrower::shoot(Vector2f playerPosition, MoveDirection orientation)
{
	std::vector<Bullet> vec = std::vector<Bullet>();
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

	vec.push_back(Bullet(playerPosition,Vector2f(4,4),2,sens));
	return vec;
}