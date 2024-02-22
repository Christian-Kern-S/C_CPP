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

struct MyClassTest : public testing::Test
{

    MyClass *mc;
    inline void SetUp() { mc = new MyClass(100); }
    inline void TearDown() { delete mc; }
};

TEST_F(MyClassTest, Increment_by_5_3)
{
    // Act
    mc->Increment(5);
    // Assert
    ASSERT_EQ(mc->getValue(), 105);
}

TEST_F(MyClassTest, Increment_by_10_3)
{
    // Act
    mc->Increment(10);

    // Assert
    EXPECT_EQ(mc->getValue(), 110);
}

