#pragma once

#include "Area.h"

class Node
{
	Node * parent;
	Area * field;
	int GCost, HCost;

public:
	void setParent(Node * parentNode);
	void setArea(Area *otherField);
	void setGCost(int value);
	void setHCost(int value);

	int getGCost() const;
	int getHCost() const;
	int getFCost() const;
	int getPathCost() const;

	Node * getParent() const;
	Node();

	Area * getArea() const;

	bool operator==(const Node otherNode) const;
	bool operator!=(const Node otherNode) const;
};