#pragma once

#include "Initializer.h"
#include <ctime>

class CaveSeedInitializer : Initializer
{

private : 
	static const unsigned int PROBABILITY = 45;
	static const unsigned int ITERATION = 5;

	std::vector<std::vector<bool>> abstraction;

	unsigned short getNumberOfNeighbour(Vector2 pos);
	void process();

public : 

	explicit CaveSeedInitializer() {};
	virtual void initialize(GameMap* map);
};