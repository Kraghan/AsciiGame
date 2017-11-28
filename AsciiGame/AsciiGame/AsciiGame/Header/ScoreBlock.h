#pragma once
#include "Block.h"

class ScoreBlock : Block
{
public:
	// Default constructor
	explicit ScoreBlock(void)
		: Block(Vector2(), 'S', false, true)
	{
		setName("ScoreBlock");
	}

	// Constructor with initial position
	explicit ScoreBlock(Vector2 pos)
		: Block(pos, 'S', false, true)
	{
		setName("ScoreBlock");
	}

	// Called when player collide with the block
	virtual void collect(Player* player);

	// Called once per frame, used to display block
	virtual void display(Window* window);
};