#include "../Header/GameStateGame.h"
#include "../Header/Debug.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(Window* wind)
{
	window = wind;																	//créé un lien du graphic engine
	player = Player(Vector2(10, Window::UI_HEIGHT + 10));							//créé un player, à la position 10,10
	
	gameMap.clear();
	gameMap = GameMap(Window::SCREEN_WIDTH / 4,(Window::SCREEN_HEIGHT - Window::UI_HEIGHT) / 4);

	Initializer::initializeBorder(&gameMap);
	Initializer::initializeCave(&gameMap);
	Initializer::initializeCollectible(&gameMap, 10, 10, 10);

	window->clear();
	needRedrawUi = true;
	timeElapsed = 0.0;
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	timeElapsed += Timer::SECONDS_PER_UPDATE;
	gameMap.update();

	Vector2 playerNextPos = Vector2(player.bounds.position.x + player.addHoriz * player.speed, player.bounds.position.y + player.addVerti * player.speed);
	std::vector<Block*> blocks = gameMap.getBlocks();

	if (player.canShoot())
		bullet.push_back(player.shoot());
	else
		player.bulletToShoot = false;

	// Si les deux angles (haut gauche et bas droit) du joueur sont dans les limites du jeu
	if (gameMap.isInBound(playerNextPos) 
		&& gameMap.isInBound(Vector2(playerNextPos.x + player.bounds.dimension.x, playerNextPos.y + player.bounds.dimension.y)))
	{
		bool wallCollisionOk = true;

		// On check pour tous les blocks si on a une collision
		// La meilleure opti à envisager serai la quad map
		//Debug::log("Debug2.txt","");
		for (unsigned int i = 0; i < blocks.size(); ++i)
		{
			//Debug::log("Debug2.txt", std::to_string(blocks[i]->getIsSolid())+"\n",true);
			Vector2 blockPos = blocks[i]->getPosition();
			Vector2 blockDim = blocks[i]->getDimension();
			blockPos.x *= 4;
			blockPos.y *= 4;
			blockPos.y += Window::UI_HEIGHT;
			
			if (collision(playerNextPos,player.bounds.dimension,blockPos, blockDim))
			{
				if (blocks[i]->getIsSolid())
				{
					wallCollisionOk = false;
					break;
				}

				if (blocks[i]->getIsCollectable())
				{
					blocks[i]->collect(&player);
					gameMap.destroyBlock(blocks[i]->getPosition());
				}
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
		Vector2 bulletNextPos = Vector2((*it).bounds.position.x + (*it).addHoriz * (*it).speed, (*it).bounds.position.y + (*it).addVerti * (*it).speed);
		bool collide = false;
		for (unsigned int i = 0; i < blocks.size(); ++i)
		{
			if (!blocks[i]->getIsSolid())
				continue;
			Vector2 blockPos = blocks[i]->getPosition();
			Vector2 blockDim = blocks[i]->getDimension();
			blockPos.x *= 4;
			blockPos.y *= 4;
			blockPos.y += Window::UI_HEIGHT;

			if (collision(blockPos, blockDim, bulletNextPos,(*it).bounds.dimension))
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
			gameMap.explode(bulletNextPos,12);
		}

	}

	for (auto & element : ia)
	{
		element.update();
	}

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
			stateMachine->activeState("pause", true);
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

	Vector2 scorePosition = Vector2(10, 10);
	AlphabetDrawer::drawWord(window, Vector2(10, 10), "SCORE:");
	
	std::string score = std::to_string(player.score);
	for(unsigned int i = 10; i < 100000000; i*=10)
		if (player.score < i)
			score = "0" + score;

	AlphabetDrawer::drawWord(window, Vector2(40, 10), score);

	Vector2 LifePosition = Vector2(110, 10);
	AlphabetDrawer::drawWord(window, LifePosition, "LIFE:");

	int lifePoint = player.lifePoint;
	for (unsigned int i = 0; i < 5; ++i)
	{
		lifePoint -= 2;
		if (lifePoint < 0)
		{
			if(lifePoint == -1)
				AlphabetDrawer::drawHalfHeart(window, Vector2(LifePosition.x + 22 + 15 * i, LifePosition.y - 4));
			else
				AlphabetDrawer::drawHeart(window, Vector2(LifePosition.x + 22 + 15 * i, LifePosition.y - 4),1,'X',true);
		}
		else
			AlphabetDrawer::drawHeart(window, Vector2(LifePosition.x + 22 + 15 * i, LifePosition.y - 4));
	}

	Vector2 AmmoPosition = Vector2(210, 10);
	AlphabetDrawer::drawWord(window, AmmoPosition, "AMMO:");

	for (unsigned int i = 0; i < player.ammunition; ++i)
		AlphabetDrawer::drawAmmo(window, Vector2(AmmoPosition.x + 25 + 6 * i, AmmoPosition.y - 4));

	AlphabetDrawer::drawWord(window, Vector2(310, 10), "TIME:");
	int minute = (int)timeElapsed / 60;
	int seconde = (int)timeElapsed % 60;
	AlphabetDrawer::drawWord(window, Vector2(332, 10), (minute < 10 ? "0" : "" ) + std::to_string(minute)+":"+ (seconde < 10 ? "0" : "") + std::to_string(seconde));
}

bool GameStateGame::collision(Vector2 positionBox1, Vector2 dimensionBox1, Vector2 positionBox2, Vector2 dimensionBox2)
{
	return !(positionBox1.x >= positionBox2.x + dimensionBox2.x)
		&& !(positionBox1.x + dimensionBox1.x <= positionBox2.x)
		&& !(positionBox1.y >= positionBox2.y + dimensionBox2.y)
		&& !(positionBox1.y + dimensionBox1.y <= positionBox2.y);
}