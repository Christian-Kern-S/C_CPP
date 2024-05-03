#include "../INCLUDE/Factory.hpp"

Factory& Factory::getInstance()
{
    static Factory instance;
    return instance;
}

ICalculator* Factory::create(CalculatorType t)
{
    switch (t)
    {
    case CalculatorType::ADD:
        return new Addition();
        break;
    case CalculatorType::SUBTRACT:
        return new Subtraction();
        break;
    case CalculatorType::DIVIDE:
        return new Division();
        break;
    case CalculatorType::MULTIPLY:
        return new Multiplication();
        break;
    
    default:
        return new NullCalculator();
        break;
    }
}