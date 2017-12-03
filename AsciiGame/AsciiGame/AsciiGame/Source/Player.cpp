#include "..\Header\Player.h"

Player::Player()
	: Entity()
{

}

Player::Player(Vector2 pos)
	: Entity(pos, Vector2(11, 8))
{
	speed = speedPlayer;

	timer = Timer();

	lifePoint = MAX_LIFE_POINT;
	ammunition = MAX_AMMO;
	score = 0;
}

Player::~Player()
{

}

///
/// change addVerti et AddHoriz pour d�finir o� il veut bouger (0,0) signifie ne bouge pas.
///
void Player::changeHorizVerti(bool stop, bool bullet = false)
{
	if (moveType != M_NOTHING)
	{
		switch (moveType)
		{
		case M_UP:
			if (!bullet)
				addVerti = (!stop) ? -speed : 0;	//si !stop, UP = -1, sinon, on a lanc� l'�v�nement STOP de UP, donc 0
			else
			{
				addShootVerti = -1;
			}
			break;
		case M_DOWN:
			if (!bullet)
				addVerti = (!stop) ? speed : 0;	//si !stop, DOWN = 1, sinon, on a lanc� l'�v�nement STOP de DOWN, donc 0
			else
			{
				addShootVerti = 1;
			}
			break;
		case M_RIGHT:
			if (!bullet)
				addHoriz = (!stop) ? speed : 0;
			else
			{
				addShootHoriz = 1;
			}
			break;
		case M_LEFT:
			if (!bullet)
				addHoriz = (!stop) ? -speed : 0;
			else
			{
				addShootHoriz = -1;
			}
			break;
		}
		//TODO ???
		moveType = M_NOTHING;								//reset le moveType !
	}
}

///
/// met le joueur dans l'�tat "essai de bouger dans une direction"
///
void Player::tryToMove(MOVE_TYPE moveTry)
{
	moveType = moveTry;							//change l'enum pour d�finir ou il veut bouger
	changeHorizVerti(false);							//change les variables d'additions � ajouter � la map

	tryedToMove = true;							//set le joueur dans l'�tat "essai de bouger"
}

///
/// essai de tirer
///
void Player::tryToShoot(MOVE_TYPE moveTry)
{
	if (timer.getElapsedSeconds() < weapon->getTimeBetweenShoot())
		return;
	moveType = moveTry;							//change l'enum pour d�finir ou on tir
	bulletToShoot = true;
	changeHorizVerti(false, true);			//change les variables d'additions � ajouter � la map
}

///
/// cr�� un bullet (position, orientation)
///
std::vector<Bullet> Player::shoot()
{
	/*int posX = bounds.position.x + (bounds.dimension.x / 2) + (bounds.dimension.x * addShootHoriz);
	int posY = bounds.position.y + (bounds.dimension.y / 2) + (bounds.dimension.y * addShootVerti);*/
	int posX = bounds.position.x + (bounds.dimension.x / 2);
	int posY = bounds.position.y + (bounds.dimension.y / 2);
	
	std::vector<Bullet> vec = weapon->shoot(Vector2(posX,posY),addShootHoriz, addShootVerti );

	//reset les valeurs de tir
	addShootHoriz = 0;
	addShootVerti = 0;
	bulletToShoot = false;
	--ammunition;

	timer.start();
	AudioHelper::getAudioHelper()->play("shoot");

	return (vec);
}

///
/// stop le joueur et reset ses valeurs
///
void Player::stopMove(MOVE_TYPE moveTry)
{
	moveType = moveTry;							//change l'enum pour d�finir quel mouvement il a arret�
	changeHorizVerti(true);

	if (addHoriz == 0 && addVerti == 0)
		tryedToMove = false;
}


///
/// affiche le player (et cache l'ancien)
///
void Player::display(Window *win)
{
	int x = bounds.position.x;
	int y = bounds.position.y;

	x = x + (bounds.dimension.x / 2);
	y = y + (bounds.dimension.y / 2);

	win->changePixel(x, y, carac, color);
	win->changePixel(x - 1, y, carac, color);
	win->changePixel(x - 2, y, carac, color);
	win->changePixel(x - 3, y, carac, color);
	win->changePixel(x - 4, y, carac, color);
	win->changePixel(x - 5, y, carac, color);
	win->changePixel(x + 1, y, carac, color);
	win->changePixel(x + 2, y, carac, color);
	win->changePixel(x + 3, y, carac, color);
	win->changePixel(x + 4, y, carac, color);
	win->changePixel(x + 5, y, carac, color);

	win->changePixel(x, y - 1, carac, color);
	win->changePixel(x + 1, y - 1, carac, color);
	win->changePixel(x - 1, y - 1, carac, color);

	win->changePixel(x + 3, y - 1, carac, color);
	win->changePixel(x - 3, y - 1, carac, color);

	win->changePixel(x + 4, y - 1, carac, color);
	win->changePixel(x - 4, y - 1, carac, color);

	win->changePixel(x, y - 2, carac, color);
	win->changePixel(x - 1, y - 2, carac, color);
	win->changePixel(x + 1, y - 2, carac, color);
	win->changePixel(x - 2, y - 2, carac, color);
	win->changePixel(x + 2, y - 2, carac, color);
	win->changePixel(x - 3, y - 2, carac, color);
	win->changePixel(x + 3, y - 2, carac, color);

	win->changePixel(x - 2, y - 3, carac, color);
	win->changePixel(x + 2, y - 3, carac, color);

	win->changePixel(x - 3, y - 4, carac, color);
	win->changePixel(x + 3, y - 4, carac, color);

	win->changePixel(x, y + 1, carac, color);
	win->changePixel(x - 1, y + 1, carac, color);
	win->changePixel(x - 2, y + 1, carac, color);
	win->changePixel(x - 3, y + 1, carac, color);
	win->changePixel(x - 5, y + 1, carac, color);
	win->changePixel(x + 1, y + 1, carac, color);
	win->changePixel(x + 2, y + 1, carac, color);
	win->changePixel(x + 3, y + 1, carac, color);
	win->changePixel(x + 5, y + 1, carac, color);

	win->changePixel(x - 3, y + 2, carac, color);
	win->changePixel(x - 5, y + 2, carac, color);
	win->changePixel(x + 3, y + 2, carac, color);
	win->changePixel(x + 5, y + 2, carac, color);

	win->changePixel(x - 1, y + 3, carac, color);
	win->changePixel(x - 2, y + 3, carac, color);
	win->changePixel(x + 1, y + 3, carac, color);
	win->changePixel(x + 2, y + 3, carac, color);

	oldPos = bounds.position;
}

///
/// d�place le joueur ?
///
void Player::update()
{
	//ici, actualiser la position du joueur
	bounds.position.x += addHoriz * speed;
	bounds.position.y += addVerti * speed;
}

bool Player::canShoot()
{
	return bulletToShoot && ammunition != 0;
}

void Player::addLifePoint(unsigned int health)
{
	lifePoint += health;
	if (lifePoint > MAX_LIFE_POINT)
		lifePoint = MAX_LIFE_POINT;
}

void Player::addAmmo(unsigned int ammo)
{
	ammunition += ammo;
	if (ammunition > MAX_AMMO)
		ammunition = MAX_AMMO;
}

void Player::setWeapon(Weapon* weap)
{
	weapon = weap;
}

Weapon* Player::getWeapon()
{
	return weapon;
}