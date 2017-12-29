#pragma once
#include "Vector2.h"

template <typename T>
class AABB
{
public: 
	Vector2<T> position;
	Vector2<T> dimension;

	explicit AABB(void);
	explicit AABB(T x, T y, T width, T height);
	explicit AABB(Vector2<T> pos, Vector2<T> dim);
	virtual ~AABB(void);

	T getX();
	T getY();
	T getWidth();
	T getHeight();
		
	bool contains(Vector2<T> point);
	bool contains(AABB<T> other);
	bool intersect(AABB<T> other);
	template <typename U>
	bool intersect(AABB<U> other);
};

#include "../Inlines/AABB.inl"

typedef AABB<int> AABBi;
typedef AABB<unsigned int> AABBui;
typedef AABB<float> AABBf;
typedef AABB<double> AABBd;