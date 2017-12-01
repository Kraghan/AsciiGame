#pragma once
#include "AABB.h"
#include "Block.h"
#include <vector>

//https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
class QuadTree
{

private : 
	// Capacité en block d'un node quadtree
	static const unsigned short NODE_CAPACITY = 10;
	static const unsigned short MAX_LEVEL = 2;

	// Block contenu dedans
	std::vector<Block*> m_nodes;

	// Limit de ce block de quadtree
	AABB m_bounds;

	// Subdivisions
	QuadTree* m_northWest;
	QuadTree* m_northEast;
	QuadTree* m_southWest;
	QuadTree* m_southEast;

	// L'arbre à été splitté
	bool m_isSubdivided;

	// Niveau de profondeur dans le quadtree
	unsigned int m_level;

	// Retourne le morceau de quadtree adéquat
	QuadTree* getIndex(AABB bound);

public:
	// Constructors
	explicit QuadTree();

	explicit QuadTree(unsigned int level, AABB bounds);

	// Destructor
	virtual ~QuadTree();

	// Divise la quadmap en 4 sous partie
	void subdivide();

	// Insert un nouveau block
	void insert(Block* node);

	// Supprime un block
	void remove(Block* node);

	// Retourne les blocks contenu dans cette zone
	std::vector<Block*> queryRange(AABB area, int recursion = 0);

	// Vide le quadtree
	void clear();

	void debug();
	int getNumberOfNodes();
	AABB getBound();
};