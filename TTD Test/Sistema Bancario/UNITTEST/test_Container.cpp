#include "../INCLUDE/Container.hpp"
#include <gtest/gtest.h>

class test_Container : public Container, public testing::Test
{
public:
    int verifyAccount(int id)
    {
        if (_accounts.find(id) != _accounts.end())
        {
            return 1;
        }
        return 0;
    }
};

TEST_F(test_Container, canAddAccountInMap)
{
    Container::addAccount(AccountType::PHYSICAL);
    EXPECT_EQ(getTypeById(1),AccountType::PHYSICAL);

    Container::addAccount(AccountType::LEGAL);
    EXPECT_EQ(getTypeById(2),AccountType::LEGAL);

    Container::addAccount(AccountType::PHYSICAL);
    EXPECT_EQ(getTypeById(3),AccountType::PHYSICAL);

    EXPECT_EQ(getTypeById(4),AccountType::INVALID);
}

TEST_F(test_Container, canDeleteAccount)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    deleteAccount(1);
    EXPECT_EQ(verifyAccount(1),0);
    EXPECT_EQ(verifyAccount(2),1);
    deleteAccount(2);
    EXPECT_EQ(verifyAccount(2),0);
}