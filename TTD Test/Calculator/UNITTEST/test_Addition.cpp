#include <gtest/gtest.h>
#include "../INCLUDE/Addition.hpp"

class test_Addition : public Addition, public ::testing::Test
{
};

TEST_F(test_Addition, CanAddTwoNumbers)
{
    EXPECT_EQ(sum(1, 2), 3);
    EXPECT_EQ(getNumber1(), 1);
    EXPECT_EQ(getNumber2(), 2);
    reset();
}

TEST_F(test_Addition, CanResetNumbers)
{
    setNumber1(2);
    setNumber2(1);
    reset();
    EXPECT_EQ(getNumber1(), 0);
    EXPECT_EQ(getNumber2(), 0);
    reset();
}