#include "../INCLUDE/Addition.hpp"

float Addition::sum(float number1, float number2)
{
    setNumber1(number1);
    setNumber2(number2);
    float result = getNumber1() + getNumber2();
    return result;
}