#include "..\Header\Bullet.h"

Bullet::Bullet(Vector2 pos, int addH, int addV)
	: Entity(pos, Vector2(5,5))
{
	addHoriz = addH;					//entity
	addVerti = addV;					//entity
	setupRealPos();						//entity

	speed = speedBullet;
}


Bullet::~Bullet()
{

}

///
/// affiche le bullet (et cache l'ancien)
///
void Bullet::display(Window *win)
{
	displayBullet(win, true);	//enlève l'ancien en mettant du blanc
	displayBullet(win);		//affiche la nouvelle positions

	oldPos = pos;
}

///
/// affiche le sprite de l'objet
///
void Bullet::displayBullet(Window *win, bool erase)
{
	char c = (!erase) ? carac : ' ';
	int x = (!erase) ? pos.x : oldPos.x;
	int y = (!erase) ? pos.y : oldPos.y;

	win->changePixel(x + dimension.x /2, y + dimension.y / 2, c);
	win->changePixel(x + dimension.x / 2 - 1 , y + dimension.y / 2, c);
	win->changePixel(x + dimension.x / 2 + 1, y + dimension.y / 2, c);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 - 1, c);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 + 1, c);

	win->changePixel(x + dimension.x / 2  - 2, y + dimension.y / 2, c);
	win->changePixel(x + dimension.x / 2  + 2, y + dimension.y / 2, c);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 - 2, c);
	win->changePixel(x + dimension.x / 2, y + dimension.y / 2 + 2, c);

	win->changePixel(x + dimension.x / 2  + 1, y + dimension.y / 2 + 1, c);
	win->changePixel(x + dimension.x / 2  + 1, y + dimension.y / 2 - 1, c);
	win->changePixel(x + dimension.x / 2  - 1, y + dimension.y / 2 + 1, c);
	win->changePixel(x + dimension.x / 2  - 1, y + dimension.y / 2 - 1, c);

}

///
/// déplace le bullet
///
void Bullet::update()
{
	pos.x += addHoriz * speed;
	pos.y += addVerti * speed;

	setupRealPos();
}