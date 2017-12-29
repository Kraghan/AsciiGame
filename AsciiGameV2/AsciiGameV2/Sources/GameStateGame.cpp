#include "../Headers/GameStateGame.h"
#include "../Headers/Debug.h"

bool GameStateGame::loadingScreenOn = false;

/*virtual*/ GameStateGame::~GameStateGame(void)
{
	// Nothing to do
}

// Used to initialize the state
/*virtual*/ void GameStateGame::init(void)
{
	window = Window::getInstance();

	player = Player(Vector2f(10, Window::UI_HEIGHT + 10), Vector2f(10, 10));
	cameraPosition = Vector2f(0, 0);
	level = 0;
	nextLevel();
}

void GameStateGame::nextLevel()
{
	level++;
	ScoreBlock::level = level;
	std::thread loading(GameStateGame::loadingScreen);
	map = GameMap(Vector2ui(Window::SCREEN_WIDTH * 2, (Window::SCREEN_HEIGHT - Window::UI_HEIGHT) * 2));
	Initializer::initializeCave(&map);
	Initializer::initializeBorder(&map);
	Initializer::initializePickUp(&map);
	animationUpdatedDecreaseScore = true;

	GameStateGame::loadingScreenOn = false;
	loading.join();
	timer.start();
	timeElapsedBeforeNextLevel = 0;
}

// Update the game logic
/*virtual*/ void GameStateGame::update()
{
	if (ScoreBlock::nbBlock == 0)
	{
		if (timeElapsedBeforeNextLevel > timeBeforeNextLevel)
		{
			nextLevel();
		}
		if (timeElapsed < 0)
		{
			timeElapsedBeforeNextLevel += timer.getElapsedSeconds(true);
		}
		return;
	}

	timeElapsed += timer.getElapsedSeconds(true);

	// Check Collisions
	// Firsts bullets
	std::vector<Bullet> bull = player.getBullets();
	bullets.insert(bullets.end(), bull.begin(), bull.end());
	player.clearBullets();
	if (bullets.size() != 0)
	{
		for (int i = 0; i < bullets.size();)
		{
			Bullet* bullet = &bullets[i];
			AABBf bulletNextBounds = AABBf(bullet->getNextPosition(), bullet->getDimension() - Vector2f(1, 1));
			std::vector<Block*> blocks = map.getBlocks(bullet->getNextPosition() - Vector2f(4, 4), bullet->getDimension() + Vector2f(8, 8));
			bool collision = false;
			for (std::vector<Block*>::iterator it2 = blocks.begin(); it2 != blocks.end(); ++it2)
			{
				Block* block = *it2;
				if (block->getBounds().intersect(bulletNextBounds))
				{
					collision = true;
					map.explode(block->getPosition() + (block->getDimension() / 2u), player.getWeapon()->getRadius());
					bullets.erase(bullets.begin() + i);
					break;
				}
			}
			if (!collision)
			{
				bullet->update();
				++i;
			}
		}
	}

	// Player
	// Slightly change the position and the dimension to get more blocks
	AABBf playerNextBounds = AABBf(player.getNextPosition(), player.getDimension() - Vector2f(1,1));
	std::vector<Block*> blocks = map.getBlocks(player.getNextPosition() - Vector2f(4,4), player.getDimension() + Vector2f(8,8));
	for (std::vector<Block*>::iterator it = blocks.begin(); it != blocks.end(); ++it)
	{
		Block* block = *it;

		if (block->getBounds().intersect(playerNextBounds))
		{
			if (!block->solid())
			{
				block->collect(&player);
				map.removeBlock(block);
			}
			else
			{
				player.askToMove(MoveDirection::NONE);
			}
		}
	}

	map.update();
	player.update();
}

// Process the input
/*virtual*/ bool GameStateGame::processInput(void)
{
	Event* e = window->popEvent();
	while (e != nullptr)
	{
		if (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING)
		{
			switch (e->input)
			{
				case Event::INPUT::KB_ESCAPE:
					stateMachine->activeState("pause",true);
					break;
				case Event::INPUT::KB_Z:
					player.askToMove(MoveDirection::UP);
					break;
				case Event::INPUT::KB_S:
					player.askToMove(MoveDirection::DOWN);
					break;
				case Event::INPUT::KB_D:
					player.askToMove(MoveDirection::RIGHT);
					break;
				case Event::INPUT::KB_Q:
					player.askToMove(MoveDirection::LEFT);
					break;
				case Event::INPUT::KB_UP:
					player.askToShoot(MoveDirection::UP);
					break;
				case Event::INPUT::KB_DOWN:
					player.askToShoot(MoveDirection::DOWN);
					break;
				case Event::INPUT::KB_RIGHT:
					player.askToShoot(MoveDirection::RIGHT);
					break;
				case Event::INPUT::KB_LEFT:
					player.askToShoot(MoveDirection::LEFT);
					break;
			}
		}

		e = window->popEvent();
	}
	return true;
}

