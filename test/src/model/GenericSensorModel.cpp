/* 
 * Created by Tucker Haydon on 8/27/17. 
 */


#include "catch.hpp"
#include "GenericSensorModel.h"

const HardwareID MOCK_ID{1};
const uint8_t MOCK_SENSOR_DATA{12};

TEST_CASE( "Constructor polymorphically stores HardwareID", "[EncoderModel]" ) {
    GenericSensorModel<uint8_t> *model = new GenericSensorModel<uint8_t>(MOCK_ID);
    REQUIRE(model->getID() == MOCK_ID);
    REQUIRE(((SensorModel*)model)->getID() == MOCK_ID);
}

TEST_CASE( "Data injected and retrieved correctly from generic sensor", "[GenericSensorModel]" ) {
    GenericSensorModel<uint8_t> model{MOCK_ID};
    model.update(std::make_shared<uint8_t>(MOCK_SENSOR_DATA));
    auto ptr = std::make_shared<std::shared_ptr<void>>();
    REQUIRE(model.get(ptr) == true);
    REQUIRE(*static_cast<uint8_t *>((*ptr.get()).get()) == MOCK_SENSOR_DATA);
}

TEST_CASE( "Generic sensor can be inserted into a STL container for SensorModels", "[GenericSensorModel]" ) {
    SensorModel *model = new GenericSensorModel<uint8_t>(MOCK_ID);
    std::shared_ptr<SensorModel> ptr = std::shared_ptr<SensorModel>(model);

    std::vector<std::shared_ptr<SensorModel>> models;
    models.push_back(ptr);

    std::shared_ptr<uint8_t> updateValue = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    models[0].get()->update(updateValue);

    auto returnValue = std::make_shared<std::shared_ptr<void>>();
    (models[0].get())->get(returnValue);
    REQUIRE(*static_cast<uint8_t *>((*returnValue.get()).get()) == MOCK_SENSOR_DATA);
}

