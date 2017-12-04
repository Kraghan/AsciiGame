#pragma once

#include "GameMap.h"
#include <ctime>

class Initializer
{
private : 
	// Used in the cave generation. Probability that a block is initialy set to "alive"
	static const unsigned int PROBABILITY = 45;

	// Used in the cave generation. Number of generation
	static const unsigned int ITERATION = 5;

	// Used in the cave generation. 2D array used to define if a cell is dead or alive
	static std::vector<std::vector<bool>> abstraction;

	// Used in the cave generation. Return the number of cells alive next to the cell at position pos
	static unsigned short getNumberOfNeighbour(Vector2 pos);

	// Used in the cave generation. Function which do an iteration of the game of life
	static std::vector<std::vector<bool>> process(void);
public : 
	// Function used to initialize the border of the gamemap with unbreakable block
	static void initializeBorder(GameMap* map);

	// Function used to initialize the border of the gamemap in the game preparation window
	static void initializePreparationBorder(GameMap* map);

	// Function used to initialize the wall in the game preparation window
	static void initializePreparationWall(GameMap* map);

	// Function used to generate a cave
	static void initializeCave(GameMap* map);

	// Function used to place the pick up on the level
	static void initializeCollectible(GameMap* map, unsigned int nbScoreBlock, unsigned int nbAmmoBlock, unsigned int nbHeartBlock);

	// Function used to place the corruption seed
	static void initializeCorruption(GameMap* map, unsigned int nbSeeds);

	// Function used to place the player on an empty area
	static void initializePlayerPosition(GameMap* map, Player* player);
};