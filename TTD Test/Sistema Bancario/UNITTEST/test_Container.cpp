#include "../INCLUDE/Container.hpp"
#include <gtest/gtest.h>

class test_Accountiner : public Container, public testing::Test
{
};

TEST_F(test_Accountiner, canAddAccountInMap)
{
    Container::addAccount(AccountType::PHYSICAL);
    EXPECT_EQ(getTypeById(1),AccountType::PHYSICAL);

    Container::addAccount(AccountType::LEGAL);
    EXPECT_EQ(getTypeById(2),AccountType::LEGAL);

    Container::addAccount(AccountType::PHYSICAL);
    EXPECT_EQ(getTypeById(3),AccountType::PHYSICAL);

    EXPECT_EQ(getTypeById(4),AccountType::INVALID);
}