#include "..\Header\Bullet.h"

Bullet::Bullet(Vector2 pos, int addH, int addV)
	: Entity(pos, Vector2(5,5))
{
	addHoriz = addH;					//entity
	addVerti = addV;					//entity

	speed = speedBullet;
	delay = 0;
}


Bullet::~Bullet()
{

}

///
/// affiche le bullet (et cache l'ancien)
///
void Bullet::display(Window *win)
{
	Vector2 dimension = bounds.dimension;
	unsigned int x = bounds.position.x;
	unsigned int y = bounds.position.y;

	win->changePixel(x + dimension.x / 2, y + dimension.y / 2, carac, 0x07);
	win->changePixel(x + dimension.x / 2 - 1, y + dimension.y / 2, carac, color);
	win->changePixel(x + dimension.x / 2 + 1, y + dimension.y / 2, carac, color);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 - 1, carac, 0x07);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 + 1, carac, 0x07);

	win->changePixel(x + dimension.x / 2 - 2, y + dimension.y / 2, carac, color);
	win->changePixel(x + dimension.x / 2 + 2, y + dimension.y / 2, carac, color);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 - 2, carac, color);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 + 2, carac, color);

	win->changePixel(x + dimension.x / 2 + 1, y + dimension.y / 2 + 1, carac, color);
	win->changePixel(x + dimension.x / 2 + 1, y + dimension.y / 2 - 1, carac, color);
	win->changePixel(x + dimension.x / 2 - 1, y + dimension.y / 2 + 1, carac, color);
	win->changePixel(x + dimension.x / 2 - 1, y + dimension.y / 2 - 1, carac, color);
	oldPos = bounds.position;
}


///
/// déplace le bullet
///
void Bullet::update()
{
	if (delay != 0)
		delay--;
	
	if (delay == 0)
	{
		bounds.position.x += addHoriz * speed;
		bounds.position.y += addVerti * speed;
	}
}

void Bullet::setDelay(int del)
{
	delay = del;
}