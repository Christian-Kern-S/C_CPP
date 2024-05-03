#include <gtest/gtest.h>
#include "../INCLUDE/Bank.hpp"
#include <iostream>

class test_Bank : public ::testing::TestWithParam<AccountType>
{
public:
    Bank& bank = Bank::getInstance();

    std::string myAccount(AccountType t)
    {
        switch (t)
        {
        case AccountType::PHYSICAL:
            return "Physical Account";
            break;
        case AccountType::LEGAL:
            return "Legal Account";
            break;

        default:
            return "";
            break;
        }
    }
};

TEST_P(test_Bank,canCreateAccounts)
{
    const AccountType& params = GetParam();
    auto actual = bank.create(params);
    auto expected = myAccount(params);
    EXPECT_EQ(actual->getName(),expected);

}

INSTANTIATE_TEST_SUITE_P(
    ParameterizedBankFactoryTest,
    test_Bank,
    ::testing::Values(
        AccountType::PHYSICAL,
        AccountType::LEGAL,
        AccountType::INVALID));
