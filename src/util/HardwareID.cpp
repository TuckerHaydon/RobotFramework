/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "HardwareID.h"

HardwareID::HardwareID()
        : ID_{NULL_ID}
{

}

HardwareID::HardwareID(const uint16_t &ID)
        : ID_{ID}
{

}

bool HardwareID::isNull() {
    return (this->ID_ == NULL_ID);
}

bool HardwareID::operator ==(const HardwareID &other) const {
    return this->ID_ == other.ID_;
}

bool HardwareID::operator !=(const HardwareID &other) const {
    return !((*this)==other);
}

bool HardwareID::operator <(const HardwareID &other) const {
    return this->ID_ < other.ID_;
}

const uint16_t HardwareID::NULL_ID{0};
