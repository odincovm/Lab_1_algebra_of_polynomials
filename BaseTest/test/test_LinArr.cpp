#include "../gtest/gtest.h"

#include <LinearArrayTable.cpp>
#include <Polynom.cpp>




TEST(TLinTable, can_create)
{
	ASSERT_NO_THROW(LinearArrayTable tmp);
}
TEST(TLinTable, can_add)
{
	LinearArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	EXPECT_EQ(1, tmp.getsize());
}
TEST(TLinTable, cant_be_dublicate)
{
	LinearArrayTable tmp;
	Polynom pol, pol2;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	pol2.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol2);
	EXPECT_EQ(1, tmp.getsize());
}
TEST(TLinTable, can_delete)
{
	LinearArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	tmp.deleteRecord("test");
	EXPECT_EQ(0, tmp.getsize());
}
TEST(TLinTable, dont_delete_if_wrong_key)
{
	LinearArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	tmp.deleteRecord("not_test");
	EXPECT_EQ(1, tmp.getsize());
}
TEST(TLinTable, can_find)
{
	LinearArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	EXPECT_NE(nullptr, tmp.find("test"));
}
TEST(TLinTable, can_print)
{
	LinearArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	ASSERT_NO_THROW(tmp.printTable());
}