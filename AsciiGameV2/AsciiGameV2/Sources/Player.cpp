#include "../Headers/Player.h"

/*explicit*/ Player::Player()
	: Player(Vector2f(0,Window::UI_HEIGHT), Vector2f(8,8))
{

}

/*explicit*/ Player::Player(Vector2f position, Vector2f dimension)
	: Entity(10,1.5f,position,dimension)
	, ammo(12)
	, score(0)
	, weapon(new BombThrower())
	, shootDirection(MoveDirection::NONE)
{

}

/*virtual*/ Player::~Player()
{

}

/*virtual*/ void Player::display(Vector2f camera)
{
	int x = bounds.getX() - camera.x;
	int y = bounds.getY() - camera.y;

	window->drawChar(x, y, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 1, y, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 2, y, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 3, y, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);

	window->drawChar(x, y + 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 1, y + 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 2, y + 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 3, y + 1, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);

	window->drawChar(x, y + 2, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 1, y + 2, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 2, y + 2, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 3, y + 2, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);

	window->drawChar(x, y + 3, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 1, y + 3, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 2, y + 3, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);
	window->drawChar(x + 3, y + 3, 'X', ColorHelper::WHITE + ColorHelper::BRIGHT);


	for (int xx = 0; xx < bounds.getWidth(); ++xx)
	{
		window->drawChar(x + xx, y, 'X', ColorHelper::PURPLE + ColorHelper::BRIGHT);
		window->drawChar(x + xx, y + bounds.getHeight() - 1, 'X', ColorHelper::PURPLE + ColorHelper::BRIGHT);
	}

	for (int yy = 0; yy < bounds.getHeight(); ++yy)
	{
		window->drawChar(x, y + yy, 'X', ColorHelper::PURPLE + ColorHelper::BRIGHT);
		window->drawChar(x + bounds.getWidth() - 1, y + yy, 'X', ColorHelper::PURPLE + ColorHelper::BRIGHT);
	}
	
}

/*virtual*/ void Player::update()
{
	Entity::update();
	if (shootDirection != MoveDirection::NONE)
	{
		if (weapon->canShoot() && ammo > 0)
		{
			AudioHelper::getAudioHelper()->play("shoot");
			std::vector<Bullet> bull = weapon->shoot(getPosition() + (getDimension() / 2.0f), shootDirection);
			weapon->resetTimer();
			bullets.insert(bullets.end(), bull.begin(), bull.end());
			--ammo;
		}

		shootDirection = MoveDirection::NONE;
		
	}
}

int Player::getAmmo()
{
	return ammo;
}

void Player::askToShoot(MoveDirection dir)
{
	if (dir == MoveDirection::DOWN)
	{
		if (shootDirection == MoveDirection::LEFT)
			shootDirection = MoveDirection::DOWN_LEFT;
		else if (shootDirection == MoveDirection::RIGHT)
			shootDirection = MoveDirection::DOWN_RIGHT;
		else
			shootDirection = dir;
	}
	else if (dir == MoveDirection::UP)
	{
		if (shootDirection == MoveDirection::LEFT)
			shootDirection = MoveDirection::UP_LEFT;
		else if (shootDirection == MoveDirection::RIGHT)
			shootDirection = MoveDirection::UP_RIGHT;
		else
			shootDirection = dir;
	}
	else if (dir == MoveDirection::LEFT)
	{
		if (shootDirection == MoveDirection::UP)
			shootDirection = MoveDirection::UP_LEFT;
		else if (shootDirection == MoveDirection::DOWN)
			shootDirection = MoveDirection::DOWN_LEFT;
		else
			shootDirection = dir;
	}
	else if (dir == MoveDirection::RIGHT)
	{
		if (shootDirection == MoveDirection::UP)
			shootDirection = MoveDirection::UP_RIGHT;
		else if (shootDirection == MoveDirection::DOWN)
			shootDirection = MoveDirection::DOWN_RIGHT;
		else
			shootDirection = dir;
	}
}

void Player::setWeapon(Weapon* wea)
{
	weapon = wea;
}

Weapon* Player::getWeapon()
{
	return weapon;
}

std::vector<Bullet> Player::getBullets()
{
	return bullets;
}

void Player::clearBullets()
{
	bullets.clear();
}

void Player::addAmmo(int ammunition)
{
	ammo += ammunition;
	if (ammo > 12)
		ammo = 12;
}

void Player::addLife(int life)
{
	lifePoint += life;
	if (lifePoint > 10)
		lifePoint = 10;
}

void Player::addScore(int scores) 
{
	score += scores;
	if (score < 0)
		score = 0;
}

int Player::getScore()
{
	return score;
}