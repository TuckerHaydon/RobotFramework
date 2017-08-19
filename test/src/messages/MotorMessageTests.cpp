/*
 * Created by Tucker Haydon on 8/19/17.
 */

#include "catch.hpp"
#include "MotorMessage.h"

const std::string mockDestination = "MOCK_DESTINATION";
const uint16_t mockSpeed = 100;

class MockMotorMessage : public MotorMessage
{
public:
    MockMotorMessage(std::string destination, uint8_t motorSpeed) : MotorMessage(destination, motorSpeed) {
        // Nothing
    }
};

TEST_CASE( "Constructor successfully passes destination1", "[MotorMessage]" ) {
    MockMotorMessage message(mockDestination, mockSpeed);
    REQUIRE(message.getMotorSpeed() == mockSpeed);
}