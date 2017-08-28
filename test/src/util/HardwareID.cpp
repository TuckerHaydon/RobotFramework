/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "catch.hpp"
#include "HardwareID.h"

TEST_CASE( "Default initializer makes ID null", "[HardwareID]" ) {
    HardwareID id;
    REQUIRE(id.isNull() == true);
}

TEST_CASE( "Initializer with null ID makes ID null", "[HardwareID]" ) {
    HardwareID id{HardwareID::NULL_ID};
    REQUIRE(id.isNull() == true);
}

TEST_CASE( "Two IDs with the same initializer ID are equivalent", "[HardwareID]" ) {
    const uint16_t MOCK_ID = 10;
    HardwareID id1{MOCK_ID}, id2{MOCK_ID};
    REQUIRE(id1 == id2);
    REQUIRE(!(id1 != id2));
}

TEST_CASE( "Two IDs with different initializers ID are not equivalent", "[HardwareID]" ) {
    const uint16_t MOCK_ID_1 = 10;
    const uint16_t MOCK_ID_2 = 20;
    HardwareID id1{MOCK_ID_1}, id2{MOCK_ID_2};
    REQUIRE(id1 != id2);
    REQUIRE(!(id1 == id2));
}

TEST_CASE( "Two equivalent IDs -> Neither are less than", "[HardwareID]" ) {
    const uint16_t MOCK_ID = 10;
    HardwareID id{MOCK_ID};
    REQUIRE(!(id < id));
}

TEST_CASE( "HardwareID less than equivalence works", "[HardwareID]" ) {
    const uint16_t MOCK_ID_1 = 10;
    const uint16_t MOCK_ID_2 = 20;
    HardwareID id1{MOCK_ID_1}, id2{MOCK_ID_2};
    REQUIRE(id1 < id2);
    REQUIRE(!(id2 < id1));
}