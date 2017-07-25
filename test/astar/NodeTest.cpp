#include "StandardInclude.h"
#include "astar/Node.h"

class NodeTest : public ::testing::Test
{
public:
	Node node;
};

TEST_F(NodeTest, setParent) {
	EXPECT_EQ(node.getParent(), nullptr);
	Node parentNode;
	node.setParent(&parentNode);
	EXPECT_EQ(node.getParent(), &parentNode);
	node.setParent(nullptr);
	EXPECT_EQ(node.getParent(), nullptr);
}

TEST_F(NodeTest, GCost) {
	EXPECT_EQ(node.getGCost(), 0);
	node.setGCost(15);
	EXPECT_EQ(node.getGCost(), 15);
	node.setGCost(-7);
	EXPECT_EQ(node.getGCost(), -7);
}

TEST_F(NodeTest, pathCost) {
	EXPECT_EQ(node.getGCost(), 0);
	node.setGCost(15);

	Node parentNode;
	parentNode.setGCost(20);

	node.setParent(&parentNode);
	EXPECT_EQ(node.getPathCost(), 35);
	parentNode.setGCost(-5);
	ASSERT_EQ(parentNode.getPathCost(), -5);
	EXPECT_EQ(node.getPathCost(), 10);

	Node grandNode;
	grandNode.setGCost(73);
	parentNode.setParent(&grandNode);
	EXPECT_EQ(parentNode.getPathCost(), 68);
	EXPECT_EQ(node.getPathCost(), 83);
	parentNode.setGCost(10);
	EXPECT_EQ(parentNode.getPathCost(), 83);
	EXPECT_EQ(node.getPathCost(), 98);
}

TEST_F(NodeTest, HCost) {
	EXPECT_EQ(node.getHCost(), -1);
	node.setHCost(15);
	EXPECT_EQ(node.getHCost(), 15);
	node.setHCost(-7);
	EXPECT_EQ(node.getHCost(), -7);
}

TEST_F(NodeTest, FCost) {
	Node grandNode;
	Node parentNode;

	parentNode.setParent(&grandNode);
	node.setParent(&parentNode);

	grandNode.setHCost(100);
	parentNode.setHCost(80);
	node.setHCost(60);

	grandNode.setGCost(92);
	parentNode.setGCost(14);
	node.setGCost(14);

	EXPECT_EQ(node.getFCost(), 180);

	grandNode.setHCost(90);
	parentNode.setHCost(100);
	node.setHCost(110);

	grandNode.setGCost(42);
	parentNode.setGCost(10);
	node.setGCost(10);

	EXPECT_EQ(node.getFCost(), 172);
}


TEST_F(NodeTest, setField) {
	EXPECT_EQ(node.getArea(), nullptr);
	Area * field;
	node.setArea(field);
	EXPECT_EQ(node.getArea(), field);
	node.setArea(nullptr);
	EXPECT_EQ(node.getArea(), nullptr);
}


TEST_F(NodeTest, comparisonNode) {
	Node anotherNode;
	EXPECT_EQ(node, anotherNode);

	Node * parentNode;
	Area * field;
	node.setArea(field);
	node.setParent(parentNode);

	anotherNode.setArea(field);
	anotherNode.setParent(parentNode);

	EXPECT_EQ(node, anotherNode);
	anotherNode.setParent(nullptr);
	EXPECT_NE(node, anotherNode);
}
