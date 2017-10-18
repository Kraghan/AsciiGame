#pragma once

#include "GameMap.h"
#include <ctime>

class Initializer
{
private : 
	static const unsigned int PROBABILITY = 45;
	static const unsigned int ITERATION = 5;

	static unsigned short getNumberOfNeighbour(Vector2 pos, std::vector<std::vector<bool>> abstraction);

	static std::vector<std::vector<bool>> process(std::vector<std::vector<bool>> abstraction);
public : 
	explicit Initializer() {};

	static void initializeBorder(GameMap* map);

	static void initializeCave(GameMap* map);
};