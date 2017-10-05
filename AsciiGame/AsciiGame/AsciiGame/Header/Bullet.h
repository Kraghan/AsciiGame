#pragma once

#include "Vector2.h"
#include "Window.h"

class Bullet
{
public:
	Vector2 displayPos;
	Vector2 displaySize;

	Vector2 oldPos;
	Vector2 pos;

	int addHoriz = 0;
	int addVerti = 0;
	int speedBullet = 1;

	char carac = '*';
	int color = 7;

public:
	Bullet(Vector2 pos, int addH, int addV);
	~Bullet();

	void display(Window *win);
	void update(); //selon move, change pos;

private:
	void displayBullet(Window *win, bool erase = false);
	void setupRealPos();	//actualise la position pour les colisions
};

