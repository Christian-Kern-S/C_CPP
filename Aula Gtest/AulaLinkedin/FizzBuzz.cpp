#include <gtest/gtest.h>

std::string fizzBuzz(int value)
{

    if (0 == (value % 3) && 0 == (value % 5))
    {
        return "FizzBuzz";
    }
    if (0 == (value % 3))
    {
        return "Fizz";
    }
    if (0 == (value % 5))
    {
        return "Buzz";
    }

    return std::to_string(value);
}

void checkFizzBuzz(int value, std::string expectedResult)
{
    std::string result = fizzBuzz(value);
    ASSERT_STREQ(expectedResult.c_str(), result.c_str());
};

TEST(FizzBuzzTests, returns1With1PassedIn)
{
    checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTests, returns2With2PassedIn)
{
    checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTests, returnsFizzWith3PassedIn)
{
    checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTests, returnsBussWith5PassedIn)
{
    checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTests, returnsFizzWith6PassedIn)
{
    checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTests, returnsBuzzWith6PassedIn)
{
    checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTests, returnsFizzBuzzWith15PassedIn)
{
    checkFizzBuzz(15, "FizzBuzz");
}