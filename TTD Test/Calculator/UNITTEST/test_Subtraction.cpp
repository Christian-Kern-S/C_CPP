#include <gtest/gtest.h>
#include "../INCLUDE/Subtraction.hpp"

class test_Subtraction : public Subtraction, public ::testing::Test
{
};

TEST_F(test_Subtraction, canSubtractTwoNumbers)
{
    EXPECT_EQ(subtract(4,3),1);
    EXPECT_EQ(getNumber1(),4);
    EXPECT_EQ(getNumber2(),3);
    reset();
}