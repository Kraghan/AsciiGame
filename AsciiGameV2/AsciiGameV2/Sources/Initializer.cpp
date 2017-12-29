#include "../Headers/Initializer.h"
#include "../Headers/Debug.h"

Vector2ui Initializer::blockDimension = Vector2ui(4, 4);

/*static*/ void Initializer::initializeBorder(GameMap* map)
{	
	int xOccupied = 0;
	int yOccupied = 0;
	while (xOccupied + blockDimension.x < map->getDimension().x)
	{
		map->addBlock(new UnbreakableBlock(Vector2ui(xOccupied, Window::UI_HEIGHT), blockDimension));
		xOccupied += blockDimension.x;
	}

	while (yOccupied + blockDimension.y < map->getDimension().y)
	{
		map->addBlock(new UnbreakableBlock(Vector2ui(xOccupied, Window::UI_HEIGHT + yOccupied), blockDimension));
		map->addBlock(new UnbreakableBlock(Vector2ui(0, Window::UI_HEIGHT + yOccupied), blockDimension));
		yOccupied += blockDimension.y;
	}

	while (xOccupied >= 0)
	{
		map->addBlock(new UnbreakableBlock(Vector2ui(xOccupied, Window::UI_HEIGHT + yOccupied), blockDimension));
		xOccupied -= blockDimension.x;
	}
}

/*static*/ void Initializer::initializeCave(GameMap* map)
{
	Vector2ui dimension = map->getDimension();

	srand((unsigned int)time(NULL));

	std::vector<std::vector<bool>> abstraction = std::vector<std::vector<bool>>((dimension.x / blockDimension.x));

	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		abstraction[x] = std::vector<bool>((dimension.y / blockDimension.y));

		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (rand() % 100 + 1 < 45)
				abstraction[x][y] = true;
			else
				abstraction[x][y] = false;
		}
	}

	for (unsigned short i = 0; i < 5; ++i)
	{
		std::vector<std::vector<bool>> tmp = abstraction;

		for (unsigned int x = 0; x < abstraction.size(); ++x)
		{
			for (unsigned int y = 0; y < abstraction[x].size(); ++y)
			{
				unsigned short neighbours = getNumberOfNeighbour(Vector2ui(x, y),abstraction);

				if (abstraction[x][y] && neighbours < 4)
					tmp[x][y] = false;

				else if (!abstraction[x][y] && neighbours >= 5)
					tmp[x][y] = true;
			}
		}

		abstraction = tmp;
	}

	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (abstraction[x][y])
			{
				map->addBlock(new NormalBlock(Vector2ui(x * blockDimension.x, Window::UI_HEIGHT + y*blockDimension.y), blockDimension));
			}
		}
	}
}

unsigned short Initializer::getNumberOfNeighbour(Vector2ui pos, std::vector<std::vector<bool>> vec)
{
	unsigned int cpt = 0;
	if (pos.x != 0)
	{
		if (pos.y != 0 && vec[pos.x - 1][pos.y - 1])
			++cpt;

		if (vec[pos.x - 1][pos.y])
			++cpt;

		if (pos.y != vec[pos.x].size() - 1 && vec[pos.x - 1][pos.y + 1])
			++cpt;
	}

	if (pos.x != (vec.size() - 1))
	{
		if (pos.y != 0 && vec[pos.x + 1][pos.y - 1])
			++cpt;

		if (vec[pos.x + 1][pos.y])
			++cpt;

		if (pos.y != vec[pos.x].size() - 1 && vec[pos.x + 1][pos.y + 1])
			++cpt;
	}

	if (pos.y != 0 && vec[pos.x][pos.y - 1])
		++cpt;

	if (pos.y != vec[pos.x].size() - 1 && vec[pos.x][pos.y + 1])
		++cpt;

	return cpt;
}

/*static*/ void Initializer::initializePreparationWall(GameMap* map)
{
	Vector2ui dimension = Vector2ui(42, 20);
	for (unsigned int x = 0; x < 10; ++x)
	{
		for (unsigned int y = 1; y < dimension.y - 1; ++y)
		{
			map->addBlock((Block*) new NormalBlock(Vector2ui(80 * 4 + x * 4, y * 4 + Window::UI_HEIGHT), Vector2ui(4,4)));
		}
	}
}

/*static*/ void Initializer::initializeBorderPreparation(GameMap* map)
{
	Vector2ui dimension = Vector2ui(42, 20);
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		map->addBlock((Block*) new UnbreakableBlock(Vector2ui(54 * 4 + x * 4, Window::UI_HEIGHT), Vector2ui(4,4)));
		map->addBlock((Block*) new UnbreakableBlock(Vector2ui(54 * 4 + x * 4, (dimension.y - 1) * 4 + Window::UI_HEIGHT), Vector2ui(4, 4)));
	}

	for (unsigned int y = 1; y < dimension.y - 1; ++y)
	{
		map->addBlock((Block*) new UnbreakableBlock(Vector2ui(54 * 4, y * 4 + Window::UI_HEIGHT), Vector2ui(4, 4)));
		map->addBlock((Block*) new UnbreakableBlock(Vector2ui(54 * 4 + (dimension.x - 1) * 4, y * 4 + Window::UI_HEIGHT), Vector2ui(4, 4)));
	}
}

/*static*/ void Initializer::initializePickUp(GameMap* map)
{
	int nbScoreBlock = 10;
	int nbAmmoBlock = 20; 
	int nbHeartBlock = 5;

	ScoreBlock::nbBlock = 0;

	Vector2ui dimension = map->getDimension();
	unsigned int nbBlock = ((dimension.x - 16) / 4) * ((dimension.y - 16) / 4);
	float spawnRate = (float)nbBlock / (float)(nbScoreBlock + nbAmmoBlock + nbHeartBlock);
	unsigned int scoreSet = 0, heartSet = 0, ammoSet = 0, cpt = 0;
	bool lockScore = false, lockHeart = false, lockAmmo = false;
	srand((unsigned int)time(NULL));

	for (unsigned int x = 8; x < dimension.x - 8; x += 4)
	{
		for (unsigned int y = 8; y < dimension.y - 8; y += 4)
		{
			++cpt;

			if (cpt >= spawnRate)
			{
				cpt = 0;
				int random = rand() % 3;

				if (random == 0 || lockScore)
				{
					map->addBlock((Block*) new ScoreBlock(Vector2ui(x, y + Window::UI_HEIGHT), Vector2ui(4,4)));

					scoreSet++;
				}
				else if (random == 1 || lockHeart)
				{
					map->addBlock((Block*) new HeartBlock(Vector2ui(x, y + Window::UI_HEIGHT), Vector2ui(4,4)));

					heartSet++;
				}
				else if (random == 2 || lockAmmo)
				{
					map->addBlock((Block*) new AmmoBlock(Vector2ui(x, y + Window::UI_HEIGHT), Vector2ui(4,4)));

					ammoSet++;
				}
			}
		}
	}
}