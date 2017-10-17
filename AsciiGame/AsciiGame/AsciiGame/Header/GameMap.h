#pragma once

#include <vector>
#include "Block.h"
#include "NormalBlock.h"
#include "BorderBlock.h"
#include "Vector2.h"
#include "Window.h"

class GameMap
{
private: 
	Vector2 dimension;
	std::vector<Block*> blockMap;
	bool needRedraw;

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
	void setBlock(Block* block);

	Vector2 getDimension();
	std::vector<Block*> getBlocks();
	void update();
	void display(Window* window);
	void explode(Vector2 position, unsigned int radius);
	void debug();

};