#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST( Testname, Increment_by_5_ ){

    // EXPECT_GT(3,2);
    // EXPECT_EQ(1,1);

    //Arrange
    int value = 100;
    int increment = 5;

    //Act
    value += increment;

    //Assert
    ASSERT_EQ(value,105);

}

TEST( Testname, Increment_by_10_ ){

    // EXPECT_GT(3,2);
    // EXPECT_EQ(1,1);

    //Arrange
    int value = 100;
    int increment = 10;

    //Act
    value += increment;

    //Assert
    ASSERT_EQ(value,110);

}

// TEST( Testname, Subtest_2 ){

//     ASSERT_FALSE(1 == 2);

// }


