#include <ArrayTable.cpp>
#include "gtest/gtest.h"
TEST(ArrayTable, Can_Add_Polynom_To_ArrayTable) {
	ArrayTable a;
	string pol = "2x3+4y2+5z1";
	Polynom temp;
	temp.parseAndAddMonoms(pol);
	a.insert("A", temp);
	EXPECT_EQ(a.getsize(), 1);
}

TEST(ArrayTable, can_create)
{
	ASSERT_NO_THROW(ArrayTable tmp);
}

TEST(ArrayTable, cant_be_dublicate)
{
	ArrayTable tmp;
	Polynom pol, pol2;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	pol2.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol2);
	EXPECT_EQ(1, tmp.getsize());
}
TEST(ArrayTable, can_delete)
{
	ArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	tmp.remove("test");
	EXPECT_EQ(0, tmp.getsize());
}

TEST(ArrayTable, can_print)
{
	ArrayTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("test", pol);
	ASSERT_NO_THROW(tmp.printTable());
}