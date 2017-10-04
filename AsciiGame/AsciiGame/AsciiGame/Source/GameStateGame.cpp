#include "../Header/GameStateGame.h"

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(GraphicEngine* e)
{
	engine = e;													//créé un lien du graphic engine
	player = Player(Vector2(10, 10));							//créé un player, à la position 10,10
	engine->displayPlayer(Vector2(10, 10));						//afficher le player
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	//engine->changeRandomPixel();
	if (player.tryedToMove)								//le joueur a essayé de bouger
	{
		//si les colisions sont ok, bouger le joueur
		//{
			//afficher le player dans graphicEngine (et remettre un couloir dans son ancienne position)
			engine->displayPlayer(Vector2(player.pos.x, player.pos.y), Vector2(player.pos.x + player.addHoriz, player.pos.y + player.addVerti));
			player.update();		//ici actualise les nouvelles positions du joueur
		//}
		//else						//sinon, reset les add/verti du player pour ne pas qu'il bouge !
		//{
			//player.addHoriz = 0;
			//player.addVerti = 0;
		//}
		player.tryedToMove = false;
	}

}

// Process the input
/*virtual*/ bool GameStateGame::processInput(void)
{
	Event* e = engine->popEvent();
	while (e != nullptr)
	{
		if (e->input == Event::INPUT::KB_ESCAPE 
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			stateMachine->activeState("pause");
		}

		inputPlayer(e);											//input du joueur in-game

		e = engine->popEvent();
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

////////////////////////////////////// INPUT PLAYER ///////////////////////////////////
void GameStateGame::inputPlayer(Event *e)
{
	//UP OU DOWN, mais pas les 2
	if (e->input == Event::INPUT::KB_UP
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING) )
	{
		player.tryToMove(Player::MOVE_TYPE::M_UP);
	}
	else if (e->input == Event::INPUT::KB_DOWN
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_DOWN);
	}

	//RIGHT OU LEFT, mais pas les deux
	if (e->input == Event::INPUT::KB_RIGHT
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_RIGHT);
	}
	else if (e->input == Event::INPUT::KB_LEFT
		&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
	{
		player.tryToMove(Player::MOVE_TYPE::M_LEFT);
	}
}