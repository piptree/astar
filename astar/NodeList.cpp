#include "NodeList.h"

void NodeList::moveFromOpenToLock()
{
	lock.push_front(open.front());
	open.pop_front();
}

bool NodeList::sortAscending(const Node &lhs, const Node &rhs) {
	return lhs.getFCost() < rhs.getFCost();
}

bool NodeList::sortDescending(const Node &lhs, const Node &rhs) {
	return lhs.getFCost() > rhs.getFCost();
}

