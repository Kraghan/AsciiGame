#include "../Header/QuadTree.h"

/*Explicit*/ QuadTree::QuadTree()
	: m_bounds(AABB())
	, m_northEast(nullptr)
	, m_northWest(nullptr)
	, m_southEast(nullptr)
	, m_southWest(nullptr)
	, m_isSubdivided(false)
	, m_level(0) 
{
	m_nodes.reserve(NODE_CAPACITY);
}

/*Explicit*/ QuadTree::QuadTree(unsigned int level, AABB bounds)
	: m_bounds(bounds)
	, m_northEast(nullptr)
	, m_northWest(nullptr)
	, m_southEast(nullptr)
	, m_southWest(nullptr)
	, m_isSubdivided(false)
	, m_level(level) 
{
	m_nodes.reserve(NODE_CAPACITY);
}

/*virtual*/ QuadTree::~QuadTree()
{

}

void QuadTree::subdivide()
{
	int subWidth = (int)(m_bounds.dimension.x / 2);
	int subHeight = (int)(m_bounds.dimension.y / 2);
	int x = (int)m_bounds.position.x;
	int y = (int)m_bounds.position.y;

	if (m_northEast == nullptr)
	{
		m_northEast = new QuadTree(m_level + 1, AABB(x + subWidth, y, subWidth, subHeight));
		m_northWest = new QuadTree(m_level + 1, AABB(x, y, subWidth, subHeight));
		m_southWest = new QuadTree(m_level + 1, AABB(x, y + subHeight, subWidth, subHeight));
		m_southEast = new QuadTree(m_level + 1, AABB(x + subWidth, y + subHeight, subWidth, subHeight));

		/*if (m_bounds.dimension.x & 1 == 1)
		{

			m_northEast = new QuadTree(m_level + 1, AABB(x + subWidth, y, subWidth + 1, subHeight));
			m_northWest = new QuadTree(m_level + 1, AABB(x, y, subWidth, subHeight));
			if (m_bounds.dimension.y & 1 == 1)
			{
				m_southWest = new QuadTree(m_level + 1, AABB(x, y + subHeight, subWidth, subHeight + 1));
				m_southEast = new QuadTree(m_level + 1, AABB(x + subWidth, y + subHeight, subWidth + 1, subHeight + 1));
			}
			else
			{
				m_southWest = new QuadTree(m_level + 1, AABB(x, y + subHeight, subWidth, subHeight));
				m_southEast = new QuadTree(m_level + 1, AABB(x + subWidth, y + subHeight, subWidth + 1, subHeight));
			}
		}
		else
		{
			m_northEast = new QuadTree(m_level + 1, AABB(x + subWidth, y, subWidth, subHeight));
			m_northWest = new QuadTree(m_level + 1, AABB(x, y, subWidth, subHeight));
			if (m_bounds.dimension.y & 1 == 1)
			{
				m_southWest = new QuadTree(m_level + 1, AABB(x, y + subHeight, subWidth, subHeight + 1));
				m_southEast = new QuadTree(m_level + 1, AABB(x + subWidth, y + subHeight, subWidth, subHeight + 1));
			}
			else
			{
				m_southWest = new QuadTree(m_level + 1, AABB(x, y + subHeight, subWidth, subHeight));
				m_southEast = new QuadTree(m_level + 1, AABB(x + subWidth, y + subHeight, subWidth, subHeight));
			}
		}*/
	}

	m_isSubdivided = true;
}

void QuadTree::insert(Block* node)
{
	// Si le tree est splitté on essaie de le refourguer aux enfants
	if (m_isSubdivided)
	{
		QuadTree* tree = getIndex(AABB(node->getPosition() * 4, node->getDimension()));
		if (tree != nullptr)
		{
			tree->insert(node);
			return;
		}

	}
	
	m_nodes.push_back(node);
	
	if (m_nodes.size() >= NODE_CAPACITY && m_level < MAX_LEVEL)
	{
		if (!m_isSubdivided)
		{
			subdivide();
			for (int i = 0; i < m_nodes.size(); ++i)
			{
				QuadTree* tree = getIndex(AABB(m_nodes[i]->getPosition() * 4, m_nodes[i]->getDimension()));
				if (tree != nullptr)
				{
					tree->insert(m_nodes[i]);
				}
			}
			m_nodes.clear();
		}
	}
}

