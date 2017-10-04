#include "../Header/BorderInitializer.h"

/*virtual*/ void BorderInitializer::initialize(GameMap* map)
{
	Vector2 dimension = map->getDimension();
	for (unsigned int x = 0; x < dimension.x; ++x)
	{
		for (unsigned int y = 0; y < dimension.y; ++y)
		{
			if (x <= 1 || y <= 1 || x >= dimension.x - 2 || y >= dimension.y - 2)
				map->setBlock(x, y, (Block*) new BorderBlock());
			else
				map->setBlock(x, y, (Block*) new NormalBlock());
		}
	}
}