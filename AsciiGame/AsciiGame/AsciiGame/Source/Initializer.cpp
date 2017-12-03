#include "../Header/Initializer.h"
#include "../Header/Debug.h"

std::vector<std::vector<bool>> Initializer::abstraction = std::vector<std::vector<bool>>();

/*static*/ void Initializer::initializeBorder(GameMap* map)
{
	Vector2 dimension = map->getDimension();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			if (x < 1 || y < 1 || x >= dimension.x - 1 || y >= dimension.y - 1)
			{
				map->setBlock((Block*) new BorderBlock(Vector2(x, y)));
				continue;
			}
		}
	}
}

/*static*/ void Initializer::initializePreparationBorder(GameMap* map)
{
	Vector2 dimension = map->getDimension();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		map->setBlock((Block*) new BorderBlock(Vector2(54 + x, 0)));
		map->setBlock((Block*) new BorderBlock(Vector2(54 + x, dimension.y - 1)));
	}

	for (unsigned int y = 1; y < dimension.y - 1; ++y)
	{
		map->setBlock((Block*) new BorderBlock(Vector2(54, y)));
		map->setBlock((Block*) new BorderBlock(Vector2(54 + dimension.x - 1, y)));
	}
}

/*static*/ void Initializer::initializePreparationWall(GameMap* map)
{
	Vector2 dimension = map->getDimension();
	for (unsigned int x = 0; x < 10; ++x)
	{
		for (unsigned int y = 1; y < dimension.y - 1; ++y)
		{
			map->setBlock((Block*) new NormalBlock(Vector2(80 + x,y)));
		}
	}
}


/*static*/ void Initializer::initializeCave(GameMap* map)
{
	Vector2 dimension = map->getDimension();

	srand((unsigned int)time(NULL));

	Initializer::abstraction = std::vector<std::vector<bool>>((dimension.x - 2));

	for (unsigned int x = 0; x < Initializer::abstraction.size(); ++x)
	{
		Initializer::abstraction[x] = std::vector<bool>((dimension.y - 2));

		for (unsigned int y = 0; y < Initializer::abstraction[x].size(); ++y)
		{
			if (rand() % 100 + 1 < PROBABILITY)
				Initializer::abstraction[x][y] = true;
			else
				Initializer::abstraction[x][y] = false;
		}
	}

	for (unsigned short i = 0; i < 5; ++i)
		Initializer::abstraction = process();


	for (unsigned int x = 0; x < Initializer::abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < Initializer::abstraction[x].size(); ++y)
		{
			if (Initializer::abstraction[x][y])
			{
				map->setBlock((Block*) new NormalBlock(Vector2(x + 1, y + 1)));
			}
		}
	}
}

/*static*/ void Initializer::initializeCollectible(GameMap* map, unsigned int nbScoreBlock, unsigned int nbAmmoBlock, unsigned int nbHeartBlock)
{
	Vector2 dimension = map->getDimension();
	unsigned int nbBlock = dimension.x * dimension.y;
	float spawnRate = (float)nbBlock / (float)(nbScoreBlock + nbAmmoBlock + nbHeartBlock);
	unsigned int scoreSet = 0, heartSet = 0, ammoSet = 0, cpt = 0;
	bool lockScore = false, lockHeart = false, lockAmmo = false;
	srand((unsigned int)time(NULL));

	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			++cpt;
			Block* block = map->getBlock(Vector2(x, y));
			if (block == nullptr || block->getIsUnbreakable())
				continue;

			if (cpt >= spawnRate)
			{
				cpt = 0; 
				int random = rand() % 3;

				if (random == 0 || lockScore)
				{
					map->setBlock((Block*) new ScoreBlock(Vector2(x, y)));

					scoreSet++;
				}
				else if (random == 1 || lockHeart)
				{
					map->setBlock((Block*) new LifeBlock(Vector2(x, y)));

					heartSet++;
				}
				else if (random == 2 || lockAmmo)
				{
					map->setBlock((Block*) new AmmoBlock(Vector2(x, y)));

					ammoSet++;
				}
			}
		}
	}

	
}

unsigned short Initializer::getNumberOfNeighbour(Vector2 pos)
{
	unsigned int cpt = 0;
	if (pos.x != 0)
	{
		if (pos.y != 0 && Initializer::abstraction[pos.x - 1][pos.y - 1])
			++cpt;

		if (Initializer::abstraction[pos.x - 1][pos.y])
			++cpt;

		if (pos.y != Initializer::abstraction[pos.x].size() - 1 && Initializer::abstraction[pos.x - 1][pos.y + 1])
			++cpt;
	}

	if (pos.x != (Initializer::abstraction.size() - 1))
	{
		if (pos.y != 0 && Initializer::abstraction[pos.x + 1][pos.y - 1])
			++cpt;

		if (Initializer::abstraction[pos.x + 1][pos.y])
			++cpt;

		if (pos.y != Initializer::abstraction[pos.x].size() - 1 && Initializer::abstraction[pos.x + 1][pos.y + 1])
			++cpt;
	}

	if (pos.y != 0 && Initializer::abstraction[pos.x][pos.y - 1])
		++cpt;

	if (pos.y != Initializer::abstraction[pos.x].size() - 1 && Initializer::abstraction[pos.x][pos.y + 1])
		++cpt;

	return cpt;
}

std::vector<std::vector<bool>> Initializer::process()
{
	std::vector<std::vector<bool>> tmp = Initializer::abstraction;
	for (unsigned int x = 0; x < Initializer::abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < Initializer::abstraction[x].size(); ++y)
		{
			unsigned short neighbours = getNumberOfNeighbour(Vector2(x, y));
			if (Initializer::abstraction[x][y] && neighbours < 4)
				tmp[x][y] = false;

			else if (!Initializer::abstraction[x][y] && neighbours >= 5)
				tmp[x][y] = true;
		}
	}
	return tmp;
}

/*static*/ void Initializer::initializeCorruption(GameMap* map, unsigned int nbSeeds)
{
	std::vector<Block*> blocks = map->getBlocks();
	std::vector<unsigned int> randoms;
	for(unsigned int i = 0; i < nbSeeds; ++i)
	{
		unsigned int random = blocks.size();
		do
		{
			random = rand() % blocks.size();
			//Debug::log("Initializer.txt", std::to_string() + " " + std::to_string(), true);
		} while (random >= blocks.size() 
			|| std::find(randoms.begin(), randoms.end(), random) != randoms.end()
			|| blocks[random]->getIsUnbreakable());

		randoms.push_back(random);
		
		map->setBlock(new CorruptionBlock(blocks[random]->getPosition()));

	}
	
}