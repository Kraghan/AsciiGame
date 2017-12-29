#pragma once

template <typename T>
/*explicit*/ inline Vector2<T>::Vector2(void)
{

}

template <typename T>
/*explicit*/ inline Vector2<T>::Vector2(T xx, T yy)
	: x(xx)
	, y(yy)
{

}

template <typename T>
/*explicit*/ inline Vector2<T>::~Vector2(void)
{

}

template <typename T>
inline Vector2<T> operator*(Vector2<T> const& a, T const& b)
{
	return Vector2<T>(a.x * b, a.y * b);
}

template <typename T>
inline Vector2<T> operator*(T const& a, Vector2<T> const& b)
{
	return b * a;
}

template <typename T>
inline Vector2<T>  operator/  (Vector2<T> const& a, T const& b)
{
	return Vector2<T>(a.x / b, a.y / b);
}

template <typename T>
inline Vector2<T>  operator-  (Vector2<T> const& type1, Vector2<T> const& type2)
{
	Vector2<T> res;
	if (type2.x > type1.x)
		res.x = 0;
	else
		res.x = type1.x - type2.x;

	if (type2.y > type1.y)
		res.y = 0;
	else
		res.y = type1.y - type2.y;

	return res;
}

template <typename T>
inline Vector2<T>  operator+  (Vector2<T> const& type1, Vector2<T> const& type2)
{
	return Vector2<T>(type1.x + type2.x, type1.y + type2.y);
}

template <typename T>
inline Vector2<T> operator*  (Vector2<T> const& type1, Vector2<T> const& type2)
{
	return Vector2<T>(type1.x * type2.x, type1.y * type2.y);
}

template <typename T>
inline bool operator==(Vector2<T> const& a, Vector2<T> const& b)
{
	return a.x == b.x && a.y == b.y;
}