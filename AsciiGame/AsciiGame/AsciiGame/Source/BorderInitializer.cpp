#include "../Header/BorderInitializer.h"

/*virtual*/ void BorderInitializer::initialize(GameMap* map)
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