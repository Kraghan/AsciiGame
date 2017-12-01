#include "../Header/GameStateGamePreparation.h"

/*virtual*/ GameStateGamePreparation::~GameStateGamePreparation(void)
{

}

/*virtual*/ void GameStateGamePreparation::init(Window* wind)
{
	window = wind;
	player = Player(Vector2(Window::SCREEN_WIDTH / 2 + 30, Window::SCREEN_HEIGHT / 4 ));
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
		if (weaponIndex >= weapons.size())
			weaponIndex = 0;
		weaponChanged = true;
	}
	if (weaponChanged)
	{
		Initializer::initializePreparationWall(&gameMap);
		gameMap.updateQuadTree();
		timeElapsedBeforeCompleteReset = 0.0;
		bullet.clear();
	}
	// End Menu Update

	// Animation Update
	if (player.bounds.position.y <= playerYLimitTop)
		playerUp = false;

	if (player.bounds.position.y >= playerYLimitBottom)
		playerUp = true;

	if (playerUp)
		player.tryToMove(Entity::MOVE_TYPE::M_UP);
	else
		player.tryToMove(Entity::MOVE_TYPE::M_DOWN);

	player.update();

	if (timeElapsedBeforeCompleteReset >= timeBeforeCompleteReset)
	{
		Initializer::initializePreparationWall(&gameMap);
		gameMap.updateQuadTree();
		timeElapsedBeforeCompleteReset = 0.0;
	}
	
	//std::vector<Block*> blocks = gameMap.getBlocks();

	if (player.canShoot())
	{
		std::vector<Bullet> vec = player.shoot();
		bullet.insert(bullet.end(), vec.begin(), vec.end());
		player.addAmmo(1);
	}
	else
		player.bulletToShoot = false;

	for (std::vector<Bullet>::iterator it = bullet.begin(); it != bullet.end();)
	{
		Vector2 bulletNextPos = Vector2((*it).bounds.position.x + (*it).addHoriz * (*it).speed, (*it).bounds.position.y + (*it).addVerti * (*it).speed);
		bool collide = false;

		std::vector<Block*> blocks = gameMap.getBlocks(AABB(bulletNextPos,(*it).bounds.dimension));
		for (unsigned int i = 0; i < blocks.size(); ++i)
		{
			if (!blocks[i]->getIsSolid())
				continue;
			Vector2 blockPos = blocks[i]->getPosition();
			Vector2 blockDim = blocks[i]->getDimension();
			blockPos.x *= 4;
			blockPos.y *= 4;
			blockPos.y += Window::UI_HEIGHT;

			if (collision(blockPos, blockDim, bulletNextPos, (*it).bounds.dimension))
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
			gameMap.explode(bulletNextPos, player.getWeapon()->getRadius());
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

	player.tryToShoot(Entity::MOVE_TYPE::M_RIGHT);

	return true;
}

/*virtual*/ void GameStateGamePreparation::display()
{
	window->clear();
	// Border
	for (unsigned int x = 0; x < Window::SCREEN_WIDTH; ++x)
	{
		window->changePixel(x, 0, 'X', borderColor);
		window->changePixel(x, 1, 'X', borderColor);
		window->changePixel(x, 2, 'X', borderColor);
		window->changePixel(x, 3, 'X', borderColor);

		window->changePixel(x, Window::SCREEN_HEIGHT - 1, 'X', borderColor);
		window->changePixel(x, Window::SCREEN_HEIGHT - 2, 'X', borderColor);
		window->changePixel(x, Window::SCREEN_HEIGHT - 3, 'X', borderColor);
		window->changePixel(x, Window::SCREEN_HEIGHT - 4, 'X', borderColor);
	}
	for (unsigned int y = 4; y < Window::SCREEN_HEIGHT; ++y)
	{
		window->changePixel(0, y, 'X', borderColor);
		window->changePixel(1, y, 'X', borderColor);
		window->changePixel(2, y, 'X', borderColor);
		window->changePixel(3, y, 'X', borderColor);

		window->changePixel(Window::SCREEN_WIDTH - 1, y, 'X', borderColor);
		window->changePixel(Window::SCREEN_WIDTH - 2, y, 'X', borderColor);
		window->changePixel(Window::SCREEN_WIDTH - 3, y, 'X', borderColor);
		window->changePixel(Window::SCREEN_WIDTH - 4, y, 'X', borderColor);
	}
	// End border

	// Border visualization
	for (unsigned int x = 0; x < (Window::SCREEN_WIDTH / 2 - 20); ++x)
	{
		unsigned int xx = Window::SCREEN_WIDTH / 2 + 10 + x;
		window->changePixel(xx, 20, 'X', borderVisualizationColor);
		window->changePixel(xx, 21, 'X', borderVisualizationColor);
		window->changePixel(xx, 22, 'X', borderVisualizationColor);
		window->changePixel(xx, 23, 'X', borderVisualizationColor);

		window->changePixel(xx, Window::SCREEN_HEIGHT / 2 - 11, 'X', borderVisualizationColor);
		window->changePixel(xx, Window::SCREEN_HEIGHT / 2 - 12, 'X', borderVisualizationColor);
		window->changePixel(xx, Window::SCREEN_HEIGHT / 2 - 13, 'X', borderVisualizationColor);
		window->changePixel(xx, Window::SCREEN_HEIGHT / 2 - 14, 'X', borderVisualizationColor);
	}
	for (unsigned int y = 0; y < (Window::SCREEN_HEIGHT / 2 - 30); ++y)
	{
		unsigned int yy = y + 20;
		window->changePixel(Window::SCREEN_WIDTH / 2 + 10, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH / 2 + 11, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH / 2 + 12, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH / 2 + 13, yy, 'X', borderVisualizationColor);

		window->changePixel(Window::SCREEN_WIDTH - 11, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH - 12, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH - 13, yy, 'X', borderVisualizationColor);
		window->changePixel(Window::SCREEN_WIDTH - 14, yy, 'X', borderVisualizationColor);
	}
	// End border visualization

	// Arrows
	for (unsigned int x = 0; x < 6; ++x)
	{
		unsigned xx = x * 2 + 1;

		for (unsigned int y = 0; y < xx; ++y)
		{
			window->changePixel(Window::SCREEN_WIDTH / 2 + 30 + x, Window::SCREEN_HEIGHT / 2 - (x - y), 'X', previousWeapon ? arrowColorPressed : arrowColor);
			window->changePixel(Window::SCREEN_WIDTH - 31 - x, Window::SCREEN_HEIGHT / 2 - (x - y), 'X', nextWeapon ? arrowColorPressed : arrowColor);
		}
	}
	// End arrows

	// Texts

	// Weapon
	std::string weaponName = weapons[weaponIndex]->getName();
	if (weaponName.size() != 24)
	{
		if(weaponName.size() % 2 != 0)
			weaponName = ' ' + weaponName;

		for (int i = 0; i < (24 - weaponName.size()) / 2 + 3; ++i)
			weaponName = ' ' + weaponName;
	}
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 40, Window::SCREEN_HEIGHT / 2 - 2), weaponName);
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 30, Window::SCREEN_HEIGHT / 2 + 20), "Weapon trait",2,'X',borderVisualizationColor + 0x08);
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 35), "Fire rate");
	
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 35), std::to_string((int)(1.0f / weapons[weaponIndex]->getTimeBetweenShoot())));
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 45), "Blast radius");
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 45), std::to_string(weapons[weaponIndex]->getRadius()));
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 20, Window::SCREEN_HEIGHT / 2 + 55), "Bullets per shots");
	AlphabetDrawer::drawWord(window, Vector2(Window::SCREEN_WIDTH / 2 + 120, Window::SCREEN_HEIGHT / 2 + 55), std::to_string(weapons[weaponIndex]->getBulletPerShot()));
	// End weapon

	AlphabetDrawer::drawWord(window, Vector2(10, Window::SCREEN_HEIGHT - 40), "press q-left or d-right to change weapon");
	AlphabetDrawer::drawWord(window, Vector2(10, Window::SCREEN_HEIGHT - 30), "press enter or space to play");
	AlphabetDrawer::drawWord(window, Vector2(10, Window::SCREEN_HEIGHT - 20), "press echap to cancel");
	// End Texts

	gameMap.display(window);
	player.display(window);
	for (auto & element : bullet)
	{
		element.display(window);
	}

}

/*virtual*/ void GameStateGamePreparation::onEnter(void)
{
	nextWeapon = false;
	previousWeapon = false;
	timeElapsed = 0.0f;
	weaponChanged = false;
	gameMap = GameMap(42, 20);
	Initializer::initializePreparationBorder(&gameMap);
	Initializer::initializePreparationWall(&gameMap);

	weaponIndex = 0;
	weapons = std::vector<Weapon*>();
	weapons.push_back(new BombThrower());
	weapons.push_back(new Laser());
	weapons.push_back(new Shotgun());
	player.setWeapon(weapons[weaponIndex]);
}

/*virtual*/ void GameStateGamePreparation::onExit(void)
{

}

bool GameStateGamePreparation::collision(Vector2 positionBox1, Vector2 dimensionBox1, Vector2 positionBox2, Vector2 dimensionBox2)
{
	return !(positionBox1.x >= positionBox2.x + dimensionBox2.x)
		&& !(positionBox1.x + dimensionBox1.x <= positionBox2.x)
		&& !(positionBox1.y >= positionBox2.y + dimensionBox2.y)
		&& !(positionBox1.y + dimensionBox1.y <= positionBox2.y);
}