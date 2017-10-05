#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(Window* wind)
{
	window = wind;												//cr�� un lien du graphic engine
	player = Player(Vector2(10, 10));							//cr�� un player, � la position 10,10
	gameMap = GameMap(Window::SCREEN_WIDTH,Window::SCREEN_HEIGHT);

	BorderInitializer borderInit = BorderInitializer();
	borderInit.initialize(&gameMap);
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	gameMap.update();
	std::vector<std::vector<Block>> blocks = gameMap.getBlocks();

	for (unsigned int i = 0; i < blocks.size(); ++i)
	{
		for (unsigned int j = 0; j < blocks[i].size(); ++j)
		{
			window->changePixel(i, j, blocks[i][j].getSprite());
		}
	}
	
	//if (player.tryedToMove)								//le joueur a essay� de bouger
	//{
		//si les colisions sont ok, bouger le joueur
		//{
		//afficher le player dans graphicEngine (et remettre un couloir dans son ancienne position)
		displayPlayer();
		
		player.update();		//ici actualise les nouvelles positions du joueur
								//}
								//else						//sinon, reset les add/verti du player pour ne pas qu'il bouge !
								//{
								//player.addHoriz = 0;
								//player.addVerti = 0;
								//}
		//player.tryedToMove = false;
	//}

	//parcourt tous les bullet pr�sents...
	/*for (auto & element : bullet)
	{
		displayBullet(element);
		element.update();
	}*/
	//Bullet ?? list de bullet

	//window->drawColorWithCode();

}

// Process the input
/*virtual*/ bool GameStateGame::processInput(void)
{
	Event* e = window->popEvent();
	while (e != nullptr)
	{
		if (e->input == Event::INPUT::KB_ESCAPE
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			stateMachine->activeState("pause");
		}

		inputPlayer(e);											//input du joueur in-game

		e = window->popEvent();
	}
	return true;
}

// Called when the state is set to active
/*virtual*/ void GameStateGame::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateGame::onExit(void)
{

}
////////////////////////////////////// display object ///////////////////////////////

void GameStateGame::displayPlayer()
{
	window->changePixel(player.pos.x, player.pos.y, ' ');
	window->changePixel(player.pos.x + player.addHoriz, player.pos.y + player.addVerti, player.carac, player.color);
}

void GameStateGame::displayBullet(Bullet &bullet)
{
	//changePixel(oldPos.x, oldPos.y, ' ');
	//changePixel(newPos.x, newPos.y, '*', 7);
}


////////////////////////////////////// INPUT PLAYER ///////////////////////////////////
void GameStateGame::inputPlayer(Event *e)
{
	//////////////////////////////////////le joueur move
	//up
	if (e->input == Event::INPUT::KB_Z
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_UP);
	}

	//DOWN
	else if (e->input == Event::INPUT::KB_S
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_DOWN);
	}
	//RIGHT
	else if (e->input == Event::INPUT::KB_D
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_RIGHT);
	}
	//LEFT
	else if (e->input == Event::INPUT::KB_Q
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_LEFT);
	}
	/////////////////////////////////////le joueur stop
	//up stop
	if (e->input == Event::INPUT::KB_Z && e->typeInput == Event::TYPE_INPUT_EVENT::TI_RELEASED)
	{
		player.stopMove(Player::MOVE_TYPE::M_UP);
	}
	//DOWN stop
	else if (e->input == Event::INPUT::KB_S && e->typeInput == Event::TYPE_INPUT_EVENT::TI_RELEASED)
	{
		player.stopMove(Player::MOVE_TYPE::M_DOWN);
	}
	//RIGHT stop
	else if (e->input == Event::INPUT::KB_D && e->typeInput == Event::TYPE_INPUT_EVENT::TI_RELEASED)
	{
		player.stopMove(Player::MOVE_TYPE::M_RIGHT);
	}
	//LEFT stop
	else if (e->input == Event::INPUT::KB_Q	&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_RELEASED)
	{
		player.stopMove(Player::MOVE_TYPE::M_LEFT);
	}

	///////////////////////////////////////////////////SHOOT
	if (e->input == Event::INPUT::KB_UP
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		Bullet bul = Bullet(Vector2(player.pos.x, player.pos.y - 1), Bullet::MOVE_TYPE::M_UP);
		bullet.push_back(bul);
	}

	//DOWN
	else if (e->input == Event::INPUT::KB_DOWN
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		Bullet bul = Bullet(Vector2(player.pos.x, player.pos.y + 1), Bullet::MOVE_TYPE::M_DOWN);
		bullet.push_back(bul);
	}
	//RIGHT
	else if (e->input == Event::INPUT::KB_RIGHT
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		Bullet bul = Bullet(Vector2(player.pos.x + 1, player.pos.y), Bullet::MOVE_TYPE::M_RIGHT);
		bullet.push_back(bul);
	}
	//LEFT
	else if (e->input == Event::INPUT::KB_LEFT
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		Bullet bul = Bullet(Vector2(player.pos.x - 1, player.pos.y), Bullet::MOVE_TYPE::M_LEFT);
		bullet.push_back(bul);
	}
}
