#include "../Misha/AVLtree.cpp"
#include "../gtest/gtest.h"
#include <Polynom.h>



TEST(AVLTree, can_create)
{
	ASSERT_NO_THROW(AVLTree tmp);
}

TEST(AVLTree, can_add_root)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	EXPECT_NE(nullptr, tmp.search("E"));
}
TEST(AVLTree, can_add)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	tmp.insert("B", pol);
	EXPECT_NE(nullptr, tmp.search("B"));
}
TEST(AVLTree, can_add_dublicate)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	tmp.insert("B", pol);
	tmp.insert("B", pol);
	EXPECT_EQ(2, tmp.getsize());
}
TEST(AVLTree, can_delete)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	tmp.insert("B", pol);
	tmp.remove("B");
	EXPECT_EQ(nullptr, tmp.search("B"));
}
TEST(AVLTree, dont_delete_if_wrong_key) {
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	tmp.insert("B", pol);
	tmp.remove("C");
	EXPECT_EQ(2, tmp.getsize());
}
TEST(AVLTree, can_print)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	ASSERT_NO_THROW(tmp.printTable());
}
TEST(AVLTree, can_balance)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("E", pol);
	tmp.insert("B", pol);
	ASSERT_NO_THROW(tmp.insert("A", pol));
	tmp.insert("C", pol);
	ASSERT_NO_THROW(tmp.insert("D", pol));
}

