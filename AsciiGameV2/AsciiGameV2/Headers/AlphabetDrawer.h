#pragma once
#include "Window.h"
#include "Vector2.h"
#include <algorithm>

class AlphabetDrawer
{
	static void drawPixel(unsigned int x, unsigned int y, unsigned int fontSize, char caractere, int color);
	static void drawHeartContour(unsigned int x, unsigned int y, unsigned int fontSize, char caractere);

public : 
	static void drawWord(Vector2ui pos, std::string word, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawAmmo(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawHeart(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', bool empty = false);
	static void drawHalfHeart(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X');
	static void drawA(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawB(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawC(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawD(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawE(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawF(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawG(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawH(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawI(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawJ(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawK(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawL(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawM(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawN(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawO(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawP(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawQ(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawR(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawS(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawT(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawU(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawV(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawW(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawX(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawY(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawZ(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw0(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw1(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw2(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw3(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw4(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw5(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw6(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw7(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw8(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw9(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawDot(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawColumn(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawPlus(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawMinus(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawUp(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawDown(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawLeft(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawRight(Vector2ui pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
};
