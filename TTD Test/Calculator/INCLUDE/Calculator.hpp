#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "ICalculator.hpp"

enum class CalculatorType
{
    INVALID = -1,
    ADD,
    SUBTRACT,
    DIVIDE,
    MULTIPLY
};

class Calculator : public ICalculator
{
public:
    inline float getNumber1() const override { return _number1; }
    inline float getNumber2() const override { return _number2; }
    inline std::string getName() const override{ return _name; }
    void reset() override;
protected:
    void setNumber1(float number1);
    void setNumber2(float number2);
    void setName(std::string name);
private:
    float _number1;
    float _number2;
    std::string _name;
};

#endif //CALCULATOR_HPP