#include "../INCLUDE/PhysicalAccount.hpp"
#include <gtest/gtest.h>

class test_PhysicalAccount : public PhysicalAccount, public ::testing::Test
{
public:
    test_PhysicalAccount() : PhysicalAccount(AccountType::PHYSICAL) {}
};

TEST_F(test_PhysicalAccount, CanSetAndGetName)
{
    setName("Test");
    EXPECT_EQ(getName(),"Test");
}

TEST_F(test_PhysicalAccount, CanSetAndGetBalance)
{
    setBalance(1000);
    EXPECT_EQ(getBalance(),1000);
}


TEST_F(test_PhysicalAccount, canSetCpf)
{
    EXPECT_EQ(getDocument(),"");
    setDocument("11111111111");
    setDocument("99734888000153");
    EXPECT_EQ(getDocument(),"");
    setDocument("74826780001");
    EXPECT_EQ(getDocument(),"74826780001");
}