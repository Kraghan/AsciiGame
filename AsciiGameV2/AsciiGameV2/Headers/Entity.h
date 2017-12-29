#pragma once
#include "AABB.h"
#include "Window.h"

enum MoveDirection
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

class Entity
{
protected :
	float sqrt2;
	AABBf bounds;
	int lifePoint; 
	Window * window;
	MoveDirection direction;
	float speed;

public : 
	explicit Entity();
	explicit Entity(int life, float speed, Vector2f position, Vector2f dimension);
	virtual ~Entity();

	virtual void update();
	virtual void display(Vector2f camera) = 0;

	void askToMove(MoveDirection direction);

	int getLife();

	void hit(int damage);

	AABBf getBounds();

	Vector2f getPosition();

	virtual Vector2f getNextPosition();

	Vector2f getDimension();

};