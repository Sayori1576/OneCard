#include "gtest/gtest.h"
#include "GlCard.h"
TEST(GlCardtest, inittest)
{
    Onecard::GlCard test(2);
    EXPECT_EQ(test.getcardlistsize(), 54) << "the size is " << test.getcardlistsize();
}