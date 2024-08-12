#include "../header/agileMotorControl.h"
#include <iostream>

using namespace std;

uint8_t checkPositionData(uint16_t positionValue, uint8_t statusFlag)
{
    // Check if the position value is within the valid range, and statusFlag !=ERROR
    if (positionValue < 0 || positionValue > 65534)
    {
        return ERROR;
    }
    if (statusFlag == WARNING)
    {
        return WARNING;
    }
    
    // Compute the motor angle in radians
    float motorAngle = (positionValue - 32767) * 0.000095828;
    
    cout << "motorAngle: " << motorAngle << endl;
    // cout << "statusFlag: " << static_cast<int>(statusFlag) << endl;

    //check status flag and motorAngle for ERROR condition
    if (statusFlag == ERROR && (motorAngle < -1.0 || motorAngle > 1.0))
    {
        return ERROR;
    }
    else if (motorAngle < -1.0 || motorAngle > 1.0)
    {
        return ERROR;
    }
    /*
    else if (statusFlag == WARNING )//||(motorAngle == -1.00016 || motorAngle == 1.00016))
    {
        return WARNING;
    }
    else if ()
    {
        return WARNING;
    }*/
    
    
    //if everything is fine, return NO_ERROR
    return NO_ERROR;
}