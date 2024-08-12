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
    uint16_t positionVal1 = POS_ONE; 
    uint16_t positionVal2 = POS_TWO;
    uint16_t positionVal3 = POS_THREE;
    uint16_t positionVal4 = POS_FOUR;
    uint16_t positionVal5 = POS_FIVE;
    uint16_t positionVal6 = POS_SIX;
    uint16_t positionVal7 = POS_SEVEN;

    uint8_t retCheckPos1 = checkPositionData(positionVal1, statusF);    //NE
    cout << "retCheckPos1 with " << positionVal1 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos1) << endl;

    statusF = ERROR;
    uint8_t retCheckPos2= checkPositionData(positionVal2, statusF);
    cout << "retCheckPos2 with " << positionVal2 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos2) << endl;
    
    uint8_t retCheckPos3= checkPositionData(positionVal3, statusF);
    cout << "retCheckPos3 with " << positionVal3 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos3) << endl;
    
    uint8_t retCheckPos4= checkPositionData(positionVal4, statusF);
    cout << "retCheckPos4 with " << positionVal4 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos4) << endl;
    
    statusF = WARNING;
    uint8_t retCheckPos5= checkPositionData(positionVal5, statusF);
    cout << "retCheckPos5 with " << positionVal5 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos5) << endl;

    statusF = ERROR;
    uint8_t retCheckPos6= checkPositionData(positionVal6, statusF);
    cout << "retCheckPos6 with " << positionVal6 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos6) << endl;

    statusF = NO_ERROR;
    uint8_t retCheckPos7= checkPositionData(positionVal7, statusF);
    cout << "retCheckPos7 with " << positionVal7 << ":" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos7) << endl;
    
    /*
    //'int' to 'uint16_t'
    uint8_t retCheckPos8= checkPositionData(65537, statusF);
    cout << "retCheckPos8 with 65537:" << static_cast<int>(statusF) << " =>"  << static_cast<int>(retCheckPos8) << endl;
    */
    return 0;
}

/*
conditions with output:
[build] !Agile Robots Motor Control!
[build] motorAngle: -1.12761
[build] retCheckPos1 with 21000:0 =>1
[build] motorAngle: -1.00016
[build] retCheckPos2 with 22330:1 =>1
[build] motorAngle: -0.740463
[build] retCheckPos3 with 25040:0 =>0
[build] motorAngle: 0.0987028
[build] retCheckPos4 with 33797:0 =>0
[build] retCheckPos5 with 43204:2 =>2
[build] motorAngle: 2.3222
[build] retCheckPos6 with 57000:1 =>1
[build] motorAngle: 3.14
[build] retCheckPos7 with 65534:0 =>1

unsigned conversion from 'int' to 'uint16_t' {aka 'short unsigned int'} changes value from '65537' to '1' [-Woverflow]GCC
(int)65537
[build] motorAngle: -3.1399
[build] retCheckPos8 with 65537:0 =>1
*/