void QuadTree::remove(Block* node)
{
	if (m_isSubdivided)
	{
		QuadTree* tree = getIndex(AABB(node->getPosition() * 4, node->getDimension()));

		if (tree != nullptr) {
			tree->remove(node);
			return;
		}
	}

	for (unsigned int i = 0; i < m_nodes.size(); ++i)
	{
		if (m_nodes[i]->getPosition() == node->getPosition())
		{
			m_nodes.erase(m_nodes.begin() + i);
			return;
		}
	}
}


std::vector<Block*> QuadTree::queryRange(AABB area, int recursion)
{
	std::vector<Block*> list = m_nodes;
	if (m_isSubdivided)
	{
		QuadTree* tree = getIndex(area);
		if (tree != nullptr) {
			std::vector<Block*> res = tree->queryRange(area, recursion + 1);
			list.insert(list.end(), res.begin(), res.end());
		}
	}

	return list;
}

void QuadTree::clear()
{
	m_nodes.clear();
	
	if (m_isSubdivided) 
	{
		m_northEast->clear();
		m_northWest->clear();

		m_southEast->clear();
		m_southWest->clear();

		m_isSubdivided = false;
	}
}

QuadTree* QuadTree::getIndex(AABB bound)
{
	QuadTree* index = nullptr;
	double verticalMidpoint = m_bounds.position.x + (m_bounds.dimension.x / 2.0);
	double horizontalMidpoint = m_bounds.position.y + (m_bounds.dimension.y / 2.0);

	// Object can completely fit within the top quadrants
	bool topQuadrant = (bound.position.y < horizontalMidpoint && bound.position.y + bound.dimension.y < horizontalMidpoint);
	// Object can completely fit within the bottom quadrants
	bool bottomQuadrant = (bound.position.y > horizontalMidpoint);

	// Object can completely fit within the left quadrants
	if (bound.position.x < verticalMidpoint && bound.position.x + bound.dimension.x < verticalMidpoint) {
		if (topQuadrant) {
			index = m_northWest;
		}
		else if (bottomQuadrant) {
			index = m_southWest;
		}
	}
	// Object can completely fit within the right quadrants
	else if (bound.position.x > verticalMidpoint) {
		if (topQuadrant) {
			index = m_northEast;
		}
		else if (bottomQuadrant) {
			index = m_southEast;
		}
	}

	return index;
}

void QuadTree::debug()
{
	for (int i = 0; i < m_level; ++i)
		Debug::log("QuadTree.txt", "\t", true);
	Debug::log("QuadTree.txt", "Bounds : (" + std::to_string(m_bounds.position.x) + "," + std::to_string(m_bounds.position.y) + "),(" + std::to_string(m_bounds.dimension.x) + "," + std::to_string(m_bounds.dimension.y) + ") : "+std::to_string(getNumberOfNodes())+" "+std::to_string(m_northEast != nullptr) +"\n", true);

	for (int i = 0; i < m_nodes.size(); ++i)
	{
		for (int j = 0; j < m_level; ++j)
			Debug::log("QuadTree.txt", "\t", true);
		Debug::log("QuadTree.txt", "\tBounds block : (" + std::to_string(m_nodes[i]->getPosition().x * 4) + "," + std::to_string(m_nodes[i]->getPosition().y * 4) + "),(" + std::to_string(m_nodes[i]->getDimension().x) + "," + std::to_string(m_nodes[i]->getDimension().y) + ")\n", true);
	}

	if (m_isSubdivided)
	{
		m_northWest->debug();
		m_northEast->debug();
		m_southWest->debug();
		m_southEast->debug();
	}
}

int QuadTree::getNumberOfNodes()
{
	int total = m_nodes.size();
	if (m_isSubdivided)
	{
		total += m_northEast->getNumberOfNodes();
		total += m_northWest->getNumberOfNodes();
		total += m_southEast->getNumberOfNodes();
		total += m_southWest->getNumberOfNodes();
	}
	return total;
}

AABB QuadTree::getBound()
{
	return m_bounds;
}