#include "../gtest/gtest.h"

#include "HashTable.cpp"

#include "TABLES/Polynom.h"


TEST(HashTable, can_create)
{
	ASSERT_NO_THROW(HashTable tmp);
}

TEST(HashTable, can_add_and_find)
{
	HashTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("first", pol);
	ASSERT_NO_THROW(tmp.search("first"));
}
TEST(HashTable, cant_be_dublicate)
{
	HashTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("first", pol);
	tmp.insert("first", pol);
	EXPECT_EQ(1, tmp.getsize());
}

TEST(HashTable, can_delete)
{
	HashTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("first", pol);
	tmp.remove("first");
	ASSERT_ANY_THROW(tmp.search("first"));
}

TEST(HashTable, can_print)
{
	HashTable tmp;
	Polynom pol;
	pol.parseAndAddMonoms("2x2y2z2");
	tmp.insert("first", pol);
	ASSERT_NO_THROW(tmp.printTable());
}