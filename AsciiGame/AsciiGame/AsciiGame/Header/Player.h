#pragma once

#include "Vector2.h"
#include "Window.h"
#include "Bullet.h"
#include "Timer.h"
#include <iostream>

class Player
{
public:
	enum MOVE_TYPE
	{
		M_NOTHING = -1,	//rien, etat initial
		M_UP = 0,
		M_DOWN = 1,
		M_RIGHT = 2,
		M_LEFT = 3,
		//diag
		M_UP_RIGHT = 4,
		M_UP_LEFT = 5,
		M_DOWN_RIGHT = 6,
		M_DOWN_LEFT = 7
	};

	Vector2 displayPos;
	Vector2 displaySize;

	Timer timer;
	float timeReload = 0.3f;

	//float timeOfFirstShoot = 0;

	Vector2 oldPos;
	Vector2 pos;
	bool tryedToMove = true;			//ici à vrai pour afficher le player au début
	int speedPlayer = 1;
	char carac = 'P';
	int color = 15;

	int addHoriz = 0;
	int addVerti = 0;

	bool bulletToShoot = false;			//le joueur doit-il tirrer un bullet ?
	int addShootHoriz = 0;
	int addShootVerti = 0;

private:
	MOVE_TYPE moveType = M_NOTHING;				//le type de mouvement à faire dans l'update !

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
	void setupRealPos();	//actualise la position pour les colisions
};

