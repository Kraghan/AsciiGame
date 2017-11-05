#pragma once
#include "Block.h"

class AmmoBlock : Block
{
public:
	explicit AmmoBlock(void)
		: Block(Vector2(), 'A', false, true)
	{

	}

	explicit AmmoBlock(Vector2 pos)
		: Block(pos, 'A', false, true)
	{

	}

	virtual void collect(Player* player);
	virtual void display(Window* window);
};