#pragma once

#include "Entity.h"
#include "Window.h"
#include "Bullet.h"
#include "Timer.h"
#include "Weapon.h"
#include <iostream>
#include "AudioHelper.h"

class Player : public Entity
{
public:
	unsigned int MAX_LIFE_POINT = 10;
	unsigned int MAX_AMMO = 12;
	unsigned int lifePoint;
	unsigned int ammunition;
	unsigned int score;

	Timer timer;
	bool tryedToMove = true;			//ici à vrai pour afficher le player au début

	char carac = 'P';
	int color = 15;
	int speedPlayer = 1;

	bool bulletToShoot = false;			//le joueur doit-il tirer un bullet ?
	int addShootHoriz = 0;
	int addShootVerti = 0;

	Weapon* weapon;

public:
	Player();
	Player(Vector2 pos);
	~Player();

	void tryToMove(MOVE_TYPE moveType);					//déplace le joueur
	void stopMove(MOVE_TYPE moveType);					//stop le joueur
	void tryToShoot(MOVE_TYPE moveType);

	void display(Window *win);
	std::vector<Bullet> shoot();
	void update(); //selon move, change pos;

	bool canShoot();
	void addLifePoint(unsigned int health);
	void addAmmo(unsigned int ammo);
	void setWeapon(Weapon* weap);
	Weapon* getWeapon();

private:
	void changeHorizVerti(bool stop, bool bullet);
};

