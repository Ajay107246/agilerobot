/*
AUTHOR: AJAY SHIMPI
CMD:
g++ -std=c++17 *.cpp source/*.cpp -o build/agilerobot

lcov && genhtml: [make sure it is installed useing msys ucrt64 tool]

pacman -S mingw-w64-ucrt-x86_64-lcov

g++ -o test_agilerobot test_agileMotorControl.cpp -lgcov --coverage

lcov --directory . --capture --output-file coverage.info
genhtml coverage.info --output-directory out

*/
#include <iostream>
#include "header/agileMotorControl.h"

using namespace std;

enum Position {
    POS_ONE = 21000,
    POS_TWO = 22330,
    POS_THREE = 25040,
    POS_FOUR = 33797,
    POS_FIVE = 43204,
    POS_SIX = 57000, 
    POS_SEVEN = 65534
};

uint8_t statusF = NO_ERROR;
/*
uint8_t statusE = ERROR;
uint8_t statusNE = NO_ERROR;
uint8_t statusW = WARNING;
*/
int main()
{
    cout << "!Agile Robots Motor Control!" << endl;
    //[22330, 43204] / [31737, 33797]
    uint16_t lowerPosVal = POS_ONE; 
    uint16_t lowerEdgeCasePosVal = POS_TWO;
    uint16_t withinRangePosVal1 = POS_THREE;
    uint16_t withinRangePosVal2 = POS_FOUR;
    uint16_t upperEdgeCasePosVal1 = POS_FIVE;
    uint16_t upperEdgeCasePosVal2 = POS_SIX;
    uint16_t upperboundaryPosVal = POS_SEVEN;
    uint16_t lowerBoundaryPosVal = 0;
    int16_t negativePosVal = -1;
    uint32_t outofRangePosVal = 65537;

    uint8_t retCheckPos1 = checkPositionData(lowerPosVal, statusF);    //NE
    cout << "lowerPosVal with " << lowerPosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos1) << endl;

    statusF = ERROR;
    uint8_t retCheckPos2= checkPositionData(lowerEdgeCasePosVal, statusF);
    cout << "lowerEdgeCasePosVal with " << lowerEdgeCasePosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos2) << endl;
    
    statusF = NO_ERROR;
    uint8_t retCheckPos3= checkPositionData(withinRangePosVal1, statusF);
    cout << "withinRangePosVal1 with " << withinRangePosVal1 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos3) << endl;
    
    uint8_t retCheckPos4= checkPositionData(withinRangePosVal2, statusF);
    cout << "withinRangePosVal2 with " << withinRangePosVal2 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos4) << endl;
    
    statusF = WARNING;
    uint8_t retCheckPos5= checkPositionData(upperEdgeCasePosVal1, statusF);
    cout << "upperEdgeCasePosVal1 with " << upperEdgeCasePosVal1 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos5) << endl;

    statusF = ERROR;
    uint8_t retCheckPos6= checkPositionData(upperEdgeCasePosVal2, statusF);
    cout << "upperEdgeCasePosVal2 with " << upperEdgeCasePosVal2 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos6) << endl;

    statusF = NO_ERROR;
    uint8_t retCheckPos7= checkPositionData(upperboundaryPosVal, statusF);
    cout << "upperboundaryPosVal with " << upperboundaryPosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos7) << endl;
    
    //'int' to 'uint16_t'
    uint8_t retCheckPos8= checkPositionData(outofRangePosVal, statusF);
    cout << "outofRangePosVal with " << outofRangePosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos8) << endl;

    uint8_t retCheckPos9= checkPositionData(lowerBoundaryPosVal, statusF);
    cout << "lowerBoundaryPosVal with " << lowerBoundaryPosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos9) << endl;
    
    statusF = ERROR;
    uint8_t retCheckPos10= checkPositionData(upperboundaryPosVal, statusF);
    cout << "upperboundaryPosVal with " << upperboundaryPosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos10) << endl;
    
    statusF = WARNING;
    uint8_t retCheckPos11= checkPositionData(negativePosVal, statusF);
    cout << "negativePosVal with " << negativePosVal << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos11) << endl;

    return 0;
}

/*
conditions with output:
PS D:\agilerobot> g++ -std=c++17 *.cpp source/*.cpp -o build/agilerobot
PS D:\agilerobot> .\build\agilerobot.exe
!Agile Robots Motor Control!
motorAngle: -1.12761
lowerPosVal with 21000:0 =>1        
motorAngle: -1.00016
lowerEdgeCasePosVal with 22330:1 =>1
motorAngle: -0.740463
withinRangePosVal1 with 25040:0 =>0 
motorAngle: 0.0987028
withinRangePosVal2 with 33797:0 =>0
motorAngle: 1.00016
upperEdgeCasePosVal1 with 43204:2 =>2
motorAngle: 2.3222
upperEdgeCasePosVal2 with 57000:1 =>1
motorAngle: 3.14
upperboundaryPosVal with 65534:0 =>1
motorAngle: -3.1399
outofRangePosVal with 65537:0 =>1
motorAngle: -3.14
lowerBoundaryPosVal with 0:0 =>1
motorAngle: 3.14
upperboundaryPosVal with 65534:1 =>1
negativePosVal with -1:2 =>1
*/