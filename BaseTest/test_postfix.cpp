
#include "gtest/gtest.h"
#include "Postfix.cpp"

#include <ArrayTable.cpp>



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
/* решить проблему с переводом таблицы в абстрактную
TEST(TPostfix, can_calculate) {
	AbstractTable* table = nullptr;
	ArrayTable arrTable;
	Polynom tpol;
	TPostfix tpos("first+first");
	tpol.parseAndAddMonoms("2xyz");
	arrTable.insert("first", tpol);
	//table = (AbstractTable*) &arrTable;
	//EXPECT_EQ(16, tpos.Calculate(table, 2, 2, 2));
}
*/