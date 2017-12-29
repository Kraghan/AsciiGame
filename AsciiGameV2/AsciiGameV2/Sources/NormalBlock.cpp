#include "../Headers/NormalBlock.h"

/*explicit*/ NormalBlock::NormalBlock(void)
	: NormalBlock(Vector2ui(0,0), Vector2ui(0,0))
{

}

/*explicit*/ NormalBlock::NormalBlock(Vector2ui position, Vector2ui dimension)
	: Block(true,false,ColorHelper::WHITE,position,dimension)
{

}

/*virtual*/ NormalBlock::~NormalBlock(void)
{

}