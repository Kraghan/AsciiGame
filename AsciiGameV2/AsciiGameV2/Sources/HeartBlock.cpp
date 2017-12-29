#include "../Headers/HeartBlock.h"

/*explicit*/ HeartBlock::HeartBlock(void)
	: HeartBlock(Vector2ui(0,0), Vector2ui(4,4))
{

}

/*explicit*/ HeartBlock::HeartBlock(Vector2ui position, Vector2ui dimension)
	: Block(false,false,ColorHelper::RED + ColorHelper::BRIGHT,position, dimension)
{

}

/*virtual*/ HeartBlock::~HeartBlock(void)
{

}

/*virtual*/ void HeartBlock::collect(Player* player)
{
	if (!disabled)
	{
		AudioHelper::getAudioHelper()->play("pickup");
		player->addLife(2);
		disabled = true;
	}
}