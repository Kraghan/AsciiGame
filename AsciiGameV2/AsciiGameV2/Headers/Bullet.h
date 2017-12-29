#pragma once
#include "Entity.h"


class Bullet : public Entity
{
private :
	Vector2f orientation;
	int delay;
public : 
	explicit Bullet();
	explicit Bullet(Vector2f position, Vector2f dimension, float speed, Vector2f orientation);

	virtual void update();
	virtual void display(Vector2f camera);
	virtual Vector2f getNextPosition();

	void setDelay(int delay);
};