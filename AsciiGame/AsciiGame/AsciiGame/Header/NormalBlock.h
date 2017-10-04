#pragma once
#include "Block.h"

class NormalBlock : Block
{
public:
	explicit NormalBlock(void)
		: Block(Vector2(), 'x')
	{

	}
	explicit NormalBlock(Vector2 pos)
		: Block(pos, 'x')
	{

	}
};