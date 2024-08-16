/*
AUTHOR: Ajay SHIMPI
Description:
This test cases indicates use of function pointers and handling pointers in Test cases
Also, use of functional library with std::function<>
*/

#include <gtest/gtest.h>
#include "../header/agileMotorControl.h"
#include <functional>   //to use std::function -> modern and safe

//creating function pointer and assigning it to original function.
typedef uint8_t (*checkPositionDataTraditionalfuncPtr) (uint16_t, uint8_t);

//modern approach and safe to use
std::function<uint8_t(uint16_t, uint8_t)> checkPositionDatafuncPtr = checkPositionData;

// Test fixture for black-box testing
class checkPositionDatafuncPtrBlackBoxTest : public ::testing::Test
{
    /*
        below data members and methods are accessible to the Google Test framework 
        also to any derived classes.
    */
    protected:
    //case1: with std::function
    std::function<uint8_t(uint16_t, uint8_t)> funcModernPtr;
    checkPositionDataTraditionalfuncPtr* traditionalFuncPtr;
    
    /*
    checkPositionDataTraditionalfuncPtr chkPosDataTraditionalFuncPtr = checkPositionData;
    */
    /*
        SetUp method: 
        1. Method is used to prepare the test environment before each test case
        This method is part of the ::testing::Test class -> checkout gtest.h
        
        SetUp() initializes the func member variable to point to checkPositionDataFunc. 
        This ensures that func is properly set up before each test case runs

        2. override: used to explicitly indicate that this method is overriding a virtual method in the base class
        
        3. ::testing::Test -> this base class defines SetUp as a virtual method. 
        By overriding it, you provide a specific implementation for your test fixture.

        4. what happen if we don't override these methods:
        code will still work, but can lose the compile time check.
        override will hlpe to catch the errors if method signature does nto match with base class method.

    */
    void SetUp() override
    {
        funcModernPtr = checkPositionData;  //modern function method
        traditionalFuncPtr = new checkPositionDataTraditionalfuncPtr(checkPositionData);
    }

    /*
        TearDown method: 
        Method is called after each test case.
        It can be used to clean up resources, although it is empty in this case.
        This method is also part of the ::testing::Test class

    */
   void TearDown() override
   {
        /*
            1. No need to manually delete the function pointer. 
            2. std::function manages the lifetime of the function object.
            3. if we use raw pointers and dynamically allocated memory, 
                we need to delete the pointer in this method to avoid memory leaks.
            4. In this case, the function pointer points to a static function, so no deletion is necessary.
            e.g. an be seen as below
        */
       delete traditionalFuncPtr;
       traditionalFuncPtr = nullptr; //nullptr, to avoid dangling pointer
   }
};

/*
    NOTE: we are choosing BlackBox Test cases here.
    BlackBox Testing: it focuses on the testing functionality of software,
    without any knowledge of internal imeplementation.
    Test cases will be derived from Specification and requirements of software.

    here, in this case of checkPositioData() function, we would focus on input and expected output,
    rather than considering internal code.
*/

//Test cases1: Valid position, with No_Error Flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxValidPositionAndNoError)
{
    uint16_t position1 = 25000;
    uint16_t position2 = 32767;
    uint8_t status = NO_ERROR;
    EXPECT_EQ(funcModernPtr(position1, status), NO_ERROR);
    EXPECT_EQ(funcModernPtr(position2, status), NO_ERROR);
}

//Test Case2: Valid position, with Error Flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxValidPositionAndError)
{
    uint16_t position1 = 30000;
    uint16_t position2 = 41767;
    uint8_t status = ERROR;
    EXPECT_EQ(funcModernPtr(position1, status), ERROR);
    EXPECT_EQ(funcModernPtr(position2, status), ERROR);
}

//Test Case3: Invalid position, with No Error Flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxInvalidPositionAndNoError)
{
    uint16_t position1 = 0;
    uint16_t position2 = 15000;
    uint16_t position3 = 51000;
    uint8_t status = NO_ERROR;
    EXPECT_EQ(funcModernPtr(position1, status), ERROR);
    EXPECT_EQ(funcModernPtr(position2, status), ERROR);
    EXPECT_EQ(funcModernPtr(position3, status), ERROR);
}

//Test Case4: Invalid position, with WARNING flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxInvalidPositionAndWarning)
{
    uint16_t position1 = 0;
    uint16_t position2 = 15000;
    uint8_t status = WARNING;
    EXPECT_EQ(funcModernPtr(position1, status), WARNING);
    EXPECT_EQ(funcModernPtr(position2, status), WARNING);
}

//Test Case5: only WARNING status flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxAnyPositionAndWarning)
{
    uint16_t position1 = 0;
    uint16_t position2 = 37000;
    uint16_t position3 = 65534;
    uint8_t status = WARNING;
    EXPECT_EQ(funcModernPtr(position1, status), WARNING);
    EXPECT_EQ(funcModernPtr(position2, status), WARNING);
    EXPECT_EQ(funcModernPtr(position3, status), WARNING);
}

//Test Case6: Motor Angle Edge Cases and ERROR flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackMotorEdgeCasesAndError)
{
    uint16_t position1 = 0;
    uint16_t position2 = 65534;
    uint8_t status = ERROR;
    EXPECT_EQ(funcModernPtr(position1, status), ERROR);
    EXPECT_EQ(funcModernPtr(position2, status), ERROR);
}

//Test Case7: Motor Angle out of Range and No Error Status
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackMotorOutofRangeAndNoError)
{
    uint16_t position = 64537;
    uint8_t status = NO_ERROR;
    EXPECT_EQ(funcModernPtr(position, status), ERROR);
}

//Test Case8: Motor Angle out of Range-Low and No Error Status
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackMotorOutofRangeLowAndNoError)
{
    uint16_t position = static_cast<uint16_t>(-1);  //cast to avoid compiler warning
    uint8_t status = NO_ERROR;
    EXPECT_EQ(funcModernPtr(position, status), ERROR);
}
//Test cases9: usage of function pointer:  Valid position, with No_Error Flag
TEST_F(checkPositionDatafuncPtrBlackBoxTest, blackBoxFunPtrValidPositionAndNoError)
{
    uint16_t position1 = 25000;
    uint16_t position2 = 32767;
    uint8_t status = NO_ERROR;
    EXPECT_EQ((*traditionalFuncPtr)(position1, status), NO_ERROR);
    EXPECT_EQ((*traditionalFuncPtr)(position2, status), NO_ERROR);
}

