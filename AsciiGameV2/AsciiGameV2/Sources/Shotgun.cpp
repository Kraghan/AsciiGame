#include "../Headers/Shotgun.h"

/*explicit*/ Shotgun::Shotgun()
	: Weapon("Shotgun",3)
{
	radius = 3;
	timeBetweenShot = 0.5;
}

/*virtual*/ Shotgun::~Shotgun(void)
{

}

/*virtual*/ std::vector<Bullet> Shotgun::shoot(Vector2f playerPosition, MoveDirection orientation)
{
	std::vector<Bullet> vec = std::vector<Bullet>();
	switch (orientation)
	{
		case MoveDirection::LEFT : 
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1,0)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, -0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, 0.5f)));
			break;
		case MoveDirection::RIGHT:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, 0)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, -0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, 0.5f)));
			break;
		case MoveDirection::UP:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0, -1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-0.5, -1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0.5, -1)));
			break;
		case MoveDirection::DOWN:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0, 1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-0.5, 1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0.5, 1)));
			break;

		case MoveDirection::UP_LEFT:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, -1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, -0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-0.5f, -1)));
			break;
		case MoveDirection::UP_RIGHT:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, -1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, -0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0.5f, -1)));
			break;
		case MoveDirection::DOWN_LEFT:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, 1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-1, 0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(-0.5f, 1)));
			break;
		case MoveDirection::DOWN_RIGHT:
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, 1)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(1, 0.5f)));
			vec.push_back(Bullet(playerPosition, Vector2f(4, 4), 2, Vector2f(0.5f, 1)));
			break;

	}
	return vec;
}