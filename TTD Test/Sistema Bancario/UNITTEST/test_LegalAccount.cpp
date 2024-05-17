#include "../INCLUDE/LegalAccount.hpp"
#include <gtest/gtest.h>

class test_LegalAccount : public LegalAccount, public ::testing::Test
{
};

TEST_F(test_LegalAccount, canSetCnpj)
{
    EXPECT_EQ(getDocument(),"");
    setDocument("11111111111111");
    EXPECT_EQ(getDocument(),"11111111111111");
}

TEST_F(test_LegalAccount, canSetRegistrationStatus)
{
    EXPECT_EQ(getRegistrationStatus(),"Active");
    setRegistrationStatus(0);
    EXPECT_EQ(getRegistrationStatus(),"Inactive");
    setRegistrationStatus(1);
    EXPECT_EQ(getRegistrationStatus(),"Active");
}

TEST_F(test_LegalAccount, canSetOpeningDate)
{
    EXPECT_EQ(getOpeningDate(),"00/00/0000");
    setOpeningDate("10","12","2001");
    EXPECT_EQ(getOpeningDate(),"10/12/2001");
}