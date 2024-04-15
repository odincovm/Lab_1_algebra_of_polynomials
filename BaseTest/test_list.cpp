
#include "gtest/gtest.h"
#include "../Project1/ListTable.h"
TEST(ListTable, can_create)
{
	ASSERT_NO_THROW(LinkedListTable tmp);
}
TEST(ListTable, can_add)
{
	LinkedListTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	EXPECT_EQ(1, tmp.getsize());
}


TEST(ListTable, can_delete)
{
	LinkedListTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	tmp.remove("test");
	EXPECT_EQ(0, tmp.getsize());
}
TEST(ListTable, cant_be_dublicate)
{
	LinkedListTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	tmp.insert("test", pol);
	EXPECT_EQ(1, tmp.getsize());
}
TEST(ListTable, can_find)
{
	LinkedListTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	ASSERT_NO_THROW(tmp.search("test"));
}
TEST(ListTable, can_print)
{
	LinkedListTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	ASSERT_NO_THROW(tmp.printTable());
}