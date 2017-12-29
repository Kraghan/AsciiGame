#include "../Headers/AmmoBlock.h"

/*explicit*/ AmmoBlock::AmmoBlock(void)
	: AmmoBlock(Vector2ui(0, 0), Vector2ui(4, 4))
{

}

/*explicit*/ AmmoBlock::AmmoBlock(Vector2ui position, Vector2ui dimension)
	: Block(false, false, ColorHelper::GREEN + ColorHelper::BRIGHT, position, dimension)
{

}

/*virtual*/ AmmoBlock::~AmmoBlock(void)
{

}

/*virtual*/ void AmmoBlock::collect(Player* player)
{
	if (!disabled)
	{
		AudioHelper::getAudioHelper()->play("pickup");
		player->addAmmo(5);
		disabled = true;
	}
}