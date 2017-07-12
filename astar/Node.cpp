#include "Node.h"

void Node::setParent(Node *parentNode) {
	parent = parentNode;
}

void Node::setGCost(int value) {
	GCost = value;
}

void Node::setHCost(int value) {
	HCost = value;
}

Node *Node::getParent() const {
	return parent;
}

Node::Node() {
	setParent(nullptr);
	setArea(nullptr);
	setGCost(0);
	setHCost(-1);
}

int Node::getGCost() const {
	return GCost;
}

int Node::getPathCost() const {
	if (!parent)
		return GCost;
	return parent->getPathCost() + GCost;
}

int Node::getFCost() const{
	return getPathCost() + getHCost();
}

int Node::getHCost() const{
	return HCost;
}

bool Node::operator==(const Node otherNode) const {
	if(this->getArea() == otherNode.getArea() && this->getParent() == otherNode.getParent())
		return true;
	return false;
}

Area * Node::getArea() const {
	return field;
}

void Node::setArea(Area *otherField) {
	field = otherField;
}

bool Node::operator!=(const Node otherNode) const {
	return !(*this == otherNode);
}
