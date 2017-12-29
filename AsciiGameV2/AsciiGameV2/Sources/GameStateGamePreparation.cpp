#include "../Headers/GameStateGamePreparation.h"

/*virtual*/ GameStateGamePreparation::~GameStateGamePreparation(void)
{

}

/*virtual*/ void GameStateGamePreparation::init(void)
{
	window = Window::getInstance();
	player = Player(Vector2f(Window::SCREEN_WIDTH / 2 + 30, Window::SCREEN_HEIGHT / 4 ), Vector2f(10,10));
	map = GameMap(Vector2ui(Window::MAX_WIDTH, Window::MAX_HEIGHT));
	Initializer::initializeBorderPreparation(&map);
	Initializer::initializePreparationWall(&map);
	nextWeapon = false;
	previousWeapon = false;
	weaponChanged = false;

	timeElapsed = 0.0f;
	timeElapsedBeforeCompleteReset = 0.0f;
	weapons.clear();
	weapons.push_back(new BombThrower());
	weapons.push_back(new Shotgun());
	weapons.push_back(new Laser());
	weaponIndex = 0;
}

/*virtual*/ void GameStateGamePreparation::update()
{
	// Menu update
	timeElapsedBeforeCompleteReset += Timer::SECONDS_PER_UPDATE;
	timeElapsed += Timer::SECONDS_PER_UPDATE;
	if (timeElapsed >= timeBeforeReset)
	{
		previousWeapon = false;
		nextWeapon = false;
		weaponChanged = false;
	}

	if (previousWeapon && !weaponChanged)
	{
		AudioHelper::getAudioHelper()->play("navigationMenu");
		weaponIndex--;
		if (weaponIndex < 0)
			weaponIndex = weapons.size() - 1;
		weaponChanged = true;
	}
	else if (nextWeapon && !weaponChanged)
	{
		AudioHelper::getAudioHelper()->play("navigationMenu");
		weaponIndex++;
		if ((unsigned int)weaponIndex >= weapons.size())
			weaponIndex = 0;
		weaponChanged = true;
	}
	if (weaponChanged)
	{
		Initializer::initializePreparationWall(&map);
		timeElapsedBeforeCompleteReset = 0.0;
		bullet.clear();
	}
	// End Menu Update

	// Animation Update
	if (player.getPosition().y <= 30)
		playerUp = false;

	if (player.getPosition().y >= 90)
		playerUp = true;

	if (playerUp)
		player.askToMove(MoveDirection::UP);
	else
		player.askToMove(MoveDirection::DOWN);

	player.askToShoot(MoveDirection::RIGHT);

	player.update();

	if (timeElapsedBeforeCompleteReset >= timeBeforeCompleteReset)
	{
		Initializer::initializePreparationWall(&map);
		timeElapsedBeforeCompleteReset = 0.0;
	}

	std::vector<Bullet> vec = player.getBullets();
	bullet.insert(bullet.end(), vec.begin(), vec.end());
	player.clearBullets();

	if (player.getAmmo() < 10)
		player.addAmmo(1);

	if (bullet.size() != 0)
	{
		for (int i = 0; i < bullet.size();)
		{
			Bullet* bull = &bullet[i];
			AABBf bulletNextBounds = AABBf(bull->getNextPosition(), bull->getDimension() - Vector2f(1, 1));
			std::vector<Block*> blocks = map.getBlocks(bull->getNextPosition() - Vector2f(4, 4), bull->getDimension() + Vector2f(8, 8));
			bool collision = false;
			for (std::vector<Block*>::iterator it2 = blocks.begin(); it2 != blocks.end(); ++it2)
			{
				Block* block = *it2;
				if (block->getBounds().intersect(bulletNextBounds))
				{
					collision = true;
					map.explode(block->getPosition() + (block->getDimension() / 2u), player.getWeapon()->getRadius());
					bullet.erase(bullet.begin() + i);
					break;
				}
			}
			if (!collision)
			{
				bull->update();
				++i;
			}
		}
	}

	// End animation update

	if (weaponChanged)
		player.setWeapon(weapons[weaponIndex]);
}	

