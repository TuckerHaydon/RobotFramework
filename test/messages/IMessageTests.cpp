//
// Created by Tucker Haydon on 8/8/17.
//

#include "catch.hpp"
#include "IMessage.h"

class MockMessage : IMessage
{

};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );

}