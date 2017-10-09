#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(Window* wind)
{
	window = wind;																	//cr�� un lien du graphic engine
	player = Player(Vector2(10, Window::UI_HEIGHT + 10));							//cr�� un player, � la position 10,10
	gameMap = GameMap(Window::SCREEN_WIDTH,Window::SCREEN_HEIGHT - Window::UI_HEIGHT);

	BorderInitializer borderInit = BorderInitializer();
	borderInit.initialize(&gameMap);
	CaveSeedInitializer caveInit = CaveSeedInitializer();
	caveInit.initialize(&gameMap);
	window->clear();
	needRedrawUi = true;
	timeElapsed = 0.0;
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	timeElapsed += Timer::SECONDS_PER_UPDATE;
	gameMap.update();

	//si les colisions sont ok, bouger le joueur
	//{
		player.update();		//ici actualise les nouvelles positions du joueur
	//}
	//else						//sinon, reset les add/verti du player pour ne pas qu'il bouge !
	//{
	//player.addHoriz = 0;
	//player.addVerti = 0;
	//}
	
	for (auto & element : bullet)
	{
		element.update();
	}

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

/*virtual*/ void GameStateGame::display()
{
	//window->clear();

	gameMap.display(window);
	//si les colisions sont ok, bouger le joueur
	//{
	player.display(window);		//afficher le player dans graphicEngine (et remettre un couloir dans son ancienne position)
	//}
	//else						//sinon, reset les add/verti du player pour ne pas qu'il bouge !
	//{
	//player.addHoriz = 0;
	//player.addVerti = 0;
	//}
	if (player.bulletToShoot)
		bullet.push_back(player.shoot());

	for (auto & element : bullet)
	{
		element.display(window);
	}

	displayUI();
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
	// Une touche est press�e ou maintenue
	if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED 
		|| e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING)
	{
		switch (e->input)
		{
			// D�placement
			case Event::INPUT::KB_Z : 
			{
				player.tryToMove(Player::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_Q:
			{
				player.tryToMove(Player::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_S:
			{
				player.tryToMove(Player::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_D:
			{
				player.tryToMove(Player::MOVE_TYPE::M_RIGHT);
				break;
			}
			// Tir
			case Event::INPUT::KB_UP:
			{
				player.tryToShoot(Player::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_DOWN:
			{
				player.tryToShoot(Player::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_LEFT:
			{
				player.tryToShoot(Player::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_RIGHT:
			{
				player.tryToShoot(Player::MOVE_TYPE::M_RIGHT);
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
			// D�placement
			case Event::INPUT::KB_Z:
			{
				player.stopMove(Player::MOVE_TYPE::M_UP);
				break;
			}
			case Event::INPUT::KB_Q:
			{
				player.stopMove(Player::MOVE_TYPE::M_LEFT);
				break;
			}
			case Event::INPUT::KB_S:
			{
				player.stopMove(Player::MOVE_TYPE::M_DOWN);
				break;
			}
			case Event::INPUT::KB_D:
			{
				player.stopMove(Player::MOVE_TYPE::M_RIGHT);
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