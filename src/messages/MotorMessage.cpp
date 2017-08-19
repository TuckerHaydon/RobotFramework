/* 
 * Created by Tucker Haydon on 8/19/17. 
 */

#include "MotorMessage.h"

MotorMessage::MotorMessage(std::string destination, uint16_t motorSpeed) : IMessage(destination) {
    this->motorSpeed_ = motorSpeed;
};

uint16_t MotorMessage::getMotorSpeed() {
    return this->motorSpeed_;
}
