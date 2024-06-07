#include <gtest/gtest.h>
#include "../INCLUDE/Deposit.hpp"
#include "../INCLUDE/Container.hpp"

class test_Deposit : public Deposit, public ::testing::Test
{
public:
    test_Deposit() : Deposit(myContainer){}
    void Test_addAccount(AccountType type)
    {
        myContainer.addAccount(type);
    }

    double Test_getBalanceById(int id)
    {
       return myContainer.getBalanceById(id);
    }
    bool Test_upgradeAccount(int id)
    {
        return myContainer.upgradeAccount(id);
    }
private:
    Container myContainer;
};

TEST_F(test_Deposit, canAddMoney)
{
    Test_addAccount(AccountType::PHYSICAL);
    Test_addAccount(AccountType::PHYSICAL);
    Test_addAccount(AccountType::LEGAL);

    deposit(1,1000);
    deposit(2,900);
    deposit(3,800);

    EXPECT_EQ(Test_getBalanceById(1),1000);
    EXPECT_EQ(Test_getBalanceById(2),900);
    EXPECT_EQ(Test_getBalanceById(3),800);
    EXPECT_FALSE(deposit(4,100));
    Test_upgradeAccount(1);
    EXPECT_EQ(Test_getBalanceById(1),1000);
}