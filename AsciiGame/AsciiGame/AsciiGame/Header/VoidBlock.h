#pragma once
#include "Block.h"

class VoidBlock : Block
{
public:
	explicit VoidBlock(void)
		: Block(Vector2(), ' ', false)
	{

	}

	explicit VoidBlock(Vector2 pos)
		: Block(pos, ' ', false)
	{

	}
};