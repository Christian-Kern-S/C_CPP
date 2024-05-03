#include <gtest/gtest.h>
#include "../INCLUDE/Division.hpp"

class test_Division : public Division, public ::testing::Test
{
};

TEST_F(test_Division, canDivideTwoNumbers)
{
    EXPECT_EQ(divide(10,5),2);
    EXPECT_EQ(getNumber1(),10);
    EXPECT_EQ(getNumber2(),5);
    reset();
}