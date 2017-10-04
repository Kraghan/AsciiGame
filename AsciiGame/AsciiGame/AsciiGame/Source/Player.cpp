#include "..\Header\Player.h"

Player::Player()
{

}

Player::Player(Vector2 pos)
	: pos(pos)
{

}

Player::~Player()
{

}

void Player::changeHorizVerti()
{
	if (moveType != M_NOTHING)
	{
		addHoriz = 0;
		addVerti = 0;

		switch (moveType)
		{
		case M_UP:
			addVerti = -speedPlayer;
			break;
		case M_DOWN:
			addVerti = speedPlayer;
			break;
		case M_RIGHT:
			addHoriz = speedPlayer;
			break;
		case M_LEFT:
			addHoriz = -speedPlayer;
			break;

		case M_UP_RIGHT:
			addHoriz = -speedPlayer;
			addVerti = speedPlayer;
			break;
		case M_UP_LEFT:
			addHoriz = -speedPlayer;
			addVerti = -speedPlayer;
			break;
		case M_DOWN_RIGHT:
			addHoriz = speedPlayer;
			addVerti = speedPlayer;
			break;
		case M_DOWN_LEFT:
			addHoriz = speedPlayer;
			addVerti = -speedPlayer;
			break;
		}
		moveType = M_NOTHING;								//reset le moveType !
	}
}

///
/// met le joueur dans l'état "essai de bouger dans une direction"
///
void Player::tryToMove(MOVE_TYPE moveTry)
{
	//ici, dire "BOUGER A DROITE"
	moveType = moveTry;							//change l'enum pour définir ou il veut bouger
	changeHorizVerti();							//change les variables d'additions à ajouter à la map

	tryedToMove = true;							//set le joueur dans l'état "essai de bouger"
}


///
/// déplace le joueur ?
///
void Player::update()
{
	//ici, actualiser la position du joueur
	pos.x = pos.x += addHoriz;
	pos.y = pos.y += addVerti;

	addHoriz = 0;							//reset les additions !
	addVerti = 0;
}