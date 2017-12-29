#pragma once
#include "Block.h"

class UnbreakableBlock : public Block
{
private:

public:
	explicit UnbreakableBlock(void);
	explicit UnbreakableBlock(Vector2ui position, Vector2ui dimension);
	virtual ~UnbreakableBlock(void);
};