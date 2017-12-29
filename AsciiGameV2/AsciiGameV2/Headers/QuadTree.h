#pragma once
#include "AABB.h"
#include "Block.h"
#include <vector>

//https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
class QuadTree
{

private : 
	// Capacité en block d'un node quadtree
	static const unsigned short NODE_CAPACITY = 40;
	static const unsigned short MAX_LEVEL = 5;

	// Block contenu dedans
	std::vector<Block*> m_nodes;

	// Limit de ce block de quadtree
	AABBf m_bounds;

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
	QuadTree* getIndex(AABBf bound);

public:
	// Constructors
	explicit QuadTree();

	explicit QuadTree(unsigned int level, AABBf bounds);

	// Destructor
	virtual ~QuadTree();

	// Divise la quadmap en 4 sous partie
	void subdivide();

	// Insert un nouveau block
	void insert(Block* node);

	// Supprime un block
	void remove(Block* node);

	// Retourne les blocks autour du block area
	std::vector<Block*> queryRange(AABBf area, int recursion = 0);

	// Retourne les blocks dans la zone area
	std::vector<Block*> getInArea(AABBf area);

	// Retourne tous les blocks
	std::vector<Block*> getAll();

	// Vide le quadtree
	void clear();

	void debug();
	int getNumberOfNodes();
	AABBf getBound();
};