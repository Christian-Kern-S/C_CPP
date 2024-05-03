#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "Calculator.hpp"

class Multiplication : public Calculator
{
public:
    Multiplication()
    {
        setName("Multiplication");
    }
    float multiply(float number1, float number2);
};

#endif //MULTIPLICATION_HPP