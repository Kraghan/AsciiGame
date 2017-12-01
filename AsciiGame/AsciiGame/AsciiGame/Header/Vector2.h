#pragma once

class Vector2
{
public :
	unsigned int x, y;

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

Vector2  operator*  (Vector2 const& type1, unsigned int const& type2);
Vector2  operator*  (unsigned int const& type1, Vector2 const& type2);

bool  operator==  (Vector2 const& type1, Vector2 const& type2);