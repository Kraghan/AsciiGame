#pragma once
#include "Block.h"

class AmmoBlock : Block
{
public:
	// Default constructor
	explicit AmmoBlock(void)
		: Block(Vector2(), 'A', false, true)
	{

	}

	// Constructor with initial position
	explicit AmmoBlock(Vector2 pos)
		: Block(pos, 'A', false, true)
	{

	}

	// Called when player collide with the block
	virtual void collect(Player* player);
	
	// Called once per frame, used to display block
	virtual void display(Window* window);
};