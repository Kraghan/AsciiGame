#include "../Headers/AlphabetDrawer.h"

void AlphabetDrawer::drawPixel(unsigned int x, unsigned int y, unsigned int fontSize, char caractere, int color)
{
	for (unsigned int i = 0; i < fontSize; ++i)
	{
		for (unsigned int j = 0; j < fontSize; ++j)
		{
			Window::getInstance()->drawChar(x + i, y + j, caractere, color);
		}
	}
}

void AlphabetDrawer::drawA(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);

}

void AlphabetDrawer::drawB(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawC(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawD(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawE(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawF(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawG(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawH(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawI(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawJ(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawK(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawL(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawM(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawN(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawO(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawP(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawQ(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawR(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawS(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawT(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawU(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawV(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	
	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawW(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawX(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawY(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::drawZ(Vector2ui pos , unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y,fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize,fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 3 * fontSize,fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize,fontSize, caractere, color);
}

void AlphabetDrawer::draw0(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw1(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 1 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw2(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x , pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw3(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw4(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw5(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw6(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw7(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw8(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

void AlphabetDrawer::draw9(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawWord(Vector2ui pos, std::string word, unsigned int fontSize, char caractere, int color)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	int offset = 0;
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
	{
		switch (*it)
		{
		case 'a':
			drawA(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'b':
			drawB(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'c':
			drawC(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'd':
			drawD(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'e':
			drawE(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'f':
			drawF(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'g':
			drawG(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'h':
			drawH(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'i':
			drawI(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 2 * fontSize;
			break;
		case 'j':
			drawJ(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'k':
			drawK(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'l':
			drawL(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'm':
			drawM(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'n':
			drawN(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'o':
			drawO(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'p':
			drawP(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'q':
			drawQ(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'r':
			drawR(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 's':
			drawS(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 't':
			drawT(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'u':
			drawU(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'v':
			drawV(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'w':
			drawW(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case 'x':
			drawX(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case 'y':
			drawY(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 4 * fontSize;
			break;
		case 'z':
			drawZ(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '0':
			draw0(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '1':
			draw1(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '2':
			draw2(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '3':
			draw3(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '4':
			draw4(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '5':
			draw5(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '6':
			draw6(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '7':
			draw7(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '8':
			draw8(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '9':
			draw9(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 5 * fontSize;
			break;
		case '+':
			drawPlus(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case '-':
			drawMinus(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 6 * fontSize;
			break;
		case ':':
			drawColumn(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 3 * fontSize;
			break;
		case '.':
			drawDot(Vector2ui(pos.x + offset, pos.y), fontSize, caractere, color);
			offset += 3 * fontSize;
			break;
		default:
			offset += 5 * fontSize;
			break;
		}
	}
}

/*static*/ void AlphabetDrawer::drawAmmo(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, 0x0E);
	
	drawPixel(pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, 6);

	for (unsigned int i = 0; i < 7; ++i)
	{
		drawPixel(pos.x, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(pos.x + 1 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(pos.x + 2 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(pos.x + 3 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 0x0E);
		drawPixel(pos.x + 4 * fontSize, pos.y + (2 + i) * fontSize, fontSize, caractere, 6);
	}

	drawPixel(pos.x + 1 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 2 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 3 * fontSize, pos.y + 9 * fontSize, fontSize, caractere, 0x0E);

	drawPixel(pos.x, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 1 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 2 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 3 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 0x0E);
	drawPixel(pos.x + 4 * fontSize, pos.y + 10 * fontSize, fontSize, caractere, 6);

}

/*static*/ void AlphabetDrawer::drawHeartContour(unsigned int x, unsigned int y, unsigned int fontSize, char caractere)
{
	drawPixel(x + 2 * fontSize, y, fontSize, caractere, 8);
	drawPixel(x + 3 * fontSize, y, fontSize, caractere, 8);
	drawPixel(x + 4 * fontSize, y, fontSize, caractere, 8);
	drawPixel(x + 8 * fontSize, y, fontSize, caractere, 8);
	drawPixel(x + 9 * fontSize, y, fontSize, caractere, 8);
	drawPixel(x + 10 * fontSize, y, fontSize, caractere, 8);

	drawPixel(x + fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(x + 5 * fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(x + 7 * fontSize, y + fontSize, fontSize, caractere, 8);
	drawPixel(x + 11 * fontSize, y + fontSize, fontSize, caractere, 8);

	drawPixel(x, y + 2 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 6 * fontSize, y + 2 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 12 * fontSize, y + 2 * fontSize, fontSize, caractere, 8);

	drawPixel(x, y + 3 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 12 * fontSize, y + 3 * fontSize, fontSize, caractere, 8);

	drawPixel(x, y + 4 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 12 * fontSize, y + 4 * fontSize, fontSize, caractere, 8);

	drawPixel(x, y + 5 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 12 * fontSize, y + 5 * fontSize, fontSize, caractere, 8);

	drawPixel(x + fontSize, y + 6 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 11 * fontSize, y + 6 * fontSize, fontSize, caractere, 8);

	drawPixel(x + 2 * fontSize, y + 7 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 10 * fontSize, y + 7 * fontSize, fontSize, caractere, 8);

	drawPixel(x + 3 * fontSize, y + 8 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 9 * fontSize, y + 8 * fontSize, fontSize, caractere, 8);

	drawPixel(x + 4 * fontSize, y + 9 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 8 * fontSize, y + 9 * fontSize, fontSize, caractere, 8);

	drawPixel(x + 5 * fontSize, y + 10 * fontSize, fontSize, caractere, 8);
	drawPixel(x + 7 * fontSize, y + 10 * fontSize, fontSize, caractere, 8);

	drawPixel(x + 6 * fontSize, y + 11 * fontSize, fontSize, caractere, 8);
}

/*static*/ void AlphabetDrawer::drawHeart(Vector2ui pos, unsigned int fontSize, char caractere, bool empty)
{
	// Draw contour
	drawHeartContour(pos.x, pos.y, fontSize, caractere);
	
	// Draw inside
	if (!empty)
	{
		int color = 0x0C;
		drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 4 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 8 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 9 * fontSize, pos.y + fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 10 * fontSize, pos.y + fontSize, fontSize, caractere, color);

		drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 5 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 7 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 8 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 9 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 10 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
		drawPixel(pos.x + 11 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 3; ++j)
				if (i == 10)
					drawPixel(pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, 0x04);
				else
					drawPixel(pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, color);
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 9 - (2 * i); ++j)
			{
				if (j == (9 - (2 * i) - 1))
					drawPixel(pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, 0x04);
				else
					drawPixel(pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, color);
			}
		}

		drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
		drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
		drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, 15);
		drawPixel(pos.x + 2 * fontSize, pos.y + 5 * fontSize, fontSize, caractere, 15);

		drawPixel(pos.x + 10 * fontSize, pos.y + fontSize, fontSize, caractere, 0x04);
		drawPixel(pos.x + 11 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 0x04);
	}
}

/*static*/ void AlphabetDrawer::drawHalfHeart(Vector2ui pos, unsigned int fontSize, char caractere)
{
	drawHeartContour(pos.x, pos.y, fontSize, caractere);

	int color = 0x0C;
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 5 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
			if ((i == 5 && j % 2 == 0) || i != 5)
				drawPixel(pos.x + (1 + i) * fontSize, pos.y + (3 + j) * fontSize, fontSize, caractere, color);
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			if(2 + i + j != 6 || (2 + i + j == 6 && i % 2 == 1))
				drawPixel(pos.x + (2 + i + j) * fontSize, pos.y + (6 + i) * fontSize, fontSize, caractere, color);
		}
	}

	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, 15);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, 15);
	drawPixel(pos.x + 2 * fontSize, pos.y + 5 * fontSize, fontSize, caractere, 15);
}

/*static*/ void AlphabetDrawer::drawColumn(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y , fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 3 *fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize , fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawDot(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 4 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawPlus(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawMinus(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
}


/*static*/ void AlphabetDrawer::drawUp(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawDown(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}

/*static*/ void AlphabetDrawer::drawLeft(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);

}

/*static*/ void AlphabetDrawer::drawRight(Vector2ui pos, unsigned int fontSize, char caractere, int color)
{
	drawPixel(pos.x + 2 * fontSize, pos.y, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + fontSize, fontSize, caractere, color);

	drawPixel(pos.x, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 1 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 2 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 4 * fontSize, pos.y + 2 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);
	drawPixel(pos.x + 3 * fontSize, pos.y + 3 * fontSize, fontSize, caractere, color);

	drawPixel(pos.x + 2 * fontSize, pos.y + 4 * fontSize, fontSize, caractere, color);
}