#ifndef SUBTRACTION_HPP
#define SUBTRACTION_HPP

#include "Calculator.hpp"

class Subtraction : public Calculator
{
public:
    Subtraction()
    {
        setName("Subtraction");
    }
    float subtract(float number1, float number2);
};

#endif //SUBTRACTION_HPP