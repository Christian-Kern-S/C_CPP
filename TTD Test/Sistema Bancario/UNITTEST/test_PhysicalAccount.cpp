#include "../INCLUDE/PhysicalAccount.hpp"
#include <gtest/gtest.h>

class test_PhysicalAccount : public PhysicalAccount, public ::testing::Test
{
};

TEST_F(test_PhysicalAccount, canSetCnpj)
{
    EXPECT_EQ(getCpf(),"0");
    setCpf("11111111111");
    EXPECT_EQ(getCpf(),"11111111111");
}