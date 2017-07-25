#pragma once

#include "Node.h"
#include <list>

class NodeList
{
public:
	std::list<Node> open, lock;
	void moveFromOpenToLock();

	bool static sortAscending(const Node &lhs, const Node &rhs);
	bool static sortDescending(const Node &lhs, const Node &rhs);
};