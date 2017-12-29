#pragma once
#include "Block.h"

class HeartBlock : public Block
{
public:
	explicit HeartBlock(void);
	explicit HeartBlock(Vector2ui position, Vector2ui dimension);
	virtual ~HeartBlock(void);

	virtual void collect(Player* player);
};