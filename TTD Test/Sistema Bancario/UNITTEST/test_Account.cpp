#include <gtest/gtest.h>
#include "../INCLUDE/Account.hpp"

class test_Account : public Account, public ::testing::Test
{
public:
    test_Account() : Account(AccountType::INVALID), ::testing::Test()
    {
    }
};

TEST_F(test_Account, CanSetAndGetName)
{
    setName("Test");
    EXPECT_EQ(getName(),"Test");
}

TEST_F(test_Account, CanSetAndGetBalance)
{
    setBalance(1000);
    EXPECT_EQ(getBalance(),1000);
}