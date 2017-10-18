#pragma once

#include "Entity.h"
#include "Window.h"
#include "Bullet.h"
#include "Timer.h"
#include <iostream>

class Player : public Entity
{
public:
	unsigned int lifePoint;
	Timer timer;
	float timeReload = 0.3f;
	bool tryedToMove = true;			//ici à vrai pour afficher le player au début

	char carac = 'P';
	int color = 15;
	int speedPlayer = 1;

	bool bulletToShoot = false;			//le joueur doit-il tirrer un bullet ?
	int addShootHoriz = 0;
	int addShootVerti = 0;

public:
	Player();
	Player(Vector2 pos);
	~Player();

	void tryToMove(MOVE_TYPE moveType);					//déplace le joueur
	void stopMove(MOVE_TYPE moveType);								//stop le joueur
	void tryToShoot(MOVE_TYPE moveType);

	void display(Window *win);
	Bullet shoot();
	void update(); //selon move, change pos;

private:
	void changeHorizVerti(bool stop, bool bullet);
	void displaySpaceInvader(Window *win, bool erase = false);	
};

