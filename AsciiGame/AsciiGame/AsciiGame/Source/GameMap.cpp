#include "../Header/GameMap.h"
#include "../Header/Debug.h"

/*explicit*/ GameMap::GameMap()
{
	blockMap = std::vector<Block*>();
	blockMap.reserve(dimension.x * dimension.y);
	quadtree = QuadTree(0, AABB(0, 0, dimension.x * 4, dimension.y * 4));
}
/*explicit*/ GameMap::GameMap(Vector2 dim)
	: dimension(dim)
{
	blockMap = std::vector<Block*>();
	blockMap.reserve(dimension.x * dimension.y);
	quadtree = QuadTree(0,AABB(0,0,dimension.x * 4, dimension.y * 4));
}
/*explicit*/ GameMap::GameMap(unsigned int x, unsigned int y)
	: dimension(Vector2(x,y))
{
	blockMap = std::vector<Block*>();
	blockMap.reserve(x * y);
	quadtree = QuadTree(0, AABB(0, 0, dimension.x * 4, dimension.y * 4));
}

/*virtual*/ GameMap::~GameMap()
{

}

// Check if a position is in bound
bool GameMap::isInBound(Vector2 position)
{
	// Easy because of unsigned int, can't be negative
	return position.x <= dimension.x * 4 
		&& position.y <= dimension.y * 4 + Window::UI_HEIGHT
		&& Window::UI_HEIGHT <= position.y;
}
bool GameMap::isInBound(unsigned int x, unsigned int y)
{
	return isInBound(Vector2(x, y));
}

// Get the block at the position 
Block* GameMap::getBlock(Vector2 position)
{
	for (unsigned int i = 0; i < blockMap.size(); ++i)
		if (blockMap[i]->getPosition().x == position.x && blockMap[i]->getPosition().y == position.y)
			return blockMap[i];
	return nullptr;

}
Block* GameMap::getBlock(unsigned int x, unsigned int y)
{
	return getBlock(Vector2(x, y));
}

// Set the block at position
void GameMap::setBlock(Block* block)
{
	for (unsigned int i = 0; i < blockMap.size(); ++i)
		if (blockMap[i]->getPosition().x == block->getPosition().x && blockMap[i]->getPosition().y == block->getPosition().y)
		{
			delete(blockMap[i]);
			blockMap[i] = block;
			return;
		}

	blockMap.push_back(block);

}

Vector2 GameMap::getDimension()
{
	return dimension;
}

std::vector<Block*> GameMap::getBlocks()
{
	return blockMap;
}

std::vector<Block*> GameMap::getBlocks(AABB bounds)
{
	return quadtree.queryRange(bounds);
}

void GameMap::update()
{
	for (unsigned int i = 0; i < blockMap.size(); ++i)
	{
		if (blockMap[i]->getName() == "CorruptionBlock")
		{
			CorruptionBlock* block = (CorruptionBlock*) blockMap[i];
			if (!block->getActive())
				continue;

			Vector2 currentPosition = blockMap[i]->getPosition();

			std::vector<Block*> adjacents = std::vector<Block*>();
			for (unsigned int j = 0; j < blockMap.size(); ++j)
			{
				if (j == i)
					continue;
				
				Vector2 position = blockMap[j]->getPosition();

				if (position.x == currentPosition.x && position.y == currentPosition.y - 1)
				{
					adjacents.push_back(blockMap[j]);
					continue;
				}

				if (position.x == currentPosition.x && position.y == currentPosition.y + 1)
				{
					adjacents.push_back(blockMap[j]);
					continue;
				}

				if (position.x == currentPosition.x - 1 && position.y == currentPosition.y)
				{
					adjacents.push_back(blockMap[j]);
					continue;
				}

				if (position.x == currentPosition.x + 1 && position.y == currentPosition.y)
				{
					adjacents.push_back(blockMap[j]);
					continue;
				}
			}

			/*bool setInactive = true;
			for (unsigned int j = 0; j < adjacents.size(); ++j)
			{
				if (adjacents[j]->getName() != "CorruptionBlock")
					setInactive = false;
				else
					adjacents.erase(adjacents.begin() + j);
			}
			block->setActive(setInactive);

			if (adjacents.size() != 0)
			{
				unsigned int random = rand() % adjacents.size();
				setBlock(new CorruptionBlock(adjacents[random]->getPosition()));
			}*/
		}
	}
}

void GameMap::display(Window* window)
{
	for (unsigned int i = 0; i < blockMap.size(); ++i)
		blockMap[i]->display(window);
}

void GameMap::explode(Vector2 position, unsigned int radius)
{
	for (std::vector<Block*>::iterator it = blockMap.begin(); it != blockMap.end();)
	{
		if (!(*it)->getIsSolid() || (*it)->isUnbreakable)
		{
			it++;
			continue;
		}
		int x = ((*it)->position.x * (*it)->getDimension().x) - position.x;
		int y = ((*it)->position.y * (*it)->getDimension().y + Window::UI_HEIGHT) - position.y;

		if (x * x + y * y <= (int) (radius * radius))
		{
			quadtree.remove(*it);
			delete(*it);
			it = blockMap.erase(it);
		}
		else
			it++;
	}
	AudioHelper::getAudioHelper()->play("destroy", false, SND_ASYNC | SND_NOSTOP);
}

void GameMap::debug()
{
	/*Debug::log("DebugGameMap.txt", "");
	for (std::vector<Block*>::iterator it = blockMap.begin(); it != blockMap.end(); it++)
	{
		Debug::log("DebugGameMap.txt", std::to_string((*it)->position.x) + " " + std::to_string((*it)->position.y) + "\n", true);
	}*/
	Debug::log("blocks.log", std::to_string(blockMap.size())+"\n");
	Debug::log("blocks.log", std::to_string(quadtree.getNumberOfNodes()), true);
}

void GameMap::clear()
{
	for (std::vector<Block*>::iterator it = blockMap.begin(); it != blockMap.end();)
	{
		delete(*it);
		it = blockMap.erase(it);
	}
}

void GameMap::destroyBlock(Vector2 position)
{
	for (std::vector<Block*>::iterator it = blockMap.begin(); it != blockMap.end();)
	{
		if ((*it)->position.x == position.x && (*it)->position.y == position.y)
		{
			quadtree.remove(*it);
			delete(*it);
			blockMap.erase(it);
			return;
		}
		++it;
	}
}

void GameMap::updateQuadTree()
{
	quadtree.clear();
	for (unsigned int i = 0; i < blockMap.size(); ++i)
	{
		quadtree.insert(blockMap[i]);
	}
}