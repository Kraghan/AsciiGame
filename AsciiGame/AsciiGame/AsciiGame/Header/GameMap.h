#pragma once

#include <vector>
#include "Block.h"
#include "Vector2.h"

class GameMap
{
private: 
	unsigned int width;
	unsigned int height;
	std::vector<std::vector<Block>> blockMap;

public : 
	bool isInBound(Vector2 position);
};