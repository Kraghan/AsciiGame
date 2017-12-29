#pragma once
#include "Block.h"

class ScoreBlock : public Block
{
public:
	explicit ScoreBlock(void);
	explicit ScoreBlock(Vector2ui position, Vector2ui dimension);
	virtual ~ScoreBlock(void);

	virtual void collect(Player* player);

	static int nbBlock;
	static int level;
};