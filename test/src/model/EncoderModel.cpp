/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#include "catch.hpp"
#include "EncoderModel.h"

const HardwareID MOCK_ID{1};
const double MOCK_SENSOR_DATA{12.0};

TEST_CASE( "Constructor polymorphically stores HardwareID", "[EncoderModel]" ) {
    EncoderModel *model = new EncoderModel(MOCK_ID);
    REQUIRE(model->getID() == MOCK_ID);
    REQUIRE(((SensorModel*)model)->getID() == MOCK_ID);
}

TEST_CASE( "do_get after model has been updated -> return true, shared_ptr updated, get and getWheelSpeed are the same", "[EncoderModel]" ) {
    EncoderModel model{MOCK_ID};
    model.update(std::make_shared<double>(MOCK_SENSOR_DATA));
    auto ptr = std::make_shared<std::shared_ptr<void>>();
    REQUIRE(model.get(ptr) == true);
    REQUIRE(*static_cast<double *>((*ptr.get()).get()) == MOCK_SENSOR_DATA);
    REQUIRE(model.getWheelSpeed_cm_per_s() == MOCK_SENSOR_DATA);
}