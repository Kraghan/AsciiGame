#pragma once

#include "Initializer.h"

class CaveSeedInitializer : Initializer
{

private : 
	static const unsigned int PROBABILITY = 45;
	static const unsigned int ITERATION = 5;

	unsigned int getNumberOfNeighbour(GameMap* map, Vector2 pos);
	void process(GameMap* map);

public : 

	explicit CaveSeedInitializer() {};
	virtual void initialize(GameMap* map);
};