#include "..\Header\Bullet.h"

Bullet::Bullet(Vector2 pos, int addH, int addV)
	: Entity(pos)
{
	addHoriz = addH;					//entity
	addVerti = addV;					//entity
	dimension.x = dimensionBulletX;		//entity
	dimension.y = dimensionBulletY;		//entity
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

	win->changePixel(x, y, c);
	win->changePixel(x - 1, y, c);
	win->changePixel(x + 1, y, c);
	win->changePixel(x, y - 1, c);
	win->changePixel(x, y + 1, c);

	win->changePixel(x - 2, y, c);
	win->changePixel(x + 2, y, c);
	win->changePixel(x, y - 2, c);
	win->changePixel(x, y + 2, c);

	win->changePixel(x + 1, y + 1, c);
	win->changePixel(x + 1, y - 1, c);
	win->changePixel(x - 1, y + 1, c);
	win->changePixel(x - 1, y - 1, c);

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