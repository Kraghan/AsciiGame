#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(Window* wind)
{
	window = wind;												//créé un lien du graphic engine
	player = Player(Vector2(10, 10));							//créé un player, à la position 10,10
	gameMap = GameMap(Window::SCREEN_WIDTH,Window::SCREEN_HEIGHT);

	BorderInitializer borderInit = BorderInitializer();
	borderInit.initialize(&gameMap);
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	gameMap.update();
	
	//if (player.tryedToMove)								//le joueur a essayï¿½ de bouger
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

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStateGame::display()
{
	gameMap.display(window);
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
	// Une touche est pressée ou maintenue
	if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED 
		|| e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING)
	{
		switch (e->input)
		{
			// Déplacement
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

				break;
			}
			case Event::INPUT::KB_DOWN:
			{

				break;
			}
			case Event::INPUT::KB_LEFT:
			{

				break;
			}
			case Event::INPUT::KB_RIGHT:
			{

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
			// Tir
			case Event::INPUT::KB_UP:
			{

				break;
			}
			case Event::INPUT::KB_DOWN:
			{

				break;
			}
			case Event::INPUT::KB_LEFT:
			{

				break;
			}
			case Event::INPUT::KB_RIGHT:
			{

				break;
			}
		}
	}
}
