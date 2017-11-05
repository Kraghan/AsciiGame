#include "../Header/Initializer.h"

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