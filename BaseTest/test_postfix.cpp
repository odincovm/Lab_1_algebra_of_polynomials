
#include "gtest/gtest.h"
#include "Postfix.cpp"

#include "ListTable.h"



TEST(TPostfix, can_create_postfix)
{

	ASSERT_NO_THROW(TPostfix p("a+b*c"));
}

TEST(TPostfix, can_get_infix) {
	TPostfix p("a+b*c");
	EXPECT_EQ("a+b*c", p.GetInfix());
}

TEST(TPostfix, can_get_postfix) {
	TPostfix p("a+b*c");
	vector <string> ans { "a","b","c","*","+"};
	EXPECT_EQ(ans, p.GetPostfix());
}

TEST(TPostfix, can_calculate) {
	AbstractTable* table = nullptr;
	LinkedListTable arrTable;
	Polynom tpol;
	TPostfix tpos("first+first");
	tpol.parseAndAddMonoms("2xyz");
	arrTable.insert("first", tpol);
	EXPECT_EQ(32, tpos.Calculate(&arrTable, 2, 2, 2));
}
TEST(TPostfix, can_calculate_with_staples) {
	AbstractTable* table = nullptr;
	LinkedListTable arrTable;
	Polynom tpol;
	TPostfix tpos("a+(a*a)");
	tpol.parseAndAddMonoms("2xyz");
	arrTable.insert("a", tpol);
	EXPECT_EQ(272, tpos.Calculate(&arrTable, 2, 2, 2));
}