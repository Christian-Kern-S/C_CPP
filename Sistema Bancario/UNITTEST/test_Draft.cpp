#include <gtest/gtest.h>
#include "../INCLUDE/Draft.hpp"

#include <iostream>

class test_Draft : public Draft, public ::testing::Test
{
public:
    test_Draft() : Draft(myContainer), _deposit(myContainer), myContainer(){}
    void Test_addAccount(AccountType type)
    {
        myContainer.addAccount(type);
    }
    void Test_deposit(int id, double value)
    {
        _deposit.deposit(2,300);
    }
    double Test_getBalanceById(int id)
    {
       return myContainer.getBalanceById(id);
    }
private:
    Deposit _deposit;
    Container myContainer;
};

TEST_F(test_Draft, CanWithdrawMoney)
{
    Test_addAccount(AccountType::LEGAL);
    Test_addAccount(AccountType::PHYSICAL);
    Test_deposit(2,300);
    withdraw(2,100);

    EXPECT_EQ(Test_getBalanceById(2),200);
    EXPECT_EQ(Test_getBalanceById(1),0);

    EXPECT_EQ(withdraw(2,100),1);
    EXPECT_EQ(withdraw(1,100),0);
}