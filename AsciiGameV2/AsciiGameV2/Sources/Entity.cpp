#include "../Headers/Entity.h"

/*explicit*/ Entity::Entity()
	: Entity(1,1,Vector2f(0,Window::UI_HEIGHT), Vector2f(4,4))
{
	
}

/*explicit*/ Entity::Entity(int life, float speed, Vector2f position, Vector2f dimension)
	: bounds(position,dimension)
	, lifePoint(life)
	, speed(speed)
{
	window = Window::getInstance();
	sqrt2 = sqrt(2);
}

/*virtual*/ Entity::~Entity()
{

}

/*virtual*/ void Entity::update()
{
	if (direction != MoveDirection::NONE)
	{
		bounds.position = getNextPosition();

		direction = MoveDirection::NONE;
	}

}

void Entity::askToMove(MoveDirection dir)
{	
	if (dir == MoveDirection::NONE)
		direction = dir;
	else if (dir == MoveDirection::DOWN)
	{
		if (direction == MoveDirection::LEFT)
			direction = MoveDirection::DOWN_LEFT;
		else if (direction == MoveDirection::RIGHT)
			direction = MoveDirection::DOWN_RIGHT;
		else
			direction = dir;
	}
	else if (dir == MoveDirection::UP)
	{
		if (direction == MoveDirection::LEFT)
			direction = MoveDirection::UP_LEFT;
		else if (direction == MoveDirection::RIGHT)
			direction = MoveDirection::UP_RIGHT;
		else
			direction = dir;
	}
	else if (dir == MoveDirection::LEFT)
	{
		if (direction == MoveDirection::UP)
			direction = MoveDirection::UP_LEFT;
		else if (direction == MoveDirection::DOWN)
			direction = MoveDirection::DOWN_LEFT;
		else
			direction = dir;
	}
	else if (dir == MoveDirection::RIGHT)
	{
		if (direction == MoveDirection::UP)
			direction = MoveDirection::UP_RIGHT;
		else if (direction == MoveDirection::DOWN)
			direction = MoveDirection::DOWN_RIGHT;
		else
			direction = dir;
	}

}

int Entity::getLife()
{
	return lifePoint;
}

void Entity::hit(int damage)
{
	lifePoint -= damage;
}

AABBf Entity::getBounds()
{
	return bounds;
}

Vector2f Entity::getPosition()
{
	return bounds.position;
}

Vector2f Entity::getNextPosition()
{
	Vector2f pos = bounds.position;

	if (direction != MoveDirection::NONE)
	{
		switch (direction)
		{
		case UP:
			pos.y -= speed;
			break;
		case DOWN:
			pos.y += speed;
			break;
		case LEFT:
			pos.x -= speed;
			break;
		case RIGHT:
			pos.x += speed;
			break;
		case UP_LEFT:
			pos.x -= speed / sqrt2;
			pos.y -= speed / sqrt2;
			break;
		case UP_RIGHT:
			pos.x += speed / sqrt2;
			pos.y -= speed / sqrt2;
			break;
		case DOWN_LEFT:
			pos.x -= speed / sqrt2;
			pos.y += speed / sqrt2;
			break;
		case DOWN_RIGHT:
			pos.x += speed / sqrt2;
			pos.y += speed / sqrt2;
			break;
		default:
			break;
		}
	}

	return pos;
}

Vector2f Entity::getDimension()
{
	return bounds.dimension;
}