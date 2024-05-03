#include <gtest/gtest.h>
#include "../INCLUDE/Calculator.hpp"

class test_Calculator : public Calculator, public ::testing::Test
{
};

TEST_F(test_Calculator, canSetTwoNumbers)
{
    setNumber1(1);
    setNumber2(2);
    EXPECT_EQ(getNumber1(), 1);
    EXPECT_EQ(getNumber2(), 2);
    reset();
}