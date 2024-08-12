#pragma once
#ifndef AGILEMOTORCONTROL__H
#define AGILEMOTORCONTROL__H

#include <cstdint>

//flags/variable
#define NO_ERROR    0
#define ERROR       1
#define WARNING     2

extern uint8_t statusF;// = NO_ERROR;

uint8_t checkPositionData(uint16_t positionValue, uint8_t statusFlag);


#endif //AGILEMOTORCONTROL__H
#pragma endregion