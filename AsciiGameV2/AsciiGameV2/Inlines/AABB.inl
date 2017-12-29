#pragma once
template <typename T>
/*explicit*/ inline AABB<T>::AABB(void)
{

}

template <typename T>
/*explicit*/ inline AABB<T>::AABB(T x, T y, T width, T height)
	: position(x, y)
	, dimension(width, height)
{

}

template <typename T>
/*explicit*/ inline AABB<T>::AABB(Vector2<T> pos, Vector2<T> dim)
	: position(pos)
	, dimension(dim)
{

}

template <typename T>
/*virtual*/ inline AABB<T>::~AABB(void)
{

}

template <typename T>
inline bool AABB<T>::contains(Vector2<T> point)
{
	return position.x <= point.x && point.x <= position.x + dimension.x
		&& position.y <= point.y && point.y <= position.y + dimension.y;
}

template <typename T>
inline bool AABB<T>::contains(AABB<T> other)
{
	return contains(other.position)
		&& contains(other.position + other.dimension);
}

template <typename T>
inline bool AABB<T>::intersect(AABB<T> other)
{
	return getX() < other.getX() + other.getWidth() &&
		getX() + getWidth() > other.getX() &&
		getY() < other.getY() + other.getHeight() &&
		getY() + getHeight() > other.getY();
}

template<typename T>
template<typename U>
inline bool AABB<T>::intersect(AABB<U> other)
{
	return getX() < other.getX() + other.getWidth() &&
		getX() + getWidth() > other.getX() &&
		getY() < other.getY() + other.getHeight() &&
		getY() + getHeight() > other.getY();
}

template <typename T>
inline T AABB<T>::getX()
{
	return position.x;
}

template <typename T>
inline T AABB<T>::getY()
{
	return position.y;
}

template <typename T>
inline T AABB<T>::getWidth()
{
	return dimension.x;
}

template <typename T>
inline T AABB<T>::getHeight()
{
	return dimension.y;
}