#include <gtest/gtest.h>
#include "../INCLUDE/Factory.hpp"
#include "../INCLUDE/Calculator.hpp"
#include "../INCLUDE/NullCalculator.hpp"

class test_Factory : public ::testing::TestWithParam<CalculatorType>
{
public:
    Factory &factory = Factory::getInstance();
    std::string myCalculator(CalculatorType t)
    {
        switch (t)
        {
        case CalculatorType::ADD:
            return "Addition";
            break;
        case CalculatorType::SUBTRACT:
            return "Subtraction";
            break;
        case CalculatorType::DIVIDE:
            return "Division";
            break;
        case CalculatorType::MULTIPLY:
            return "Multiplication";
            break;
        default:
            return "";
            break;
        }
    }
};

TEST_P(test_Factory, canCreateCalculator)
{
    const CalculatorType& params = GetParam();
    auto actual = factory.create(params);
    auto expected = myCalculator(params);
    EXPECT_EQ(actual->getName(), expected);
}

TEST_F(test_Factory, canCreateCalculator2)
{
    auto actual = factory.create(CalculatorType::ADD);
    auto expected = myCalculator(CalculatorType::ADD);
    EXPECT_EQ(actual->getName(), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ParametrizedFactoryTest,
    test_Factory,
    ::testing::Values(
        CalculatorType::ADD,
        CalculatorType::SUBTRACT,
        CalculatorType::DIVIDE,
        CalculatorType::MULTIPLY,
        CalculatorType::INVALID));