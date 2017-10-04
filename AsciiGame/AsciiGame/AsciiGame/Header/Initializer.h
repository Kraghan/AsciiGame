#pragma once

#include "GameMap.h"

class Initializer
{
public : 
	explicit Initializer() {};
	virtual void initialize(GameMap* map) = 0;
};