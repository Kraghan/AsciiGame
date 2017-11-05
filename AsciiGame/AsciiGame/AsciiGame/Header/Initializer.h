#pragma once

#include "GameMap.h"
#include <ctime>

class Initializer
{
private : 
	static const unsigned int PROBABILITY = 45;
	static const unsigned int ITERATION = 5;
	static std::vector<std::vector<bool>> abstraction;

	static unsigned short getNumberOfNeighbour(Vector2 pos);

	static std::vector<std::vector<bool>> process();
public : 
	explicit Initializer() {};

	static void initializeBorder(GameMap* map);

	static void initializeCave(GameMap* map);

	static void initializeCollectible(GameMap* map, unsigned int nbScoreBlock, unsigned int nbAmmoBlock, unsigned int nbHeartBlock);
};