#include "../Header/CaveSeedInitializer.h"

/*virtual*/ void CaveSeedInitializer::initialize(GameMap* map)
{
	Vector2 dimension = map->getDimension();
	for (unsigned int x = 2; x < dimension.x - 3; ++x)
	{
		for (unsigned int y = 2; y < dimension.y - 3; ++y)
		{
			if (rand() < PROBABILITY)
				map->setBlock(Vector2(x, y), (Block*) new NormalBlock());
		}
	}

	for(unsigned short i = 0; i < ITERATION; ++i)
		process(map);
}

unsigned int CaveSeedInitializer::getNumberOfNeighbour(GameMap* map, Vector2 pos)
{
	unsigned int cpt = 0;
	if (pos.x != 0)
	{
		if (pos.y != 0)
			cpt += array[(pos.x - 1) + (pos.y - 1) * (uint)dimension.x];

		cpt += array[(pos.x - 1) + pos.y * (uint)dimension.x];

		if (pos.y != (uint)dimension.y - 1)
			cpt += array[(pos.x - 1) + pos(pos.y + 1) * (uint)dimension.x];
	}

	if (pos.x != (uint)(dimension.x - 1))
	{
		if (pos.y != 0)
			cpt += array[(pos.x + 1) + (pos.y - 1) * (uint)dimension.x];

		cpt += array[(pos.x + 1) + pos.y * (uint)dimension.x];

		if (y != (uint)dimension.y - 1)
			cpt += array[(pos.x + 1) + (pos.y + 1) * (uint)dimension.x];
	}

	if (y != 0)
		cpt += array[pos.x + (pos.y - 1) * (uint)dimension.x];
	if (y != (uint)dimension.y - 1)
		cpt += array[pos.x + (pos.y + 1) * (uint)dimension.x];

	return cpt;
}

void CaveSeedInitializer::process(GameMap* map)
{

}