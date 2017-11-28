#pragma once
#include "Block.h"

class CorruptionBlock : public Block
{
private : 
	bool active;

public:
	// Default constructor
	explicit CorruptionBlock(void)
		: Block(Vector2(), 'X')
	{
		setName("CorruptionBlock");
	}

	// Constructor with initial position
	explicit CorruptionBlock(Vector2 pos)
		: Block(pos, 'X')
	{
		setName("CorruptionBlock");
	}

	// Called once per frame, used to display block
	virtual void display(Window* window);

	// Set if this corruption block can corrupted other block
	void setActive(bool active);

	// Get if the corruption block is active
	bool getActive();
};