#include "..\Header\Player.h"

Player::Player()
{

}

Player::Player(Vector2 pos)
	: Entity(pos, Vector2(11, 9))
{
	setupRealPos();		//entity

	speed = speedPlayer;

	timer = Timer();
}

Player::~Player()
{

}

///
/// change addVerti et AddHoriz pour définir où il veut bouger (0,0) signifie ne bouge pas.
///
void Player::changeHorizVerti(bool stop, bool bullet = false)
{
	if (moveType != M_NOTHING)
	{
		switch (moveType)
		{
		case M_UP:
			if (!bullet)
				addVerti = (!stop) ? -speed : 0;	//si !stop, UP = -1, sinon, on a lancé l'événement STOP de UP, donc 0
			else
			{
				addShootVerti = -1;
			}
			break;
		case M_DOWN:
			if (!bullet)
				addVerti = (!stop) ? speed : 0;	//si !stop, DOWN = 1, sinon, on a lancé l'événement STOP de DOWN, donc 0
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
/// met le joueur dans l'état "essai de bouger dans une direction"
///
void Player::tryToMove(MOVE_TYPE moveTry)
{
	moveType = moveTry;							//change l'enum pour définir ou il veut bouger
	changeHorizVerti(false);							//change les variables d'additions à ajouter à la map

	tryedToMove = true;							//set le joueur dans l'état "essai de bouger"
}

///
/// essai de tirer
///
void Player::tryToShoot(MOVE_TYPE moveTry)
{
	if (timer.getElapsedSeconds() < timeReload)
		return;
	moveType = moveTry;							//change l'enum pour définir ou on tir
	bulletToShoot = true;
	changeHorizVerti(false, true);			//change les variables d'additions à ajouter à la map
}

///
/// créé un bullet (position, orientation)
///
Bullet Player::shoot()
{
	int posX = pos.x + (dimension.x * addShootHoriz);
	int posY = pos.y + (dimension.y * addShootVerti);
	Bullet bull(Vector2(posX, posY), addShootHoriz, addShootVerti);

	//reset les valeurs de tir
	addShootHoriz = 0;
	addShootVerti = 0;
	bulletToShoot = false;

	timer.start();

	return (bull);
}

///
/// stop le joueur et reset ses valeurs
///
void Player::stopMove(MOVE_TYPE moveTry)
{
	moveType = moveTry;							//change l'enum pour définir quel mouvement il a arreté
	changeHorizVerti(true);

	if (addHoriz == 0 && addVerti == 0)
		tryedToMove = false;
}


///
/// affiche le player (et cache l'ancien)
///
void Player::display(Window *win)
{
	displaySpaceInvader(win, true);	//enlève l'ancien en mettant du blanc
	displaySpaceInvader(win);		//affiche la nouvelle positions

	oldPos = pos;
}

///
/// affiche le sprite de l'objet: spaceInvader
///
void Player::displaySpaceInvader(Window *win, bool erase)
{
	char c = (!erase) ? carac : ' ';
	int x = (!erase) ? pos.x : oldPos.x;
	int y = (!erase) ? pos.y : oldPos.y;

	// Todo redraw IN THE RECT

	/*win->changePixel(x, y, c);
	win->changePixel(x - 1, y, c);
	win->changePixel(x - 2, y, c);
	win->changePixel(x - 3, y, c);
	win->changePixel(x - 4, y, c);
	win->changePixel(x - 5, y, c);
	win->changePixel(x + 1, y, c);
	win->changePixel(x + 2, y, c);
	win->changePixel(x + 3, y, c);
	win->changePixel(x + 4, y, c);
	win->changePixel(x + 5, y, c);

	win->changePixel(x, y - 1, c);
	win->changePixel(x + 1, y - 1, c);
	win->changePixel(x - 1, y - 1, c);
	
	win->changePixel(x + 3, y - 1, c);
	win->changePixel(x - 3, y - 1, c);

	win->changePixel(x + 4, y - 1, c);
	win->changePixel(x - 4, y - 1, c);

	win->changePixel(x, y - 2, c);
	win->changePixel(x - 1, y - 2, c);
	win->changePixel(x + 1, y - 2, c);
	win->changePixel(x - 2, y - 2, c);
	win->changePixel(x + 2, y - 2, c);
	win->changePixel(x - 3, y - 2, c);
	win->changePixel(x + 3, y - 2, c);

	win->changePixel(x - 2, y - 3, c);
	win->changePixel(x + 2, y - 3, c);

	win->changePixel(x - 3, y - 4, c);
	win->changePixel(x + 3, y - 4, c);

	win->changePixel(x, y + 1, c);
	win->changePixel(x - 1, y + 1, c);
	win->changePixel(x - 2, y + 1, c);
	win->changePixel(x - 3, y + 1, c);
	win->changePixel(x - 5, y + 1, c);
	win->changePixel(x + 1, y + 1, c);
	win->changePixel(x + 2, y + 1, c);
	win->changePixel(x + 3, y + 1, c);
	win->changePixel(x + 5, y + 1, c);

	win->changePixel(x - 3, y + 2, c);
	win->changePixel(x - 5, y + 2, c);
	win->changePixel(x + 3, y + 2, c);
	win->changePixel(x + 5, y + 2, c);

	win->changePixel(x - 1, y + 3, c);
	win->changePixel(x - 2, y + 3, c);
	win->changePixel(x + 1, y + 3, c);
	win->changePixel(x + 2, y + 3, c);*/

	for (int i = 0; i < dimension.x; ++i)
	{
		for (int j = 0; j < dimension.y; ++j)
		{
			win->changePixel(x + i, y + j, c, 0x05);
		}
	}

}

///
/// déplace le joueur ?
///
void Player::update()
{
	//ici, actualiser la position du joueur
	pos.x += addHoriz * speed;
	pos.y += addVerti * speed;

	setupRealPos();
}