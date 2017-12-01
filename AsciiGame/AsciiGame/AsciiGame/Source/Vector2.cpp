#include "../Header/Vector2.h"

Vector2 operator*(Vector2 const& a, unsigned int const& b)
{
	return Vector2(a.x * b, a.y * b);
}

Vector2 operator*(unsigned int const& a, Vector2 const& b)
{
	return b * a;
}

bool operator==(Vector2 const& a, Vector2 const& b)
{
	return a.x == b.x && a.y == b.y;
}