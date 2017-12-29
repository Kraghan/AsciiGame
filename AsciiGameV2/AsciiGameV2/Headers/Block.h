#pragma once
#include "AABB.h"
#include "Window.h"
#include "Player.h"

class Block
{
protected : 
	int color;
	AABBui bounds;
	// Say if the block can be crossed
	bool isSolid;

	// Say if the block can be destroyed with shoot
	bool isUnbreakable;

	bool disabled;

public : 
	explicit Block(void);
	explicit Block(bool solid, bool unbreakable, int color, Vector2ui position, Vector2ui dimension);
	virtual ~Block(void);

	virtual void display(Vector2f cameraPosition);
	virtual void collect(Player* player);
	Vector2ui getPosition();
	Vector2ui getDimension();
	AABBui getBounds();
	bool solid();
	bool unbreakable();

};