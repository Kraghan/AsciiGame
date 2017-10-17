#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(Window* wind)
{
	window = wind;																	//créé un lien du graphic engine
	player = Player(Vector2(10, Window::UI_HEIGHT + 10));							//créé un player, à la position 10,10
	gameMap = GameMap(Window::SCREEN_WIDTH / 4,(Window::SCREEN_HEIGHT - Window::UI_HEIGHT) / 4);

	BorderInitializer borderInit = BorderInitializer();
	borderInit.initialize(&gameMap);
	CaveSeedInitializer caveInit = CaveSeedInitializer();
	//caveInit.initialize(&gameMap);
	window->clear();
	needRedrawUi = true;
	timeElapsed = 0.0;
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	timeElapsed += Timer::SECONDS_PER_UPDATE;
	gameMap.update();

	Vector2 playerNextPos = Vector2(player.pos.x + player.addHoriz * player.speed, player.pos.y + player.addVerti * player.speed);
	std::vector<Block*> blocks = gameMap.getBlocks();

	// Si les deux angles (haut gauche et bas droit) du joueur sont dans les limites du jeu
	if (gameMap.isInBound(playerNextPos) 
		&& gameMap.isInBound(Vector2(playerNextPos.x + player.dimension.x, playerNextPos.y + player.dimension.y)))
	{
		bool wallCollisionOk = true;

		// On check pour tous les blocks si on a une collision
		// La meilleure opti à envisager serai la quad map
		for (unsigned int i = 0; i < blocks.size(); ++i)
		{
			Vector2 blockPos = blocks[i]->getPosition();
			Vector2 blockDim = blocks[i]->getDimension();
			blockPos.x *= 4;
			blockPos.y *= 4;
			blockPos.y += Window::UI_HEIGHT;
			
			if (collision(playerNextPos,player.dimension,blockPos, blockDim))
			{
				/*if (!(playerNextPos.x >= blockPos.x + blockDim.x)
					&& !(playerNextPos.x + player.dimension.x <= blockPos.x))

				if (!(playerNextPos.y >= blockPos.y + blockDim.y)
					&& !(playerNextPos.y + player.dimension.y <= blockPos.y))*/

				wallCollisionOk = false;
				break;
			}
		}

		if(wallCollisionOk)
		{
			player.update();		//ici actualise les nouvelles positions du joueur
		}
		else
		{
			player.addHoriz = 0;
			player.addVerti = 0;
		}
	}
	
	for (std::vector<Bullet>::iterator it = bullet.begin(); it != bullet.end();)
	{
		Vector2 bulletNextPos = Vector2((*it).position.x + (*it).addHoriz * (*it).speed, (*it).position.y + (*it).addVerti * (*it).speed);
		bool collide = false;
		for (unsigned int i = 0; i < blocks.size(); ++i)
		{
			Vector2 blockPos = blocks[i]->getPosition();
			Vector2 blockDim = blocks[i]->getDimension();
			blockPos.x *= 4;
			blockPos.y *= 4;
			blockPos.y += Window::UI_HEIGHT;
			if (collision(blockPos, blockDim, bulletNextPos,(*it).dimension))
			{
				collide = true;
				break;
			}
		}
		if (!collide)
		{
			(*it).update();
			++it;
		}
		else
		{
			it = bullet.erase(it);
			gameMap.explode(bulletNextPos,20);
		}

	}

	for (auto & element : ia)
	{
		element.update();
	}

	//parcourt tous les bullet prï¿½sents...
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

		if (e->input == Event::INPUT::KB_I
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			IA popIa(Vector2(200, 100));
			ia.push_back(popIa);
		}

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStateGame::display()
{
	window->clear();

	gameMap.display(window);
	player.display(window);		//afficher le player dans graphicEngine (et remettre un couloir dans son ancienne position)
	
	if (player.bulletToShoot)
		bullet.push_back(player.shoot());

	for (auto & element : bullet)
	{
		element.display(window);
	}

	displayUI();
	for (auto & element : ia)
	{
		element.display(window);
	}
}

// Called when the state is set to active
/*virtual*/ void GameStateGame::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateGame::onExit(void)
{

}

////////////////////////////////////// INPUT PLAYER ///////////////////////////////////
void GameStateGame::inputPlayer(Event *e)
{
	// Une touche est pressée ou maintenue
	if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED 
		|| e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING)
	{
		switch (e->input)
		{
			// Déplacement
			case Event::INPUT::KB_Z : 
			{
				player.tryToMove(Entity::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_Q:
			{
				player.tryToMove(Entity::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_S:
			{
				player.tryToMove(Entity::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_D:
			{
				player.tryToMove(Entity::MOVE_TYPE::M_RIGHT);
				break;
			}
			// Tir
			case Event::INPUT::KB_UP:
			{
				player.tryToShoot(Entity::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_DOWN:
			{
				player.tryToShoot(Entity::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_LEFT:
			{
				player.tryToShoot(Entity::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_RIGHT:
			{
				player.tryToShoot(Entity::MOVE_TYPE::M_RIGHT);
				break;
			}
			default:
			{
				break;
			}
		}
	}
	else if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_RELEASED)
	{
		switch (e->input)
		{
			// Déplacement
			case Event::INPUT::KB_Z:
			{
				player.stopMove(Entity::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_Q:
			{
				player.stopMove(Entity::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_S:
			{
				player.stopMove(Entity::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_D:
			{
				player.stopMove(Entity::MOVE_TYPE::M_RIGHT);
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void GameStateGame::displayUI()
{
	if (needRedrawUi)
	{
		for (unsigned int x = 0; x < Window::SCREEN_WIDTH; ++x)
		{
			window->changePixel(x, 0, '-', 0x03);
			window->changePixel(x, 1, '-', 0x03);
			window->changePixel(x, Window::UI_HEIGHT - 2, '=', 0x03);
			window->changePixel(x, Window::UI_HEIGHT - 1, '=', 0x03);
		}
		for (unsigned int y = 2; y < Window::UI_HEIGHT - 2; ++y)
		{
			window->changePixel(0, y, '|', 0x03);
			window->changePixel(Window::SCREEN_WIDTH - 1, y, '|', 0x03);
			window->changePixel(1, y, '|', 0x03);
			window->changePixel(Window::SCREEN_WIDTH - 2, y, '|', 0x03);
		}

		needRedrawUi = false;
	}

	Vector2 timerPosition = Vector2(50, 7);
	AlphabetDrawer::draw0(window, timerPosition);
	AlphabetDrawer::draw1(window, Vector2(timerPosition.x + 5, timerPosition.y));
	AlphabetDrawer::draw2(window, Vector2(timerPosition.x + 10, timerPosition.y));
	AlphabetDrawer::draw3(window, Vector2(timerPosition.x + 15, timerPosition.y));
	AlphabetDrawer::draw4(window, Vector2(timerPosition.x + 20, timerPosition.y));
	AlphabetDrawer::draw5(window, Vector2(timerPosition.x + 25, timerPosition.y));
	AlphabetDrawer::draw6(window, Vector2(timerPosition.x + 30, timerPosition.y));
	AlphabetDrawer::draw7(window, Vector2(timerPosition.x + 35, timerPosition.y));
	AlphabetDrawer::draw8(window, Vector2(timerPosition.x + 40, timerPosition.y));
	AlphabetDrawer::draw9(window, Vector2(timerPosition.x + 45, timerPosition.y));

	

	
}

bool GameStateGame::collision(Vector2 positionBox1, Vector2 dimensionBox1, Vector2 positionBox2, Vector2 dimensionBox2)
{
	return !(positionBox1.x >= positionBox2.x + dimensionBox2.x)
		&& !(positionBox1.x + dimensionBox1.x <= positionBox2.x)
		&& !(positionBox1.y >= positionBox2.y + dimensionBox2.y)
		&& !(positionBox1.y + dimensionBox1.y <= positionBox2.y);
}