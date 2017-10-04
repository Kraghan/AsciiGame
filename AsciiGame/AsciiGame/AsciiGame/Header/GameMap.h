#pragma once

#include <vector>
#include "Block.h"
#include "NormalBlock.h"
#include "BorderBlock.h"
#include "Vector2.h"

class GameMap
{
private: 
	Vector2 dimension;
	std::vector<std::vector<Block>> blockMap;

public : 
	explicit GameMap();
	explicit GameMap(Vector2 dim);
	explicit GameMap(unsigned int x, unsigned int y);
	virtual ~GameMap();

	// Check if a position is in bound
	bool isInBound(Vector2 position);
	bool isInBound(unsigned int x, unsigned int y);

	// Get the block at the position 
	Block* getBlock(Vector2 position);
	Block* getBlock(unsigned int x, unsigned int y);

	// Set the block at position
	void setBlock(Vector2 position, Block* block);
	void setBlock(unsigned int x, unsigned int y, Block* block);

	Vector2 getDimension();
	std::vector<std::vector<Block>> getBlocks();
	void update();


};