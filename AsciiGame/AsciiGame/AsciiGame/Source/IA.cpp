#include "..\Header\IA.h"

IA::IA(Vector2 pos)
	: Entity(pos, Vector2(dimensionBulletX, dimensionBulletY))
{
	setupRealPos();						//entity

	speed = speedIA;

	while (addHoriz == 0 && addVerti == 0)
	{
		int min = -2;
		int max = 2;
		addHoriz = (rand() % (max - min + 1) + min);
		addVerti = (rand() % (max - min + 1) + min);
	}
}



IA::~IA()
{

}

///
/// affiche le bullet (et cache l'ancien)
///
void IA::display(Window *win)
{
	displayIA(win, true);	//enlève l'ancien en mettant du blanc
	displayIA(win);		//affiche la nouvelle positions

	oldPos = pos;
}

///
/// affiche le sprite de l'objet
///
void IA::displayIA(Window *win, bool erase)
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

	win->changePixel(x + 2, y + 1, c);
	win->changePixel(x + 2, y - 1, c);

	win->changePixel(x - 2, y + 1, c);
	win->changePixel(x - 2, y - 1, c);

	win->changePixel(x + 1, y + 1, c);
	win->changePixel(x - 1, y + 1, c);

	win->changePixel(x + 2, y + 2, c);
	win->changePixel(x - 2, y + 2, c);

	win->changePixel(x + 2, y - 2, c);
	win->changePixel(x - 2, y - 2, c);

	win->changePixel(x + 1, y + 2, c);
	win->changePixel(x - 1, y + 2, c);

	win->changePixel(x, y + 3, c);
	win->changePixel(x + 1, y + 3, c);
	win->changePixel(x - 1, y + 3, c);

}

///
/// déplace le bullet
///
void IA::update()
{
	pos.x += addHoriz * speed;
	pos.y += addVerti * speed;

	setupRealPos();
}