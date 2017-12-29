#include "../Headers/UnbreakableBlock.h"

/*explicit*/ UnbreakableBlock::UnbreakableBlock(void)
	: UnbreakableBlock(Vector2ui(0,0), Vector2ui(0,0))
{

}

/*explicit*/ UnbreakableBlock::UnbreakableBlock(Vector2ui position, Vector2ui dimension)
	: Block(true,true,ColorHelper::BRIGHT + ColorHelper::WHITE,position,dimension)
{

}

/*virtual*/ UnbreakableBlock::~UnbreakableBlock(void)
{

}