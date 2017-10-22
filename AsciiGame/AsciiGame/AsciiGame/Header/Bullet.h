#pragma once

#include "Entity.h"
#include "Window.h"

class Bullet : public Entity
{
public:
	char carac = '*';
	int color = 7;
	int speedBullet = 2;

public:
	Bullet(Vector2 pos, int addH, int addV);
	~Bullet();

	void display(Window *win);
	void update(); //selon move, change pos;

private:
};

