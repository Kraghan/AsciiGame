#include "../Headers/QuadTree.h"
#include "../Headers/Debug.h"

/*Explicit*/ QuadTree::QuadTree()
	: m_bounds(AABBf())
	, m_northEast(nullptr)
	, m_northWest(nullptr)
	, m_southEast(nullptr)
	, m_southWest(nullptr)
	, m_isSubdivided(false)
	, m_level(0) 
{
	m_nodes.reserve(NODE_CAPACITY);
}

/*Explicit*/ QuadTree::QuadTree(unsigned int level, AABBf bounds)
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
	if (m_northEast != nullptr)
	{
		delete(m_northEast);
		delete(m_northWest);
		delete(m_southEast);
		delete(m_southWest);
	}
	
}

void QuadTree::subdivide()
{
	float subWidth = (m_bounds.dimension.x / 2);
	float subHeight = (m_bounds.dimension.y / 2);
	float x = m_bounds.position.x;
	float y = m_bounds.position.y;

	if (m_northEast == nullptr)
	{
		m_northEast = new QuadTree(m_level + 1, AABBf(x + subWidth, y, subWidth, subHeight));
		m_northWest = new QuadTree(m_level + 1, AABBf(x, y, subWidth, subHeight));
		m_southWest = new QuadTree(m_level + 1, AABBf(x, y + subHeight, subWidth, subHeight));
		m_southEast = new QuadTree(m_level + 1, AABBf(x + subWidth, y + subHeight, subWidth, subHeight));

	}

	m_isSubdivided = true;
}

void QuadTree::insert(Block* node)
{
	// Si le tree est splitté on essaie de le refourguer aux enfants
	if (m_isSubdivided)
	{
		QuadTree* tree = getIndex(AABBf(Vector2f(node->getBounds().getX(), node->getBounds().getY()), 
			Vector2f(node->getBounds().getWidth(), node->getBounds().getHeight())));
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
			for (unsigned int i = 0; i < m_nodes.size(); ++i)
			{
				QuadTree* tree = getIndex(AABBf(Vector2f(m_nodes[i]->getBounds().getX(), m_nodes[i]->getBounds().getY()),
					Vector2f(m_nodes[i]->getBounds().getWidth(), m_nodes[i]->getBounds().getHeight())));
				if (tree != nullptr)
				{
					tree->insert(m_nodes[i]);
				}
			}
		}
	}
}

void QuadTree::remove(Block* node)
{
	if (m_isSubdivided)
	{
		QuadTree* tree = getIndex(AABBf(Vector2f(node->getBounds().getX(), node->getBounds().getY()),
			Vector2f(node->getBounds().getWidth(), node->getBounds().getHeight())));

		if (tree != nullptr) {
			tree->remove(node);
		}
	}

	for (unsigned int i = 0; i < m_nodes.size(); )
	{
		if (!m_nodes[i]->unbreakable() && m_nodes[i]->solid() && m_nodes[i]->getPosition() == node->getPosition())
		{
			m_nodes.erase(m_nodes.begin() + i);
		}
		else
			++i;
	}
}


std::vector<Block*> QuadTree::queryRange(AABBf area, int recursion)
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

QuadTree* QuadTree::getIndex(AABBf bound)
{
	if (m_northEast->getBound().contains(bound))
		return m_northEast;
	if (m_northWest->getBound().contains(bound))
		return m_northWest;
	if (m_southEast->getBound().contains(bound))
		return m_southEast;
	if (m_southWest->getBound().contains(bound))
		return m_southWest;
	return nullptr;
}

void QuadTree::debug()
{
	for (unsigned int i = 0; i < m_level; ++i)
		Debug::log("QuadTree.txt", "\t", true);
	Debug::log("QuadTree.txt", "Bounds : (" + std::to_string(m_bounds.position.x) + "," + std::to_string(m_bounds.position.y) + "),(" + std::to_string(m_bounds.dimension.x) + "," + std::to_string(m_bounds.dimension.y) + ") : "+std::to_string(getNumberOfNodes())+" "+std::to_string(m_northEast != nullptr) +"\n", true);

	for (unsigned int i = 0; i < m_nodes.size(); ++i)
	{
		for (unsigned int j = 0; j < m_level; ++j)
			Debug::log("QuadTree.txt", "\t", true);
		Debug::log("QuadTree.txt", "\tBounds block : (" + std::to_string(m_nodes[i]->getPosition().x) + "," + std::to_string(m_nodes[i]->getPosition().y) + "),(" + std::to_string(m_nodes[i]->getDimension().x) + "," + std::to_string(m_nodes[i]->getDimension().y) + ")\n", true);
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

AABBf QuadTree::getBound()
{
	return m_bounds;
}

std::vector<Block*> QuadTree::getInArea(AABBf area)
{
	std::vector<Block*> vec = std::vector<Block*>();

	if (!area.intersect(m_bounds))
	{
		return vec;
	}

	for (unsigned int i = 0; i < m_nodes.size(); ++i)
	{
		// Don't know if intersects or contains
		if (area.intersect(AABBf(Vector2f(m_nodes[i]->getBounds().getX(), m_nodes[i]->getBounds().getY()),
			Vector2f(m_nodes[i]->getBounds().getWidth(), m_nodes[i]->getBounds().getHeight()))))
		{
			vec.push_back(m_nodes[i]);
		}
	}

	if (m_isSubdivided)
	{
		std::vector<Block*> subQuery = std::vector<Block*>();

		subQuery = m_northEast->getInArea(area);
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_northWest->getInArea(area);
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_southEast->getInArea(area);
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_southWest->getInArea(area);
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
	}

	return vec;
}


std::vector<Block*> QuadTree::getAll()
{
	std::vector<Block*> vec = m_nodes;

	if (m_isSubdivided)
	{
		std::vector<Block*> subQuery = std::vector<Block*>();

		subQuery = m_northEast->getAll();
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_northWest->getAll();
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_southEast->getAll();
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
		subQuery = m_southWest->getAll();
		vec.insert(vec.end(), subQuery.begin(), subQuery.end());
	}

	return vec;
}