#include "StandardInclude.h"
#include "astar/NodeList.h"

class NodeListTest : public ::testing::Test
{
public:
	NodeList list;
};

TEST_F(NodeListTest, moveFromOpenToLock)
{
	ASSERT_TRUE(list.open.empty());
	ASSERT_TRUE(list.lock.empty());
	auto firstNode = std::make_unique<Node>();
	firstNode->setGCost(45);
	list.open.push_front(*firstNode.get());
	ASSERT_FALSE(list.open.empty());
	EXPECT_EQ(list.open.front().getGCost(), 45);
	list.moveFromOpenToLock();
	EXPECT_TRUE(list.open.empty());
	EXPECT_EQ(list.lock.size(), 1);
	EXPECT_EQ(list.lock.front().getGCost(), 45);
	list.open.clear();
	list.lock.clear();
	ASSERT_TRUE(list.open.empty());
	ASSERT_TRUE(list.lock.empty());

	Node secondNode;
	secondNode.setParent(firstNode.get());
	list.open.push_front(*firstNode.get());
	list.open.push_front(secondNode);
	list.moveFromOpenToLock();
	EXPECT_EQ(list.lock.size(), 1);
	ASSERT_EQ(*(list.lock.front().getParent()), list.open.front());
}

TEST_F(NodeListTest, sort)
{
	Node elements[5];
	elements[0].setGCost(4);
	elements[1].setGCost(3);
	elements[2].setGCost(2);
	elements[3].setGCost(1);
	elements[4].setGCost(0);

	elements[0].setHCost(10);
	elements[1].setHCost(20);
	elements[2].setHCost(0);
	elements[3].setHCost(30);
	elements[4].setHCost(40);

	for(auto &i : elements)
	{
		list.open.push_front(i);
		list.lock.push_front(i);
	}
	EXPECT_EQ(list.open.front().getFCost(), 40);
	EXPECT_EQ(list.open.back().getFCost(), 14);

	list.open.sort(NodeList::sortAscending);

	EXPECT_EQ(list.open.front().getFCost(), 2);
	EXPECT_EQ(list.open.back().getFCost(), 40);

	list.open.sort(NodeList::sortDescending);

	EXPECT_EQ(list.open.front().getFCost(), 40);
	EXPECT_EQ(list.open.back().getFCost(), 2);
}