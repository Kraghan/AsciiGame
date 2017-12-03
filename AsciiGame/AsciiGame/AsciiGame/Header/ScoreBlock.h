#pragma once
#include "Block.h"

class ScoreBlock : Block
{
public:
	// Number of score block in the game
	static unsigned int numberOfBlock;
	static unsigned int level;

	// Default constructor
	explicit ScoreBlock(void)
		: Block(Vector2(), 'S', false, true)
	{
		setName("ScoreBlock");
		ScoreBlock::numberOfBlock++;
	}

	// Constructor with initial position
	explicit ScoreBlock(Vector2 pos)
		: Block(pos, 'S', false, true)
	{
		setName("ScoreBlock");
		ScoreBlock::numberOfBlock++;
	}

	// Called when player collide with the block
	virtual void collect(Player* player);

	// Called once per frame, used to display block
	virtual void display(Window* window);
};