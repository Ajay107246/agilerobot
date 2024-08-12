Introduction: We have a function that checks data received from a position sensor on a rotating motor. This prototype of that function is: 
  **uint8_t checkPositionData(uint16_t positionValue, uint8_t statusFlag);** 
  
The sensor gives a digital **positionValue** between **0 and 65534**. Apart from that position, the function receives a **statusFlag**. 

The function is supposed to compute the motor angle in radiants.
It should also check the statusFlag as well as motor angle and **give appropriate return values** to the calling function.

Additional information: 
• The compuation for the motor angle in radiants is: 
  **positionValue – 32767 * 0.000095828**

• The allowed range for position data is within -1 rad and +1 rad.

• The status Flag has the following encoding:
  **0 - No error 
  1 - Error
  2 - Warning**

Task:
1. Create a new GIT local project (Not on public sites like gitlab.com)
2. Implement the checkPositionData function in C or C++
3. Create a CMake project to compile it
4. Create unit tests using a unit testing framework (e.g. unity or gtest). Think about appropriate test cases to sufficiently cover the function under test
5. Create a script, e.g. in python, that automates the build and test steps and stores the test results in a separate folder
