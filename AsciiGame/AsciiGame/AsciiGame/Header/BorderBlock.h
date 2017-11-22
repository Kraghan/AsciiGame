#pragma once
#include "Block.h"

class BorderBlock : Block
{
public :
	// Default constructor
	explicit BorderBlock(void)
		: Block(Vector2(), 'N', true, false, true)
	{
		
	}

	// Constructor with initial position
	explicit BorderBlock(Vector2 pos)
		: Block(pos, 'N', true, false, true)
	{
		
	}
};