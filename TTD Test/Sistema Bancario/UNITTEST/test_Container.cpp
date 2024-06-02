#include "../MOCKS/MockObserver.hpp"
#include "../INCLUDE/Container.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


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
    EXPECT_FALSE(Container::setAccountName(3,"Kern's Corporation"));
}

TEST_F(test_Container, canSetAccountCnpj)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_FALSE(Container::setAccountDocument(1,"11111111111111"));
    EXPECT_FALSE(Container::setAccountDocument(1,"89634098000142"));
    EXPECT_FALSE(Container::setAccountDocument(2,"11111111111111"));
    EXPECT_TRUE(Container::setAccountDocument(2,"89634098000142"));
    EXPECT_EQ(Container::getDocumentById(1),"");
    EXPECT_EQ(Container::getDocumentById(2),"89634098000142");
    EXPECT_EQ(Container::getDocumentById(3),"Invalid");
}

TEST_F(test_Container, canSetAccountCpf)
{
    
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_FALSE(Container::setAccountDocument(2,"11111111111"));
    EXPECT_FALSE(Container::setAccountDocument(1,"11111111111"));
    EXPECT_TRUE(Container::setAccountDocument(1,"59458078008"));
    EXPECT_EQ(Container::getDocumentById(1),"59458078008");
    EXPECT_EQ(Container::getDocumentById(2),"");
    EXPECT_EQ(Container::getDocumentById(3),"Invalid");
}

TEST_F(test_Container, canSetAccountRegistrationStatus)
{
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    EXPECT_FALSE(Container::setAccountRegistrationStatus(1,1));
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
    EXPECT_FALSE(Container::setAccountOpeningDate(1,"11","11","2001"));
    EXPECT_TRUE(Container::setAccountOpeningDate(2,"11","11","2001"));
    EXPECT_EQ(Container::getOpeningDateById(1),"Invalid");
    EXPECT_EQ(Container::getOpeningDateById(2),"11/11/2001");
}

TEST_F(test_Container, canGetNotification)
{
    MockObserver mockObserver;
    int expectedValue = 2;
    EXPECT_CALL(mockObserver, update(expectedValue));
    addObserver(mockObserver);
    addAccount(AccountType::LEGAL);
}

TEST_F(test_Container, canGetIsPremium)
{
    Container::addAccount(AccountType::PREMIUM_PHYSICAL);
    Container::addAccount(AccountType::LEGAL);
    Container::addAccount(AccountType::PHYSICAL);
    Container::addAccount(AccountType::PREMIUM_LEGAL);

    EXPECT_TRUE(Container::isAccountValid(1));
    EXPECT_FALSE(Container::isAccountValid(2));
    EXPECT_FALSE(Container::isAccountValid(3));
    EXPECT_TRUE(Container::isAccountValid(4));
}