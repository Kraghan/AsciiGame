#include "..\Header\IA.h"

IA::IA(Vector2 pos)
	: Entity(pos, Vector2(dimensionBulletX, dimensionBulletY))
{

	speed = speedIA;

	while (addHoriz == 0 && addVerti == 0)
	{
		int min = -1;
		int max = 1;
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
	int x = bounds.position.x;
	int y = bounds.position.y;

	win->changePixel(x, y, carac, color);

	win->changePixel(x - 1, y, carac, color);
	win->changePixel(x + 1, y, carac, color);
	win->changePixel(x, y - 1, carac, color);
	win->changePixel(x, y + 1, carac, color);

	win->changePixel(x - 2, y, carac, color);
	win->changePixel(x + 2, y, carac, color);
	win->changePixel(x, y - 2, carac, color);
	win->changePixel(x, y + 2, carac, color);

	win->changePixel(x + 2, y + 1, carac, color);
	win->changePixel(x + 2, y - 1, carac, color);

	win->changePixel(x - 2, y + 1, carac, color);
	win->changePixel(x - 2, y - 1, carac, color);

	win->changePixel(x + 1, y + 1, carac, color);
	win->changePixel(x - 1, y + 1, carac, color);

	win->changePixel(x + 2, y + 2, carac, color);
	win->changePixel(x - 2, y + 2, carac, color);

	win->changePixel(x + 2, y - 2, carac, color);
	win->changePixel(x - 2, y - 2, carac, color);

	win->changePixel(x + 1, y + 2, carac, color);
	win->changePixel(x - 1, y + 2, carac, color);

	win->changePixel(x, y + 3, carac, color);
	win->changePixel(x + 1, y + 3, carac, color);
	win->changePixel(x - 1, y + 3, carac, color);

	oldPos = bounds.position;
}

///
/// affiche le sprite de l'objet
///
void IA::displayIA(Window *win, bool erase)
{
	char c = (!erase) ? carac : ' ';
	

}

///
/// déplace le bullet
///
void IA::update()
{
	bounds.position.x += addHoriz * speed;
	bounds.position.y += addVerti * speed;
}