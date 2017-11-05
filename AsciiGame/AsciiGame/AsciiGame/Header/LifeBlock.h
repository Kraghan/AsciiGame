#pragma once
#include "Block.h"

class LifeBlock : public Block
{
public:
	explicit LifeBlock(void)
		: Block(Vector2(), 'H', false, true)
	{

	}

	explicit LifeBlock(Vector2 pos)
		: Block(pos, 'H', false, true)
	{

	}

	virtual void collect(Player* player);
	virtual void display(Window* window);
};