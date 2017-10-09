#include "../Header/AlphabetDrawer.h"

void AlphabetDrawer::drawPixel(Window* window, unsigned int x, unsigned int y, unsigned int fontSize, char caractere, int color)
{
	for (unsigned int i = 0; i < fontSize; ++i)
	{
		for (unsigned int j = 0; j < fontSize; ++j)
		{
			window->changePixel(x + i, y + j, caractere, color);
		}
	}
}

void AlphabetDrawer::drawA(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);

}

void AlphabetDrawer::drawB(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawC(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawD(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawE(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawF(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawG(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawH(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawI(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawJ(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawK(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawL(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawM(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawN(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawO(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawP(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawQ(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawR(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawS(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawT(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawU(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawV(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	
	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawW(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawX(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawY(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawZ(Window* window, Vector2 pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::draw0(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw1(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + 1 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw2(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x , pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw3(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw4(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw5(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw6(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw7(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw8(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw9(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}