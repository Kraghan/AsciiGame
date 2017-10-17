#include "../Header/GameMap.h"
#include "../Header/Debug.h"

/*explicit*/ GameMap::GameMap()
{
	blockMap = std::vector<Block*>(dimension.x * dimension.y);
	needRedraw = true;
}
/*explicit*/ GameMap::GameMap(Vector2 dim)
	: dimension(dim)
{
	blockMap = std::vector<Block*>(dimension.x * dimension.y);
	needRedraw = true;
}
/*explicit*/ GameMap::GameMap(unsigned int x, unsigned int y)
	: dimension(Vector2(x,y))
{
	
	blockMap = std::vector<Block*>();
	needRedraw = true;
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
	return x < dimension.x && y < dimension.y;
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

void GameMap::update()
{
	
}

void GameMap::display(Window* window)
{
	for (unsigned int i = 0; i < blockMap.size(); ++i)
		blockMap[i]->display(window);
}

void GameMap::explode(Vector2 position, unsigned int radius)
{
	Debug::log("Debug.txt", "" + std::to_string(position.x) + " " + std::to_string(position.y));
	Debug::log("Debug.txt", "\n" + std::to_string(radius), true);
	for (std::vector<Block*>::iterator it = blockMap.begin(); it != blockMap.end();)
	{
		if ((*it)->getIsSolid())
		{
			it++;
			continue;
		}
		unsigned int x = position.x - ((*it)->position.x * (*it)->getDimension().x);
		unsigned int y = position.y - ((*it)->position.y * (*it)->getDimension().y);

		if (x + y * y <= radius * radius)
		{
			Debug::log("Debug.txt", "\n" + std::to_string((*it)->position.x) + " " + std::to_string((*it)->position.y), true);
			it = blockMap.erase(it);
		}
		else
			it++;
	}
}