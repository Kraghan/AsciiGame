#pragma once

#include "Vector2.h"
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

	Vector2 pos;
	bool tryedToMove = false;
	int speedPlayer = 1;
	char carac = 'P';
	int color = 5;

	int addHoriz = 0;
	int addVerti = 0;

private:
	MOVE_TYPE moveType = M_NOTHING;				//le type de mouvement à faire dans l'update !

public:
	Player();
	Player(Vector2 pos);
	~Player();

	void tryToMove(MOVE_TYPE moveType);					//déplace le joueur
	void stopMove(MOVE_TYPE moveType);								//stop le joueur
													//dis "BOUGER a droite"
	void update(); //selon move, change pos;

private:
	void changeHorizVerti(bool stop);

};

