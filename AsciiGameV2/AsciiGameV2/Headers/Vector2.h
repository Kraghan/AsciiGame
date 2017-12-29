#pragma once

template <typename T>
class Vector2
{
public:
	T x;
	T y;
	explicit Vector2(void);
	explicit Vector2(T xx, T yy);
	virtual ~Vector2(void);
};

template <typename T>
Vector2<T>  operator*  (Vector2<T> const& type1, T const& type2);
template <typename T>
Vector2<T>  operator*  (T const& type1, Vector2<T> const& type2);
template <typename T>
Vector2<T>  operator/  (Vector2<T> const& type1, T const& type2);
template <typename T>
Vector2<T>  operator-  (Vector2<T> const& type1, Vector2<T> const& type2);
template <typename T>
Vector2<T>  operator+  (Vector2<T> const& type1, Vector2<T> const& type2);
template <typename T>
Vector2<T>  operator*  (Vector2<T> const& type1, Vector2<T> const& type2);
template <typename T>
bool  operator==  (Vector2<T> const& type1, Vector2<T> const& type2);

#include "../Inlines/Vector2.inl"

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<double> Vector2d;