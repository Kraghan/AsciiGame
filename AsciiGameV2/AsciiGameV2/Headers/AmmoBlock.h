#pragma once
#include "Block.h"

class AmmoBlock : public Block
{
public:
	explicit AmmoBlock(void);
	explicit AmmoBlock(Vector2ui position, Vector2ui dimension);
	virtual ~AmmoBlock(void);

	virtual void collect(Player* player);
};