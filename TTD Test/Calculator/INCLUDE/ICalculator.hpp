#ifndef ICALCULATOR_HPP
#define ICALCULATOR_HPP

#include <string>

class ICalculator
{
public:
    virtual inline float getNumber1() const = 0;
    virtual inline float getNumber2() const = 0;
    virtual inline std::string getName() const = 0;
    virtual void reset() = 0;
};

#endif //ICALCULATOR_HPP