#include "../Header/GameMap.h"

/*explicit*/ GameMap::GameMap()
{
	blockMap = std::vector<std::vector<Block>>(dimension.x);
	for (unsigned int i = 0; i < blockMap.size(); ++i)
	{
		blockMap[i] = std::vector<Block>(dimension.y);
		for (unsigned int j = 0; j < blockMap[i].size(); ++j)
			blockMap[i][j] = Block(i, j, ' ', false);
	}
	needRedraw = true;
}
/*explicit*/ GameMap::GameMap(Vector2 dim)
	: dimension(dim)
{
	blockMap = std::vector<std::vector<Block>>(dimension.x);
	for (unsigned int i = 0; i < blockMap.size(); ++i)
	{
		blockMap[i] = std::vector<Block>(dimension.y);
		for (unsigned int j = 0; j < blockMap[i].size(); ++j)
			blockMap[i][j] = Block(i, j, ' ', false);
	}
	needRedraw = true;
}
/*explicit*/ GameMap::GameMap(unsigned int x, unsigned int y)
	: dimension(Vector2(x,y))
{
	
	blockMap = std::vector<std::vector<Block>>(dimension.x);
	for (unsigned int i = 0; i < blockMap.size(); ++i)
	{
		blockMap[i] = std::vector<Block>(dimension.y);
		for (unsigned int j = 0; j < blockMap[i].size(); ++j)
		{
			blockMap[i][j] = Block(i, j, ' ', false);
		}
	}
	needRedraw = true;
	
}
/*virtual*/ GameMap::~GameMap()
{

}

// Check if a position is in bound
bool GameMap::isInBound(Vector2 position)
{
	// Easy because of unsigned int, can't be negative
	return position.x < dimension.x && position.y < dimension.y;
}
bool GameMap::isInBound(unsigned int x, unsigned int y)
{
	return x < dimension.x && y < dimension.y;
}

// Get the block at the position 
Block* GameMap::getBlock(Vector2 position)
{
	return &blockMap[position.x][position.y];
}
Block* GameMap::getBlock(unsigned int x, unsigned int y)
{
	return &blockMap[x][y];
}

// Set the block at position
void GameMap::setBlock(Vector2 position, Block* block)
{
	blockMap[position.x][position.y].setPosition(position);
	blockMap[position.x][position.y].setSprite(block->getSprite());
	blockMap[position.x][position.y].setIsSolid(block->getIsSolid());
}
void GameMap::setBlock(unsigned int x, unsigned int y, Block* block)
{
	blockMap[x][y].setPosition(Vector2(x,y));
	blockMap[x][y].setSprite(block->getSprite());
	blockMap[x][y].setIsSolid(block->getIsSolid());
}

Vector2 GameMap::getDimension()
{
	return dimension;
}

std::vector<std::vector<Block>> GameMap::getBlocks()
{
	return blockMap;
}

void GameMap::update()
{
	
}

void GameMap::display(Window* window)
{
	if (needRedraw)
	{
		for (unsigned int i = 0; i < blockMap.size(); ++i)
		{
			for (unsigned int j = 0; j < blockMap[i].size(); ++j)
			{
				window->changePixel(i, j, blockMap[i][j].getSprite());
			}
		}
		needRedraw = false;
	}
}