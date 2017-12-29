#include "../Headers/ScoreBlock.h"
int ScoreBlock::nbBlock = 0;
int ScoreBlock::level = 0;

/*explicit*/ ScoreBlock::ScoreBlock(void)
	: ScoreBlock(Vector2ui(0, 0), Vector2ui(4, 4))
{
}

/*explicit*/ ScoreBlock::ScoreBlock(Vector2ui position, Vector2ui dimension)
	: Block(false, false, ColorHelper::YELLOW + ColorHelper::BRIGHT, position, dimension)
{
	ScoreBlock::nbBlock++;
}

/*virtual*/ ScoreBlock::~ScoreBlock(void)
{

}

/*virtual*/ void ScoreBlock::collect(Player* player)
{
	if (!disabled)
	{
		AudioHelper::getAudioHelper()->play("pickup");
		player->addScore(100 * ScoreBlock::level);
		ScoreBlock::nbBlock--;
		disabled = true;
	}
	
}