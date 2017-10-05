#include "../Header/AlphabetDrawer.h"

void AlphabetDrawer::drawA(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');

}

void AlphabetDrawer::drawB(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawC(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawD(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawE(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawF(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
}

void AlphabetDrawer::drawG(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawH(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawI(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
}

void AlphabetDrawer::drawJ(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawK(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 2, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawL(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawM(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 1, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawN(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 1, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawO(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawP(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
}

void AlphabetDrawer::drawQ(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 2, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawR(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 2, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawS(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');

	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawT(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');
	window->changePixel(pos.x, pos.y, 'X');

	window->changePixel(pos.x + 1, pos.y + 1, 'X');

	window->changePixel(pos.x + 1, pos.y + 2, 'X');

	window->changePixel(pos.x + 1, pos.y + 3, 'X');
	
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
}

void AlphabetDrawer::drawU(Window* window, Vector2 pos)
{
	window->changePixel(pos.x + 3, pos.y, 'X');
	window->changePixel(pos.x, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 3, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
}

void AlphabetDrawer::drawV(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	
	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 2, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
}

void AlphabetDrawer::drawW(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 4, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');
	window->changePixel(pos.x + 4, pos.y + 1, 'X');

	window->changePixel(pos.x, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');
	window->changePixel(pos.x + 4, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 2, pos.y + 3, 'X');
	window->changePixel(pos.x + 4, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawX(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x + 1, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');

	window->changePixel(pos.x + 1, pos.y + 2, 'X');
	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x, pos.y + 3, 'X');
	window->changePixel(pos.x + 3, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}

void AlphabetDrawer::drawY(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');

	window->changePixel(pos.x, pos.y + 1, 'X');
	window->changePixel(pos.x + 2, pos.y + 1, 'X');

	window->changePixel(pos.x + 1, pos.y + 2, 'X');

	window->changePixel(pos.x + 1, pos.y + 3, 'X');

	window->changePixel(pos.x + 1, pos.y + 4, 'X');
}

void AlphabetDrawer::drawZ(Window* window, Vector2 pos)
{
	window->changePixel(pos.x, pos.y, 'X');
	window->changePixel(pos.x + 1, pos.y, 'X');
	window->changePixel(pos.x + 2, pos.y, 'X');
	window->changePixel(pos.x + 3, pos.y, 'X');

	window->changePixel(pos.x + 3, pos.y + 1, 'X');

	window->changePixel(pos.x + 2, pos.y + 2, 'X');

	window->changePixel(pos.x + 1, pos.y + 3, 'X');

	window->changePixel(pos.x, pos.y + 4, 'X');
	window->changePixel(pos.x + 1, pos.y + 4, 'X');
	window->changePixel(pos.x + 2, pos.y + 4, 'X');
	window->changePixel(pos.x + 3, pos.y + 4, 'X');
}
