#include "../INCLUDE/Calculator.hpp"

void Calculator::setNumber1(float number1)
{
    _number1 = number1;
}
void Calculator::setNumber2(float number2)
{
    _number2 = number2;
}
void Calculator::reset()
{
    _number1 = 0;
    _number2 = 0;
}

void Calculator::setName(std::string name)
{
    _name = name;
}