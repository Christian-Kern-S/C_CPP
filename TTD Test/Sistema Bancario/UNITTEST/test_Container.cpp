#include "../INCLUDE/Container.hpp"
#include <gtest/gtest.h>

class test_Container : public Container, public testing::Test
{
public:
    int verifyAccount(int id)
    {
        if (_accounts.find(id) != _accounts.end())
        {
            return true;
        }
        return false;
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
    EXPECT_EQ(verifyAccount(1),false);
    EXPECT_EQ(verifyAccount(2),true);
    deleteAccount(2);
    EXPECT_EQ(verifyAccount(2),false);
}

TEST_F(test_Container, canSetAccountName)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_TRUE(Container::setAccountName(1,"Christian"));
    EXPECT_TRUE(Container::setAccountName(2,"Kern's Corporation"));
    EXPECT_EQ(Container::getNameById(1),"Christian");
    EXPECT_EQ(Container::getNameById(2),"Kern's Corporation");
}

TEST_F(test_Container, canSetAccountCnpj)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_EQ(Container::setAccountCnpj(1,"11111111111111"),false);
    EXPECT_TRUE(Container::setAccountCnpj(2,"11111111111111"));
    EXPECT_EQ(Container::getCnpjById(1),"false");
    EXPECT_EQ(Container::getCnpjById(2),"11111111111111");
}

TEST_F(test_Container, canSetAccountCpf)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_EQ(Container::setAccountCpf(2,"11111111111"),false);
    EXPECT_TRUE(Container::setAccountCpf(1,"11111111111"));
    EXPECT_EQ(Container::getCpfById(1),"11111111111");
    EXPECT_EQ(Container::getCpfById(2),"false");
}

TEST_F(test_Container, canSetAccountRegistrationStatus)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    //EXPECT_FALSE(Container::setAccountRegistrationStatus(1,1));
    EXPECT_TRUE(Container::setAccountRegistrationStatus(2,0));
    EXPECT_EQ(Container::getRegistrationStatusById(1),"Invalid");
    EXPECT_EQ(Container::getRegistrationStatusById(2),"Inactive");
    EXPECT_TRUE(Container::setAccountRegistrationStatus(2,1));
    EXPECT_EQ(Container::getRegistrationStatusById(2),"Active");
}

TEST_F(test_Container, canSetAccountOpeningDate)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    //EXPECT_FALSE(Container::setAccountOpeningDate(1,"11","11","2001"));
    EXPECT_TRUE(Container::setAccountOpeningDate(2,"11","11","2001"));
    EXPECT_EQ(Container::getOpeningDateById(1),"Invalid");
    EXPECT_EQ(Container::getOpeningDateById(2),"11/11/2001");
}