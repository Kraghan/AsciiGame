#include "..\Header\Bullet.h"

Bullet::Bullet(Vector2 pos, MOVE_TYPE move)
	: pos(pos), moveType(move)
{
	void changeHorizVerti(MOVE_TYPE moveType);					//déplace le joueur
}


Bullet::~Bullet()
{

}

void Bullet::changeHorizVerti()
{
	if (moveType != M_NOTHING)
	{
		addHoriz = 0;
		addVerti = 0;

		switch (moveType)
		{
		case M_UP:
			addVerti = -speedBullet;
			break;
		case M_DOWN:
			addVerti = speedBullet;
			break;
		case M_RIGHT:
			addHoriz = speedBullet;
			break;
		case M_LEFT:
			addHoriz = -speedBullet;
			break;

		case M_UP_RIGHT:
			addHoriz = -speedBullet;
			addVerti = speedBullet;
			break;
		case M_UP_LEFT:
			addHoriz = -speedBullet;
			addVerti = -speedBullet;
			break;
		case M_DOWN_RIGHT:
			addHoriz = speedBullet;
			addVerti = speedBullet;
			break;
		case M_DOWN_LEFT:
			addHoriz = speedBullet;
			addVerti = -speedBullet;
			break;
		}
		//TODO ???
		moveType = M_NOTHING;								//reset le moveType !
	}
}

///
/// déplace le bullet
///
void Bullet::update()
{
	pos.x = pos.x += addHoriz;
	pos.y = pos.y += addVerti;
}