#pragma once
#include "Window.h"
#include "Vector2.h"
#include <algorithm>

class AlphabetDrawer
{
	static void drawPixel(Window* window, unsigned int x, unsigned int y, unsigned int fontSize, char caractere, int color);
	static void drawHeartContour(Window* window, unsigned int x, unsigned int y, unsigned int fontSize, char caractere);

public : 
	static void drawWord(Window* window, Vector2 pos, std::string word, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawAmmo(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawHeart(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', bool empty = false);
	static void drawHalfHeart(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X');
	static void drawA(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawB(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawC(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawD(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawE(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawF(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawG(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawH(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawI(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawJ(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawK(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawL(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawM(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawN(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawO(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawP(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawQ(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawR(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawS(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawT(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawU(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawV(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawW(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawX(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawY(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawZ(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw0(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw1(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw2(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw3(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw4(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw5(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw6(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw7(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw8(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void draw9(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawDot(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawColumn(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawPlus(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
	static void drawMinus(Window* window, Vector2 pos, unsigned int fontSize = 1, char caractere = 'X', int color = 15);
};
