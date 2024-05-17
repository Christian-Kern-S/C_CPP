#include "../INCLUDE/PhysicalAccount.hpp"
#include <gtest/gtest.h>

class test_PhysicalAccount : public PhysicalAccount, public ::testing::Test
{
};

TEST_F(test_PhysicalAccount, canSetCnpj)
{
    EXPECT_EQ(getDocument(),"");
    setDocument("11111111111");
    EXPECT_EQ(getDocument(),"11111111111");
}