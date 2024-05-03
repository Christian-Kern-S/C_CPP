#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "Calculator.hpp"

class Division : public Calculator
{
public:
    Division()
    {
        setName("Division");
    }
    float divide(float number1, float number2);
};

#endif //DIVISION_HPP