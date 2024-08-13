#include <gtest/gtest.h>
#include <cmath>
#include "../header/agileMotorControl.h"

#define NEGATIVE_POS -1
#define OUTOF_POS 65537

enum validTest_Postion{
    POS_VALID1 = 23000,
    POS_VALID2 = 26040,
    POS_VALID3 =  33797,
    POS_VALID4 =  41020
};
enum inValidTest_Postion{
    POS_INVALID1 = 0,
    POS_INVALID2 = 15000,
    POS_INVALID3 =  45000,
    POS_INVALID4 =  65534
};

// Test case for valid position values and NO_ERROR status flag
TEST(checkPositionDataTest,validPositionAndNoError)
{
    EXPECT_TRUE(true);
    EXPECT_EQ(checkPositionData(POS_VALID1, NO_ERROR), NO_ERROR);
    EXPECT_EQ(checkPositionData(POS_VALID2, NO_ERROR), NO_ERROR);
    EXPECT_EQ(checkPositionData(POS_VALID3, NO_ERROR), NO_ERROR);
    EXPECT_EQ(checkPositionData(POS_VALID4, NO_ERROR), NO_ERROR);
}

// Test case for valid position values and ERROR status flag
TEST(checkPositionDataTest, validPositionAndError)
{
    EXPECT_EQ(checkPositionData(POS_VALID1, ERROR), ERROR);
    EXPECT_EQ(checkPositionData(POS_VALID2, ERROR), ERROR);
}

// Test case for invalid position values and NO_ERROR status flag
TEST(checkPositionDataTest,invalidPositionAndNoError)
{
    EXPECT_EQ(checkPositionData(POS_INVALID1, NO_ERROR), ERROR);
    EXPECT_EQ(checkPositionData(POS_INVALID2, NO_ERROR), ERROR);
    EXPECT_EQ(checkPositionData(POS_INVALID3, NO_ERROR), ERROR);
    EXPECT_EQ(checkPositionData(POS_INVALID4, NO_ERROR), ERROR);
}

// Test case for invalid position values and WARNING status flag
TEST(checkPositionDataTest, negativePositionAndWarning)
{
    EXPECT_EQ(checkPositionData(NEGATIVE_POS, WARNING), ERROR);
    // EXPECT_EQ(checkPositionData(OUTOF_POS, WARNING), ERROR);
}

// Test case for WARNING status flag
TEST(checkPositionDataTest,invalidPositionAndWarning)
{
    EXPECT_EQ(checkPositionData(POS_INVALID1, WARNING), WARNING);
    EXPECT_EQ(checkPositionData(POS_VALID2, WARNING), WARNING);
    EXPECT_EQ(checkPositionData(POS_INVALID4, WARNING), WARNING);
}

// Test case for ERROR status flag and Motor Angle out of Range
TEST(checkPositionDataTest, ErrorStatusFlagAndMotorOutofRange)
{
    EXPECT_EQ(checkPositionData(POS_INVALID1, ERROR), ERROR);
    EXPECT_EQ(checkPositionData(POS_INVALID4, ERROR), ERROR);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
//[22330, 43204] / [31737, 33797]
conditions with output:
motorAngle: -1.12761
retCheckPos1 with 21000:0 =>1
motorAngle: -1.00016
retCheckPos2 with 22330:1 =>1
motorAngle: -0.740463
retCheckPos3 with 25040:1 =>0
motorAngle: 0.0987028
retCheckPos4 with 33797:1 =>0
retCheckPos5 with 43204:2 =>2
motorAngle: 2.3222
retCheckPos6 with 57000:1 =>1
motorAngle: 3.14
retCheckPos7 with 65534:0 =>1
motorAngle: -3.1399
retCheckPos8 with 65537:0 =>1
motorAngle: -3.14
retCheckPos9 with 0:0 =>1
motorAngle: 3.14
retCheckPos10 with 65534:0 =>1
retCheckPos11 with -1:2 =>1
*/