/*virtual*/ void GameStateGame::display()
{
	// Exception pour animation
	if (ScoreBlock::nbBlock == 0)
	{
		if (animationUpdatedDecreaseScore && timeElapsed >= 0)
		{
			timeElapsed--;
			player.addScore(-level);
			if (timeElapsed < 0)
				timer.start();
		}
		animationUpdatedDecreaseScore = !animationUpdatedDecreaseScore;
	}

	window->clear();

	Vector2f playerPositionOnScreen = player.getPosition() - cameraPosition;

	
	// Déplace la caméra sur la gauche 
	if (playerPositionOnScreen.x < Window::SCREEN_WIDTH / 2 - 50)
	{
		cameraPosition.x -= ((Window::SCREEN_WIDTH / 2 - 50) - playerPositionOnScreen.x);
	}
	// Déplace la caméra sur la droite
	else if (playerPositionOnScreen.x + player.getDimension().x > Window::SCREEN_WIDTH / 2 + 50)
	{
		cameraPosition.x += (playerPositionOnScreen.x + player.getDimension().x - (Window::SCREEN_WIDTH / 2 + 50));
		//cameraPosition.x = player.bounds.position.
	}

	// Bloque la position côté gauche
	if (cameraPosition.x < 0)
	{
		cameraPosition.x = 0;
	}
	// Bloque la position côté droit
	else if (cameraPosition.x > map.getDimension().x - Window::SCREEN_WIDTH)
	{
		cameraPosition.x = map.getDimension().x - Window::SCREEN_WIDTH;
	}

	
	if (playerPositionOnScreen.y < (Window::UI_HEIGHT + Window::SCREEN_HEIGHT / 2) - 50)
		cameraPosition.y -= ((Window::UI_HEIGHT + Window::SCREEN_HEIGHT / 2) - 50) - playerPositionOnScreen.y;
	else if (playerPositionOnScreen.y >(Window::UI_HEIGHT + Window::SCREEN_HEIGHT / 2) + 50)
		cameraPosition.y += playerPositionOnScreen.y - ((Window::UI_HEIGHT + Window::SCREEN_HEIGHT / 2) + 50);

	if (cameraPosition.y < 0)
		cameraPosition.y = 0;
	else if (cameraPosition.y > map.getDimension().y - (Window::SCREEN_HEIGHT - Window::UI_HEIGHT))
		cameraPosition.y = map.getDimension().y - (Window::SCREEN_HEIGHT - Window::UI_HEIGHT);

	map.display(cameraPosition);

	for (int i = 0; i < bullets.size(); ++i)
		bullets[i].display(cameraPosition);

	player.display(cameraPosition);
	displayUI();
}

