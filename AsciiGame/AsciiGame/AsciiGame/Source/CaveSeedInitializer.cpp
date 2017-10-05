#include "../Header/CaveSeedInitializer.h"

/*virtual*/ void CaveSeedInitializer::initialize(GameMap* map)
{
	Vector2 dimension = map->getDimension();

	srand(time(NULL));

	if ((dimension.x - 4) % 4 != 0 && (dimension.y - 4) % 4 != 0)
	{
		cout << "Erreur : taille de map invalide" << endl;
		exit(-1);
	}


	abstraction = std::vector<std::vector<bool>>((dimension.x - 4) / 4);

	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		abstraction[x] = std::vector<bool>((dimension.y - 4) / 4);

		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (rand() % 100 + 1 < PROBABILITY)
				abstraction[x][y] = true;
			else
				abstraction[x][y] = false;
		}
	}

	for (unsigned short i = 0; i < 5; ++i)
	{
		process();
	}


	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (abstraction[x][y])
			{
				map->setBlock(x * 4 + 2, y * 4 + 2, (Block*) new NormalBlock());
				map->setBlock(x * 4 + 3, y * 4 + 2, (Block*) new NormalBlock());
				map->setBlock(x * 4 + 2, y * 4 + 3, (Block*) new NormalBlock());
				map->setBlock(x * 4 + 3, y * 4 + 3, (Block*) new NormalBlock());
			}
		}
	}
}

unsigned short CaveSeedInitializer::getNumberOfNeighbour(Vector2 pos)
{
	unsigned int cpt = 0;
	if (pos.x != 0)
	{
		if (pos.y != 0 && abstraction[pos.x - 1][pos.y - 1])
			++cpt;

		if(abstraction[pos.x - 1][pos.y])
			++cpt;

		if (pos.y != abstraction[pos.x].size() - 1 && abstraction[pos.x - 1][pos.y + 1])
			++cpt;
	}

	if (pos.x != (abstraction.size() - 1))
	{
		if (pos.y != 0 && abstraction[pos.x + 1][pos.y - 1])
			++cpt;

		if(abstraction[pos.x + 1][pos.y])
			++cpt; 

		if (pos.y != abstraction[pos.x].size() - 1 && abstraction[pos.x + 1][pos.y + 1])
			++cpt;
	}

	if (pos.y != 0 && abstraction[pos.x][pos.y - 1])
		++cpt;

	if (pos.y != abstraction[pos.x].size() - 1 && abstraction[pos.x][pos.y + 1])
		++cpt;

	return cpt;
}

void CaveSeedInitializer::process()
{
	std::vector<std::vector<bool>> tmp = abstraction;
	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			unsigned short neighbours = getNumberOfNeighbour(Vector2(x, y));
			if (abstraction[x][y] && neighbours < 4)
				tmp[x][y] = false;

			else if (!abstraction[x][y] && neighbours >= 5)
				tmp[x][y] = true;
		}
	}
	abstraction = tmp;
}