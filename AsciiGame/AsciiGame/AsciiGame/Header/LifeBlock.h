#pragma once
#include "Block.h"

class LifeBlock : public Block
{
public:
	// Default constructor
	explicit LifeBlock(void)
		: Block(Vector2(), 'H', false, true)
	{

	}

	// Constructor with initial position
	explicit LifeBlock(Vector2 pos)
		: Block(pos, 'H', false, true)
	{

	}

	// Called when player collide with the block
	virtual void collect(Player* player);

	// Called once per frame, used to display block
	virtual void display(Window* window);
};