#include <gtest/gtest.h>
#include "../INCLUDE/Multiplication.hpp"

class test_Multiplication : public Multiplication, public ::testing::Test
{
};

TEST_F(test_Multiplication, canMultiplyTwoNumbers)
{
    EXPECT_EQ(multiply(5,5), 25);
    EXPECT_EQ(getNumber1(),5);
    EXPECT_EQ(getNumber2(),5);
    reset();
}