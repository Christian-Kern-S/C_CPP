#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class MyClass
{
    string id;

public:
    MyClass(string _id) : id(_id) {}

    inline string GetId() { return id; }

};

TEST(Testname, Increment_by_5_2)
{

    // Arrange
    MyClass mc("root");

    // Act
    string value = mc.GetId();

    // Assert
    EXPECT_STREQ(value.c_str(), "root");
}


