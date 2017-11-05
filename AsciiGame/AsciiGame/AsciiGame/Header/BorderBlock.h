#pragma once
#include "Block.h"

class BorderBlock : Block
{
public :
	explicit BorderBlock(void)
		: Block(Vector2(), 'N')
	{
		isUnbreakable = true;
	}

	explicit BorderBlock(Vector2 pos)
		: Block(pos, 'N')
	{
		isUnbreakable = true;
	}
};