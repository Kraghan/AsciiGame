#pragma once
#include "Block.h"

class ScoreBlock : Block
{
public:
	explicit ScoreBlock(void)
		: Block(Vector2(), 'S', false, true)
	{

	}

	explicit ScoreBlock(Vector2 pos)
		: Block(pos, 'S', false, true)
	{

	}

	virtual void collect(Player* player);
	virtual void display(Window* window);
};