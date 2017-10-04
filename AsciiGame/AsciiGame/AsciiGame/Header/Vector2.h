#pragma once

class Vector2
{
public :
	unsigned x, y;

	explicit Vector2(void)
	{
		x = 0;
		y = 0;
	}

	explicit Vector2(unsigned int xx, unsigned int yy)
	{
		x = xx;
		y = yy;
	}
};