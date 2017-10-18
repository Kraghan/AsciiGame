#include "../Header/Initializer.h"

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


/*static*/ void Initializer::initializeCave(GameMap* map)
{
	Vector2 dimension = map->getDimension();

	srand((unsigned int)time(NULL));

	std::vector<std::vector<bool>> abstraction = std::vector<std::vector<bool>>((dimension.x - 2));

	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		abstraction[x] = std::vector<bool>((dimension.y - 2));

		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (rand() % 100 + 1 < PROBABILITY)
				abstraction[x][y] = true;
			else
				abstraction[x][y] = false;
		}
	}

	for (unsigned short i = 0; i < 5; ++i)
		abstraction = process(abstraction);


	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			if (abstraction[x][y])
			{
				map->setBlock((Block*) new NormalBlock(Vector2(x + 1, y + 1)));
			}
		}
	}
}

unsigned short Initializer::getNumberOfNeighbour(Vector2 pos, std::vector<std::vector<bool>> abstraction)
{
	unsigned int cpt = 0;
	if (pos.x != 0)
	{
		if (pos.y != 0 && abstraction[pos.x - 1][pos.y - 1])
			++cpt;

		if (abstraction[pos.x - 1][pos.y])
			++cpt;

		if (pos.y != abstraction[pos.x].size() - 1 && abstraction[pos.x - 1][pos.y + 1])
			++cpt;
	}

	if (pos.x != (abstraction.size() - 1))
	{
		if (pos.y != 0 && abstraction[pos.x + 1][pos.y - 1])
			++cpt;

		if (abstraction[pos.x + 1][pos.y])
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

std::vector<std::vector<bool>> Initializer::process(std::vector<std::vector<bool>> abstraction)
{
	std::vector<std::vector<bool>> tmp = abstraction;
	for (unsigned int x = 0; x < abstraction.size(); ++x)
	{
		for (unsigned int y = 0; y < abstraction[x].size(); ++y)
		{
			unsigned short neighbours = getNumberOfNeighbour(Vector2(x, y),abstraction);
			if (abstraction[x][y] && neighbours < 4)
				tmp[x][y] = false;

			else if (!abstraction[x][y] && neighbours >= 5)
				tmp[x][y] = true;
		}
	}
	return tmp;
}