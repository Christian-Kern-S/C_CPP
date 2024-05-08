#include <gtest/gtest.h>
#include "../INCLUDE/Transfer.hpp"
#include "../INCLUDE/Deposit.hpp"

class test_Transfer : public Transfer, public ::testing::Test
{
public:
    test_Transfer() : Transfer(myContainer), _deposit(myContainer){}
    void Test_addAccount(AccountType type)
    {
        myContainer.addAccount(type);
    }
    void Test_deposit(int id, double value)
    {
        _deposit.deposit(id,value);
    }
    double Test_getBalanceById(int id)
    {
       return myContainer.getBalanceById(id);
    }
private:
    Deposit _deposit;
    Container myContainer;
};

TEST_F(test_Transfer, CanTransferMoney)
{
    Test_addAccount(AccountType::LEGAL);
    Test_addAccount(AccountType::PHYSICAL);

    Test_deposit(1,100);
    Test_deposit(2,200);

    transfer(1,50,2);
    EXPECT_EQ(Test_getBalanceById(1),50);
    EXPECT_EQ(Test_getBalanceById(2),250);

    transfer(2,200,1);
    EXPECT_EQ(Test_getBalanceById(1),250);
    EXPECT_EQ(Test_getBalanceById(2),50);
}