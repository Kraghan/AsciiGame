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

///
/// change addVerti et AddHoriz pour d�finir o� il veut bouger (0,0) signifie ne bouge pas.
///
void Player::changeHorizVerti(bool stop = false)
{
	if (moveType != M_NOTHING)
	{
		switch (moveType)
		{
		case M_UP:
			addVerti = (!stop) ? -speedPlayer : 0;	//si !stop, UP = -1, sinon, on a lanc� l'�v�nement STOP de UP, donc 0
			break;
		case M_DOWN:
			addVerti = (!stop) ? speedPlayer : 0;	//si !stop, DOWN = -1, sinon, on a lanc� l'�v�nement STOP de UP, donc 0
			break;
		case M_RIGHT:
			addHoriz = (!stop) ? speedPlayer : 0;
			break;
		case M_LEFT:
			addHoriz = (!stop) ? -speedPlayer : 0;
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
		//TODO ???
		moveType = M_NOTHING;								//reset le moveType !
	}
}

///
/// met le joueur dans l'�tat "essai de bouger dans une direction"
///
void Player::tryToMove(MOVE_TYPE moveTry)
{
	//ici, dire "BOUGER A DROITE"
	moveType = moveTry;							//change l'enum pour d�finir ou il veut bouger
	changeHorizVerti(false);							//change les variables d'additions � ajouter � la map

	tryedToMove = true;							//set le joueur dans l'�tat "essai de bouger"
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
/// d�place le joueur ?
///
void Player::update()
{
	//ici, actualiser la position du joueur
	pos.x = pos.x += addHoriz;
	pos.y = pos.y += addVerti;

	//addHoriz = 0;							//reset les additions !
	//addVerti = 0;
}