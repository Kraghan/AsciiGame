#pragma once
#include "Block.h"

class NormalBlock : public Block
{
private : 

public:
	explicit NormalBlock(void);
	explicit NormalBlock(Vector2ui position, Vector2ui dimension);
	virtual ~NormalBlock(void);
};