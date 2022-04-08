#include "gtest/gtest.h"
#include "GlCard.h"
#define ONECARD_DEBUG
TEST(GlCardtest, inittest)
{
    Onecard::GlCard test(2);
    EXPECT_EQ(test.getcardlistsize(), 54) << "the size is " << test.getcardlistsize();
    test.init();
    EXPECT_EQ(test.getcardlistsize(), 108);
}
TEST(GlCardtest, gettest)
{

    Onecard::GlCard test(2);
    int a = test.getcardlistsize();
    test.getrandomcard();
    EXPECT_EQ(test.getcardlistsize(), a - 1);
}
TEST(GlCardtest, addtest)
{
    Onecard::GlCard test(2);
    int a = test.getcardlistsize();
    int b = test.getusecardsize();
    Onecard::Card c = test.getrandomcard();
    EXPECT_EQ(test.getcardlistsize(), a - 1);
    test.addcard(c);
    EXPECT_EQ(test.getusecardsize(), b + 1);
}