#pragma once

#include <vector>
#include "Block.h"
#include "NormalBlock.h"
#include "BorderBlock.h"
#include "AmmoBlock.h"
#include "LifeBlock.h"
#include "ScoreBlock.h"
#include "CorruptionBlock.h"
#include "Vector2.h"
#include "Window.h"
#include "AudioHelper.h"
#include "QuadTree.h"

class GameMap
{
private: 
	// Number of block that the gamemap can contains
	Vector2 dimension;
	
	// Used to store the blocks
	std::vector<Block*> blockMap;

	// Used to optimize collision
	QuadTree quadtree;

public : 
	// Constructors
	explicit GameMap(void);
	explicit GameMap(Vector2 dim);
	explicit GameMap(unsigned int x, unsigned int y);

	// Destructor
	virtual ~GameMap(void);

	// Check if a position is in bound
	bool isInBound(Vector2 position);
	bool isInBound(unsigned int x, unsigned int y);

	// Get the block at the position 
	Block* getBlock(Vector2 position);
	Block* getBlock(unsigned int x, unsigned int y);

	// Set the block at position
	void setBlock(Block* block);

	// Get the number of blocks in the map
	Vector2 getDimension(void);

	// Return all the blocks
	std::vector<Block*> getBlocks(void);

	// Return all the blocks near the bound
	std::vector<Block*> getBlocks(AABB bound);

	// Logical update method
	void update(void);

	// Display the map
	void display(Window* window);

	// Used to explode all the block which are not unbreakable in the circle of center position and of radius radius
	void explode(Vector2 position, unsigned int radius);

	// Destroy all the blocks
	void clear(void);

	// Debug method
	void debug(void);

	// Search a block at position position and if found, destroy it
	void destroyBlock(Vector2 position);

	// Update the quadtree
	void updateQuadTree();
};