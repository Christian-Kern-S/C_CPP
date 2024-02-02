#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class MyClass
{
    int baseValue;

public:
    MyClass(int _bv) : baseValue(_bv) {}
    void Increment(int byValue)
    {
        baseValue += byValue;
    }
    inline int getValue() { return baseValue; }
};

TEST(ClassTest, Increment_by_5)
{

    // Arrange
    MyClass mc(100);

    // Act
    mc.Increment(5);

    // Assert
    EXPECT_EQ(mc.getValue(), 105);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