/*virtual*/ bool GameStateGamePreparation::processInput(void)
{
	Event* e = window->popEvent();

	while (e != nullptr)
	{
		// Return to main menu
		if (e->input == Event::INPUT::KB_ESCAPE
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			stateMachine->activeState("menu", true);
		}

		// Launch game
		if ((e->input == Event::INPUT::KB_SPACE || e->input == Event::INPUT::KB_ENTER)
			&& e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED)
		{
			stateMachine->activeState("game", true);
			GameStateGame* state = (GameStateGame*)stateMachine->getActiveState();
			state->setPlayerWeapon(weapons[weaponIndex]);
		}

		// Change weapon
		if ((e->input == Event::INPUT::KB_LEFT || e->input == Event::INPUT::KB_Q)
			&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
		{
			timeElapsed = 0.0;
			previousWeapon = true;
			nextWeapon = false;
		}
		else if ((e->input == Event::INPUT::KB_RIGHT || e->input == Event::INPUT::KB_D)
			&& (e->typeInput == Event::TYPE_INPUT_EVENT::TI_PRESSED || e->typeInput == Event::TYPE_INPUT_EVENT::TI_HOLDING))
		{
			timeElapsed = 0.0;
			nextWeapon = true;
			previousWeapon = false;
		}

		e = window->popEvent();
	}

	//player.tryToShoot(Entity::MOVE_TYPE::M_RIGHT);

	return true;
}

/*virtual*/ void GameStateGamePreparation::display()
{
	window->clear();
	// Border
	for (unsigned int x = 0; x < Window::SCREEN_WIDTH; ++x)
	{
		window->drawChar(x, 0, 'X', borderColor);
		window->drawChar(x, 1, 'X', borderColor);
		window->drawChar(x, 2, 'X', borderColor);
		window->drawChar(x, 3, 'X', borderColor);

		window->drawChar(x, Window::SCREEN_HEIGHT - 1, 'X', borderColor);
		window->drawChar(x, Window::SCREEN_HEIGHT - 2, 'X', borderColor);
		window->drawChar(x, Window::SCREEN_HEIGHT - 3, 'X', borderColor);
		window->drawChar(x, Window::SCREEN_HEIGHT - 4, 'X', borderColor);
	}
	for (unsigned int y = 4; y < Window::SCREEN_HEIGHT; ++y)
	{
		window->drawChar(0, y, 'X', borderColor);
		window->drawChar(1, y, 'X', borderColor);
		window->drawChar(2, y, 'X', borderColor);
		window->drawChar(3, y, 'X', borderColor);

		window->drawChar(Window::SCREEN_WIDTH - 1, y, 'X', borderColor);
		window->drawChar(Window::SCREEN_WIDTH - 2, y, 'X', borderColor);
		window->drawChar(Window::SCREEN_WIDTH - 3, y, 'X', borderColor);
		window->drawChar(Window::SCREEN_WIDTH - 4, y, 'X', borderColor);
	}
	// End border

	// Border visualization
	for (unsigned int x = 0; x < (Window::SCREEN_WIDTH / 2 - 20); ++x)
	{
		unsigned int xx = Window::SCREEN_WIDTH / 2 + 10 + x;
		window->drawChar(xx, 20, 'X', borderVisualizationColor);
		window->drawChar(xx, 21, 'X', borderVisualizationColor);
		window->drawChar(xx, 22, 'X', borderVisualizationColor);
		window->drawChar(xx, 23, 'X', borderVisualizationColor);

		window->drawChar(xx, Window::SCREEN_HEIGHT / 2 - 11, 'X', borderVisualizationColor);
		window->drawChar(xx, Window::SCREEN_HEIGHT / 2 - 12, 'X', borderVisualizationColor);
		window->drawChar(xx, Window::SCREEN_HEIGHT / 2 - 13, 'X', borderVisualizationColor);
		window->drawChar(xx, Window::SCREEN_HEIGHT / 2 - 14, 'X', borderVisualizationColor);
	}
	for (unsigned int y = 0; y < (Window::SCREEN_HEIGHT / 2 - 30); ++y)
	{
		unsigned int yy = y + 20;
		window->drawChar(Window::SCREEN_WIDTH / 2 + 10, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH / 2 + 11, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH / 2 + 12, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH / 2 + 13, yy, 'X', borderVisualizationColor);

		window->drawChar(Window::SCREEN_WIDTH - 11, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH - 12, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH - 13, yy, 'X', borderVisualizationColor);
		window->drawChar(Window::SCREEN_WIDTH - 14, yy, 'X', borderVisualizationColor);
	}
	// End border visualization

	// Arrows
	for (unsigned int x = 0; x < 6; ++x)
	{
		unsigned xx = x * 2 + 1;

		for (unsigned int y = 0; y < xx; ++y)
		{
			window->drawChar(Window::SCREEN_WIDTH / 2 + 30 + x, Window::SCREEN_HEIGHT / 2 - (x - y), 'X', previousWeapon ? arrowColorPressed : arrowColor);
			window->drawChar(Window::SCREEN_WIDTH - 31 - x, Window::SCREEN_HEIGHT / 2 - (x - y), 'X', nextWeapon ? arrowColorPressed : arrowColor);
		}
	}
	// End arrows

	// Texts

	// Weapon
	std::string weaponName = weapons[weaponIndex]->getName();
	if (weaponName.size() != 24)
	{
		if (weaponName.size() % 2 != 0)
			weaponName = ' ' + weaponName;

		for (unsigned int i = 0; i < (24 - weaponName.size()) / 2 + 3; ++i)
			weaponName = ' ' + weaponName;
	}
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 40, Window::SCREEN_HEIGHT / 2 - 2), weaponName);
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 30, Window::SCREEN_HEIGHT / 2 + 20), "Weapon trait", 2, 'X', borderVisualizationColor + 0x08);
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 35), "Fire rate");

	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 35), std::to_string((int)(1.0f / weapons[weaponIndex]->getTimeBetweenShoot())));
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 45), "Blast radius");
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 45), std::to_string(weapons[weaponIndex]->getRadius()));
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 55), "Bullets per shots");
	AlphabetDrawer::drawWord(Vector2ui(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 55), std::to_string(weapons[weaponIndex]->getBulletPerShot()));
	// End weapon

	AlphabetDrawer::drawWord(Vector2ui(10, Window::SCREEN_HEIGHT - 40), "press q-left or d-right to change weapon");
	AlphabetDrawer::drawWord(Vector2ui(10, Window::SCREEN_HEIGHT - 30), "press enter or space to play");
	AlphabetDrawer::drawWord(Vector2ui(10, Window::SCREEN_HEIGHT - 20), "press echap to cancel");
	// End Texts

	map.display(Vector2f(0,0));
	player.display(Vector2f(0, 0));
	for (auto & element : bullet)
	{
		element.display(Vector2f(0, 0));
	}
}

/*virtual*/ void GameStateGamePreparation::onEnter(void)
{
	
}

/*virtual*/ void GameStateGamePreparation::onExit(void)
{

}