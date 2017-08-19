/* 
 * Created by Tucker Haydon on 8/19/17. 
 */

#pragma once
#include "IMessage.h"

class MotorMessage : public IMessage
{
public:
    MotorMessage(std::string destination, uint16_t motorSpeed);
    uint16_t getMotorSpeed();

private:
    uint16_t motorSpeed_;


};



