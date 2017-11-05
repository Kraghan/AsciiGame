#pragma once			//que pour VS

#include <iostream>
#include "Vector2.h"
#include "Window.h"
#include "Player.h"

class Block
{

friend class GameMap;
private :
	Vector2 position;
	char sprite;
	bool isSolid;
	bool isCollectable;

	void setSprite(char representation);
	void setPosition(Vector2 pos);
	void setIsSolid(bool solid);

protected:
	bool isUnbreakable;

public:
	explicit Block(void);
	explicit Block(Vector2 pos, char representation, bool isSolid = true, bool isCollectable = false);
	explicit Block(unsigned int x, unsigned int y, char representation, bool isSolid = true, bool isCollectable = false);
	virtual ~Block();

	char getSprite();
	Vector2 getPosition();
	bool getIsSolid();
	Vector2 getDimension();
	virtual void display(Window* window);
	virtual void collect(Player* player);
	bool getIsCollectable();
};

