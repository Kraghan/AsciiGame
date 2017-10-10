#pragma once
#include "Initializer.h"
#include "BorderBlock.h"

class BorderInitializer
{
public : 
	explicit BorderInitializer() {};
	virtual void initialize(GameMap* map);
};