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

/*static*/ void AlphabetDrawer::drawWord(Window* window, Vector2 pos, std::string word, unsigned int fontSize, char caractere, int color)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	int offset = 0;
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
	{
		switch (*it)
		{
		case 'a':
			drawA(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'b':
			drawB(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'c':
			drawC(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'd':
			drawD(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'e':
			drawE(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'f':
			drawF(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'g':
			drawG(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'h':
			drawH(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'i':
			drawI(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 2 * fontSize;
			break;
		case 'j':
			drawJ(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'k':
			drawK(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'l':
			drawL(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'm':
			drawM(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'n':
			drawN(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'o':
			drawO(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'p':
			drawP(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'q':
			drawQ(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'r':
			drawR(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 's':
			drawS(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 't':
			drawT(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'u':
			drawU(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'v':
			drawV(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'w':
			drawW(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case 'x':
			drawX(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'y':
			drawY(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'z':
			drawZ(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '0':
			draw0(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '1':
			draw1(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '2':
			draw2(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '3':
			draw3(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '4':
			draw4(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '5':
			draw5(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '6':
			draw6(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '7':
			draw7(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '8':
			draw8(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '9':
			draw9(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '+':
			drawPlus(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case '-':
			drawMinus(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case ':':
			drawColumn(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 3 * fontSize;
			break;
		case '.':
			drawDot(window, Vector2(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 3 * fontSize;
			break;
		default:
			offset += 5 * fontSize;
			break;
		}
	}
}

/*static*/ void AlphabetDrawer::drawAmmo(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, 0x0E);
	
	drawPixel(window, pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, 6);

	for (unsigned int i = 0; i < 7; ++i)
	{
		drawPixel(window, pos.x, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(window, pos.x + 1 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(window, pos.x + 2 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(window, pos.x + 3 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(window, pos.x + 4 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 6);
	}

	drawPixel(window, pos.x + 1 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);

	drawPixel(window, pos.x, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 1 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 6);

}

/*static*/ void AlphabetDrawer::drawHeartContour(Window* window, unsigned int x, unsigned int y, unsigned int fontSize, char caractere)
{
	drawPixel(window, x + 2 * fontSize, y, fontSize, caractere, 8);
	drawPixel(window, x + 3 * fontSize, y, fontSize, caractere, 8);
	drawPixel(window, x + 4 * fontSize, y, fontSize, caractere, 8);
	drawPixel(window, x + 8 * fontSize, y, fontSize, caractere, 8);
	drawPixel(window, x + 9 * fontSize, y, fontSize, caractere, 8);
	drawPixel(window, x + 10 * fontSize, y, fontSize, caractere, 8);

	drawPixel(window, x + fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 5 * fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 7 * fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 11 * fontSize, y + fontSize, fontSize, caractere, 8);

	drawPixel(window, x, y + 2 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 6 * fontSize, y + 2 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 12 * fontSize, y + 2 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x, y + 3 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 12 * fontSize, y + 3 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x, y + 4 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 12 * fontSize, y + 4 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x, y + 5 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 12 * fontSize, y + 5 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + fontSize, y + 6 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 11 * fontSize, y + 6 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + 2 * fontSize, y + 7 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 10 * fontSize, y + 7 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + 3 * fontSize, y + 8 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 9 * fontSize, y + 8 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + 4 * fontSize, y + 9 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 8 * fontSize, y + 9 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + 5 * fontSize, y + 10 * fontSize, fontSize, caractere, 8);
	drawPixel(window, x + 7 * fontSize, y + 10 * fontSize, fontSize, caractere, 8);

	drawPixel(window, x + 6 * fontSize, y + 11 * fontSize, fontSize, caractere, 8);
}

/*static*/ void AlphabetDrawer::drawHeart(Window* window, Vector2 pos, unsigned int fontSize, char caractere, bool empty)
{
	// Draw contour
	drawHeartContour(window, pos.x, pos.y, fontSize, caractere);
	
	// Draw inside
	if (!empty)
	{
		int color = 0x0C;
		drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 4 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 8 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 9 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 10 * fontSize, pos.y + fontSize, fontSize, caractere, color);

		drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 5 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 7 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 8 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 9 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 10 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(window, pos.x + 11 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 3; ++j)
				if (i == 10)
					drawPixel(window, pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, 0x04);
				else
					drawPixel(window, pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, color);
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 9 - (2 * i); ++j)
			{
				if (j == (9 - (2 * i) - 1))
					drawPixel(window, pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, 0x04);
				else
					drawPixel(window, pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, color);
			}
		}

		drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
		drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
		drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, 15);
		drawPixel(window, pos.x + 2 * fontSize, pos.y + 5 * fontSize, fontSize, caractere, 15);

		drawPixel(window, pos.x + 10 * fontSize, pos.y + fontSize, fontSize, caractere, 0x04);
		drawPixel(window, pos.x + 11 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 0x04);
	}
}

/*static*/ void AlphabetDrawer::drawHalfHeart(Window* window, Vector2 pos, unsigned int fontSize, char caractere)
{
	drawHeartContour(window, pos.x, pos.y, fontSize, caractere);

	int color = 0x0C;
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 5 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
			if ((i == 5 && j % 2 == 0) || i != 5)
				drawPixel(window, pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, color);
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			if(2 + i + j != 6 || (2 + i + j == 6 && i % 2 == 1))
				drawPixel(window, pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, color);
		}
	}

	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, 15);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 5 * fontSize, fontSize, caractere, 15);
}

/*static*/ void AlphabetDrawer::drawColumn(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y , fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 3 *fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize , fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawDot(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawPlus(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(window, pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawMinus(Window* window, Vector2 pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(window, pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(window, pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
}