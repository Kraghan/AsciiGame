#include "../Headers/GameMap.h"
#include "../Headers/Debug.h"

/*explicit*/ GameMap::GameMap(void)
	: GameMap(Vector2ui(0,0))
{

}

/*explicit*/ GameMap::GameMap(Vector2ui dim)
{
	dimension = dim;
	quadTree = QuadTree(0,AABBf(Vector2f(0,Window::UI_HEIGHT), Vector2f(dim.x, dim.y)));
}

/*virtual*/ GameMap::~GameMap(void)
{

}

void GameMap::addBlock(Block* block)
{
	quadTree.insert(block);
}

void GameMap::update(void)
{
	
}

void GameMap::display(Vector2f cameraPosition)
{
	std::vector<Block*> blocks = quadTree.getInArea(AABBf(cameraPosition, Vector2f(Window::SCREEN_WIDTH, Window::SCREEN_HEIGHT)));

	for (int i = 0; i < blocks.size(); ++i)
	{
		blocks[i]->display(cameraPosition);
	}

}

Vector2ui GameMap::getDimension()
{
	return dimension;
}

std::vector<Block*> GameMap::getBlocks(Vector2f position, Vector2f dimension)
{
	return quadTree.getInArea(AABBf(position, dimension));
}

void GameMap::explode(Vector2ui positions, int radius)
{
	std::vector<Block*> blocks = quadTree.getAll(); //quadTree.getInArea(AABBf(Vector2f(positions.x - radius / 2, positions.y - radius / 2), Vector2f(radius, radius)));

	for (std::vector<Block*>::iterator it = blocks.begin(); it != blocks.end();++it)
	{
		Block* block = *it;

		if (block->unbreakable() || !block->solid())
			continue;

		float x = ((float)block->getPosition().x + (float)block->getDimension().x / 2.0f) - (float)positions.x;
		float y = ((float)block->getPosition().y + (float)block->getDimension().y / 2.0f) - (float)positions.y;
		
		if(x * x + y * y <= radius * radius)
			quadTree.remove(block);
	}

	AudioHelper::getAudioHelper()->play("destroy", false, SND_ASYNC | SND_NOSTOP);
}

void GameMap::removeBlock(Block* block)
{
	quadTree.remove(block);
}