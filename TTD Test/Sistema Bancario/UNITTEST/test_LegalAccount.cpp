#include "../INCLUDE/LegalAccount.hpp"
#include <gtest/gtest.h>

class test_LegalAccount : public LegalAccount, public ::testing::Test
{
public:
    test_LegalAccount() : LegalAccount(AccountType::LEGAL) {}
};

TEST_F(test_LegalAccount, CanSetAndGetName)
{
    setName("Test");
    EXPECT_EQ(getName(),"Test");
}

TEST_F(test_LegalAccount, CanSetAndGetBalance)
{
    setBalance(1000);
    EXPECT_EQ(getBalance(),1000);
}

TEST_F(test_LegalAccount, canSetCnpj)
{
    EXPECT_EQ(getDocument(),"");
    setDocument("11111111111111");
    setDocument("74826780001");
    EXPECT_EQ(getDocument(),"");
    setDocument("99734888000153");
    EXPECT_EQ(getDocument(),"99734888000153");
}

TEST_F(test_LegalAccount, canSetRegistrationStatus)
{
    EXPECT_EQ(getRegistrationStatus(),"Active");
    setRegistrationStatus("Inactive");
    EXPECT_EQ(getRegistrationStatus(),"Inactive");
    setRegistrationStatus("Active");
    EXPECT_EQ(getRegistrationStatus(),"Active");
}

TEST_F(test_LegalAccount, canSetOpeningDate)
{
    EXPECT_EQ(getOpeningDate(),"00/00/0000");
    setOpeningDate("10/12/2001");
    EXPECT_EQ(getOpeningDate(),"10/12/2001");
}