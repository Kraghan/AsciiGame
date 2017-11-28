#pragma once
#include "AABB.h"
#include "Block.h"
#include <vector>

class QuadTree
{
private : 
	static const unsigned short NODE_CAPACITY = 4;

	std::vector<Block> m_nodes;
	AABB m_bounds;

	QuadTree* m_northWest;
	QuadTree* m_northEast;
	QuadTree* m_southWest;
	QuadTree* m_southEast;

	bool m_isComplete;

public:
	explicit QuadTree()
		: m_bounds(AABB())
		, m_northEast(nullptr)
		, m_northWest(nullptr)
		, m_southEast(nullptr)
		, m_southWest(nullptr)
		, m_isComplete(false){}

	explicit QuadTree(AABB bounds)
		: m_bounds(bounds)
		, m_northEast(nullptr)
		, m_northWest(nullptr)
		, m_southEast(nullptr)
		, m_southWest(nullptr)
		, m_isComplete(false) {}

	virtual ~QuadTree(){}
	//https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374

	void subdivide()
	{
		Vector2 newDimensions = Vector2(m_bounds.dimension.x / 2, m_bounds.dimension.y / 2);
		int eastX = m_bounds.position.x + newDimensions.x;
		int southY = m_bounds.position.y + newDimensions.y;

		m_northWest = new QuadTree(AABB(m_bounds.position, newDimensions));
		m_northEast = new QuadTree(AABB(Vector2(eastX, m_bounds.position.y), newDimensions));
		m_southWest = new QuadTree(AABB(Vector2(m_bounds.position.x, southY), newDimensions));
		m_southEast = new QuadTree(AABB(Vector2(eastX, southY), newDimensions));
	}

	bool insert(Block node)
	{
		if(m_bounds.contains() )
	}

	void queryRange(AABB area)
	{

	}
};