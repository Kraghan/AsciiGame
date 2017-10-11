#pragma once			//que pour VS

#include <iostream>
#include "Vector2.h"
#include "Window.h"

class Block
{

friend class GameMap;
private :
	Vector2 position;
	char sprite;
	bool isSolid;

	void setSprite(char representation);
	void setPosition(Vector2 pos);
	void setIsSolid(bool solid);

public:
	explicit Block(void);
	explicit Block(Vector2 pos, char representation, bool isSolid = true);
	explicit Block(unsigned int x, unsigned int y, char representation, bool isSolid = true);
	virtual ~Block();

	char getSprite();
	Vector2 getPosition();
	bool getIsSolid();
	Vector2 getDimension();
	void display(Window* window);

};

