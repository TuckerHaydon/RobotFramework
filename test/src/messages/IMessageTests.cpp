//
// Created by Tucker Haydon on 8/8/17.
//

#include "catch.hpp"
#include "IMessage.h"

const std::string mockDestination = "MOCK_DESTINATION";
class MockMessage : public IMessage
{
public:
    MockMessage(std::string destination) : IMessage(destination) {
        // Nothing
    }
};

TEST_CASE( "Constructor successfully passes destination", "[IMessage]" ) {
    REQUIRE( MockMessage(mockDestination).getDestination() == mockDestination);
}