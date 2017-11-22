#pragma once
#include "Block.h"

class NormalBlock : public Block
{
public:
	// Default constructor
	explicit NormalBlock(void)
		: Block(Vector2(), 'X')
	{

	}

	// Constructor with initial position
	explicit NormalBlock(Vector2 pos)
		: Block(pos, 'X')
	{

	}
};