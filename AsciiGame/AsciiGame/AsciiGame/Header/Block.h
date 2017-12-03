#pragma once			//que pour VS

#include <iostream>
#include "Vector2.h"
#include "Window.h"
#include "Player.h"

class Block
{

friend class GameMap;
private :
	// Position of the block
	Vector2 position;

	// Char used to display the block
	char sprite;

	// Used to differenciate block
	std::string blockName;

	// If true, the block is collidable
	bool isSolid;

	// If true, the block is a collectable (will call the collect function on collide)
	bool isCollectable;

	// If true, the block is unbreakable
	bool isUnbreakable;

	// Set the char used to display the block
	void setSprite(char representation);

	// Set the position of the block
	void setPosition(Vector2 pos);

	// Set if the block is solid
	void setIsSolid(bool solid);

protected :
	// To call only in constructor !
	void setName(std::string name);

public:
	// Default constructor
	explicit Block(void);

	// Constructor with vector2 coordinate
	explicit Block(Vector2 pos, char representation, bool isSolid = true, bool isCollectable = false, bool isUnbreakable = false);

	// Constructor with two separated coordinates
	explicit Block(unsigned int x, unsigned int y, char representation, bool isSolid = true, bool isCollectable = false, bool isUnbreakable = false);

	// Destructor
	virtual ~Block();

	// Get the char used to render the block
	char getSprite();

	// Get the position of the block
	Vector2 getPosition();

	// True if the block is collidable
	bool getIsSolid();

	// True if the block is unbreakable
	bool getIsUnbreakable();

	// Get the size of the block
	Vector2 getDimension();

	// Display the block
	virtual void display(Window* window);

	// Called when the player collide with the block to check if the player can collect the block
	virtual bool canCollect(Player* player);

	// Called when the player collide with the block if the block is set to collectable
	virtual void collect(Player* player);

	// Return true if the block is collectable
	bool getIsCollectable();

	// Get block name
	std::string getName();
};

