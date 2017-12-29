#pragma once
#include "GameMap.h"
#include <ctime>

class Initializer
{
private :
	static Vector2ui blockDimension;
	static unsigned short getNumberOfNeighbour(Vector2ui pos, std::vector<std::vector<bool>> vec);
public : 
	static void initializeBorder(GameMap* map);
	static void initializeCave(GameMap* map);
	static void initializePreparationWall(GameMap* map);
	static void initializeBorderPreparation(GameMap* map);
	static void initializePickUp(GameMap* map);
};