void GameStateGame::displayUI()
{
	window->clear(Vector2ui(0, 0), Vector2ui(Window::SCREEN_WIDTH, Window::UI_HEIGHT));
	for (unsigned int x = 0; x < Window::SCREEN_WIDTH; ++x)
	{
		window->drawChar(x, 0, '-', 0x03);
		window->drawChar(x, 1, '-', 0x03);
		window->drawChar(x, Window::UI_HEIGHT - 2, '=', 0x03);
		window->drawChar(x, Window::UI_HEIGHT - 1, '=', 0x03);
	}
	for (unsigned int y = 2; y < Window::UI_HEIGHT - 2; ++y)
	{
		window->drawChar(0, y, '|', 0x03);
		window->drawChar(Window::SCREEN_WIDTH - 1, y, '|', 0x03);
		window->drawChar(1, y, '|', 0x03);
		window->drawChar(Window::SCREEN_WIDTH - 2, y, '|', 0x03);
	}

	Vector2ui scorePosition = Vector2ui(10, 10);
	AlphabetDrawer::drawWord(Vector2ui(10, 10), "SCORE:");

	std::string score = std::to_string(player.getScore());
	for (unsigned int i = 10; i < 100000000; i *= 10)
		if (player.getScore() < i)
			score = "0" + score;



	AlphabetDrawer::drawWord(Vector2ui(40, 10), score + "  " + std::to_string(ScoreBlock::nbBlock));

	Vector2ui LifePosition = Vector2ui(110, 10);
	AlphabetDrawer::drawWord(LifePosition, "LIFE:");

	int lifePoint = player.getLife();
	for (unsigned int i = 0; i < 5; ++i)
	{
		lifePoint -= 2;
		if (lifePoint < 0)
		{
			if (lifePoint == -1)
				AlphabetDrawer::drawHalfHeart(Vector2ui(LifePosition.x + 22 + 15 * i, LifePosition.y - 4));
			else
				AlphabetDrawer::drawHeart(Vector2ui(LifePosition.x + 22 + 15 * i, LifePosition.y - 4), 1, 'X', true);
		}
		else
			AlphabetDrawer::drawHeart(Vector2ui(LifePosition.x + 22 + 15 * i, LifePosition.y - 4));
	}

	Vector2ui AmmoPosition = Vector2ui(210, 10);
	AlphabetDrawer::drawWord(AmmoPosition, "AMMO:");

	for (unsigned int i = 0; i < player.getAmmo(); ++i)
		AlphabetDrawer::drawAmmo(Vector2ui(AmmoPosition.x + 25 + 6 * i, AmmoPosition.y - 4));

	AlphabetDrawer::drawWord(Vector2ui(310, 10), "TIME:");
	int minute = (int)timeElapsed / 60;
	int seconde = (int)timeElapsed % 60;
	AlphabetDrawer::drawWord(Vector2ui(332, 10), (minute < 10 ? "0" : "") + std::to_string(minute) + ":" + (seconde < 10 ? "0" : "") + std::to_string(seconde));
}

// Called when the state is set to active
/*virtual*/ void GameStateGame::onEnter(void)
{

}

// Called when the state is set to inactive
/*virtual*/ void GameStateGame::onExit(void)
{

}

void GameStateGame::loadingScreen()
{
	Window* window = Window::getInstance();

	GameStateGame::loadingScreenOn = true;
	Timer timer = Timer();
	timer.start();
	double previous = timer.getElapsedSeconds();
	double lag = 0.0;

	int stateLoading = 0;
	bool running = true;
	double animationElapsed = 0.0;
	while (running)
	{
		// Time elapsed calculation since the last loop
		double current = timer.getElapsedSeconds();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		Event* e = window->popEvent();
		while (e != nullptr)
		{
			if (!GameStateGame::loadingScreenOn &&
				(e->input == Event::INPUT::KB_ENTER || e->input == Event::INPUT::KB_SPACE)
				&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
			{
				running = false;
			}
			e = window->popEvent();
		}


		// Lag compensation + FPS limitation
		while (lag >= Timer::SECONDS_PER_UPDATE)
		{
			window->update();

			animationElapsed += Timer::SECONDS_PER_UPDATE;

			if (animationElapsed >= 1.0 / 5.0)
			{
				stateLoading++;
				if (stateLoading == 4)
					stateLoading = 0;
				animationElapsed = 0.0;
			}

			lag -= Timer::SECONDS_PER_UPDATE;
		}

		window->clear();
		switch (stateLoading)
		{
		case 0:
			AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 80, Window::SCREEN_HEIGHT / 2 - 20), "Loading", 4, 'X', 0x0A);
			break;
		case 1:
			AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 80, Window::SCREEN_HEIGHT / 2 - 20), "Loading.", 4, 'X', 0x0A);
			break;
		case 2:
			AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 80, Window::SCREEN_HEIGHT / 2 - 20), "Loading..", 4, 'X', 0x0A);
			break;
		case 3:
			AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 - 80, Window::SCREEN_HEIGHT / 2 - 20), "Loading...", 4, 'X', 0x0A);
			break;
		}

		if (!GameStateGame::loadingScreenOn)
			AlphabetDrawer::drawWord(Vector2ui(40, Window::SCREEN_HEIGHT - 30), "Press enter or space to continue", 2);
		window->display();
	}
}

void GameStateGame::setPlayerWeapon(Weapon* weapon)
{
	player.setWeapon(weapon);
}