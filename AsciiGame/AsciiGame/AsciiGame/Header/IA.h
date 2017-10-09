#pragma once

#include "Entity.h"
#include "Window.h"

class IA : Entity
{
public:
	char carac = 'I';
	int color = 9;
	int dimensionBulletX = 7;
	int dimensionBulletY = 7;
	int speedIA = 1;

	IA(Vector2 pos);
	~IA();

	void display(Window *win);
	void update(); //selon move, change pos;

private:
	void displayIA(Window *win, bool erase = false);					//déplace l'IA
};

