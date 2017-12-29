#include "../Headers/Bullet.h"
#include "../Headers/Debug.h"

/*explicit*/ Bullet::Bullet()
	: Bullet(Vector2f(0, 0), Vector2f(4, 4), 1, Vector2f(1, 0))
{

}

/*explicit*/ Bullet::Bullet(Vector2f position, Vector2f dimension, float speed, Vector2f orientation)
	: Entity(1,speed,position,dimension)
	, orientation(orientation)
	, delay(0)
{

}

/*virtual*/ void Bullet::update()
{
	if (delay <= 0)
		bounds.position = getNextPosition();
	else
		--delay;
	
}

/*virtual*/ void Bullet::display(Vector2f camera)
{
	for (int x = 0; x < bounds.getWidth(); ++x)
	{
		for (int y = 0; y < bounds.getHeight(); ++y)
		{
			window->drawChar(bounds.getX() + x - camera.x, bounds.getY() + y - camera.y, 'X', ColorHelper::AQUA + ColorHelper::BRIGHT);
		}
	}
}

/*virtual*/ Vector2f Bullet::getNextPosition()
{
	return Vector2f(bounds.getX() + (speed * orientation.x), bounds.getY() + (speed * orientation.y));
}

void Bullet::setDelay(int del)
{
	delay = del;
}