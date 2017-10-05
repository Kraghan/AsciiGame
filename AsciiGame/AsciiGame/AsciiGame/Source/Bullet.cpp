#include "..\Header\Bullet.h"

Bullet::Bullet(Vector2 pos, int addH, int addV)
	: pos(pos), addHoriz(addH), addVerti(addV)
{
	oldPos = pos;
	displaySize.x = 5;
	displaySize.y = 5;
	setupRealPos();
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
	win->changePixel(x - 1, y - 1, c);
	win->changePixel(x - 1, y + 1, c);
	win->changePixel(x + 1, y - 1, c);
	win->changePixel(x + 2, y + 1, c);
}

///
/// actualise la position pour les colisions
///
void Bullet::setupRealPos()
{
	displayPos.x = pos.x - (displaySize.x / 2);
	displayPos.y = pos.y - (displaySize.y / 2);
}

///
/// déplace le bullet
///
void Bullet::update()
{
	pos.x += addHoriz * speedBullet;
	pos.y += addVerti * speedBullet;

	setupRealPos();
}