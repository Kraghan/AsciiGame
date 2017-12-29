#pragma once
#include "Window.h"
#include "QuadTree.h"
#include "NormalBlock.h"
#include "UnbreakableBlock.h"
#include "ScoreBlock.h"
#include "AmmoBlock.h"
#include "HeartBlock.h"
#include "AudioHelper.h"

class GameMap
{
private : 
	Vector2ui dimension;
	QuadTree quadTree;

public : 
	explicit GameMap(void);
	explicit GameMap(Vector2ui dimension);
	virtual ~GameMap(void);

	void addBlock(Block* block);
	
	void update(void);
	void display(Vector2f cameraPosition);

	Vector2ui getDimension();

	std::vector<Block*> getBlocks(Vector2f position, Vector2f dimension);

	void explode(Vector2ui positions, int radius);

	void removeBlock(Block* block);
};