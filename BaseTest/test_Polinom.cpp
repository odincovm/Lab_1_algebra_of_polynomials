#include "gtest/gtest.h"
#include "Polynom.h"




TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polynom tmp);
}
TEST(Polinom, can_print)
{
	Polynom tmp;
	ASSERT_NO_THROW(tmp.printPolynom());
}
//
TEST(Polinom, can_parseAndAddMonoms) {
	Polynom tmp;
	ASSERT_NO_THROW(tmp.parseAndAddMonoms("2x2y2z2"));
}
TEST(Polinom, can_calculate) {
	Polynom tmp;
	tmp.parseAndAddMonoms("2x2y2z2");
	EXPECT_EQ(128, tmp.calcPolynom(2, 2, 2));
}
TEST(Polinom, can_add) {
	Polynom tmp,tmp1;
	tmp.parseAndAddMonoms("2x2y2z2");
	tmp1 = tmp;
	tmp.addPolynom(tmp1);
	EXPECT_EQ(256, tmp.calcPolynom(2, 2, 2));
}

TEST(Polinom, can_multiply) {
	Polynom tmp, tmp1;
	tmp.parseAndAddMonoms("2x2y2z2");
	tmp1 = tmp;
	tmp.multiplyPolynom(tmp1);
	EXPECT_EQ(16384, tmp.calcPolynom(2, 2, 2));
}