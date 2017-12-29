#pragma once
#include "Entity.h"
#include "Weapon.h"
#include "BombThrower.h"
#include "Laser.h"
#include "Shotgun.h"
#include "AudioHelper.h"

class Player : public Entity
{
private : 
	int ammo;
	int score;
	MoveDirection shootDirection;
	Weapon* weapon;
	std::vector<Bullet> bullets;

public : 
	explicit Player();
	explicit Player(Vector2f position, Vector2f dimension);
	virtual ~Player();
	virtual void update();
	virtual void display(Vector2f cameraPosition);
	int getAmmo();
	void askToShoot(MoveDirection direction);
	void setWeapon(Weapon* weapon);
	Weapon* getWeapon();
	std::vector<Bullet> getBullets();
	void clearBullets();
	void addAmmo(int ammo);
	void addLife(int life);
	void addScore(int score);
	int getScore();
};