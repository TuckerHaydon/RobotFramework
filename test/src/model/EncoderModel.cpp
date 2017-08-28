/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#include "catch.hpp"
#include "EncoderModel.h"

const HardwareID MOCK_ID{1};
const double MOCK_SENSOR_DATA{12.0};

TEST_CASE( "Encoder model updated -> Retrieve data the same", "[EncoderModel]" ) {
    EncoderModel model{MOCK_ID};
    model.update(std::make_shared<double>(MOCK_SENSOR_DATA));
    REQUIRE(model.getWheelSpeed_cm_per_s() == MOCK_SENSOR_DATA);
}