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
	tmp.add("E", pol);
	EXPECT_NE(nullptr, tmp.Find("E"));
}
TEST(AVLTree, can_add)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	tmp.add("B", pol);
	EXPECT_NE(nullptr, tmp.Find("B"));
}
TEST(AVLTree, can_add_dublicate)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	tmp.add("B", pol);
	tmp.add("B", pol);
	EXPECT_EQ(2, tmp.getsize());
}
TEST(AVLTree, can_delete)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	tmp.add("B", pol);
	tmp.deleterecord("B");
	EXPECT_EQ(nullptr, tmp.Find("B"));
}
TEST(AVLTree, dont_delete_if_wrong_key) {
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	tmp.add("B", pol);
	tmp.deleterecord("C");
	EXPECT_EQ(2, tmp.getsize());
}
TEST(AVLTree, can_print)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	ASSERT_NO_THROW(tmp.Print());
}
TEST(AVLTree, can_balance)
{
	AVLTree tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.add("E", pol);
	tmp.add("B", pol);
	ASSERT_NO_THROW(tmp.add("A", pol));
	tmp.add("C", pol);
	ASSERT_NO_THROW(tmp.add("D", pol));
}

