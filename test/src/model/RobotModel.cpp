/* 
 * Created by Tucker Haydon on 8/24/17. 
 */

#include "catch.hpp"
#include "GenericSensorModel.h"
#include "RobotModel.h"

const HardwareID MOCK_ID_1{1};
const HardwareID MOCK_ID_2{2};
const uint8_t MOCK_SENSOR_DATA{12};

class MockISensorModel : public GenericSensorModel<uint8_t> {
public:
    MockISensorModel(const HardwareID &ID) : GenericSensorModel<uint8_t >(ID) {}

    uint8_t getData() const {
        return this->data_;
    }
};

TEST_CASE( "Updating the model with null ID -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    bool returnValue = model.updateModel(HardwareID(HardwareID::NULL_ID), sensorModel);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Updating the model with a duplicate ID -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    bool returnValue = model.updateModel(MOCK_ID_1, sensorModel);
    REQUIRE(returnValue == true);
    returnValue = model.updateModel(MOCK_ID_1, sensorModel);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Updating the model correctly -> returns true", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    bool returnValue = model.updateModel(MOCK_ID_1, sensorModel);
    REQUIRE(returnValue == true);
}

TEST_CASE( "Updating sensor data with null id -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    bool returnValue = model.updateSensorData(HardwareID(HardwareID::NULL_ID), updateData);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Updating nonexistent sensor -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    bool returnValue = model.updateSensorData(MOCK_ID_2, updateData);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Updating sensor correctly -> returns true, passes data to ISensorModel object", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    bool returnValue = model.updateSensorData(MOCK_ID_1, updateData);
    REQUIRE(returnValue == true);
    REQUIRE(((MockISensorModel*)sensorModel.get())->getData() == MOCK_SENSOR_DATA);
}

TEST_CASE( "Get sensor data with null id -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    model.updateSensorData(MOCK_ID_1, updateData);

    std::shared_ptr<std::shared_ptr<void>> returnData = std::make_shared<std::shared_ptr<void>>();
    bool returnValue = model.getSensorData(HardwareID(HardwareID::NULL_ID), returnData);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Get sensor data with nonexistent id -> returns false", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    model.updateSensorData(MOCK_ID_1, updateData);

    std::shared_ptr<std::shared_ptr<void>> returnData = std::make_shared<std::shared_ptr<void>>();
    bool returnValue = model.getSensorData(MOCK_ID_2, returnData);
    REQUIRE(returnValue == false);
}

TEST_CASE( "Get sensor data correctly -> returns true, returns expected data", "[RobotModel]" ) {
    RobotModel model{};
    std::shared_ptr<ISensorModel> sensorModel = std::make_shared<MockISensorModel>(MOCK_ID_1);
    model.updateModel(MOCK_ID_1, sensorModel);
    std::shared_ptr<void> updateData = std::make_shared<uint8_t>(MOCK_SENSOR_DATA);
    model.updateSensorData(MOCK_ID_1, updateData);

    std::shared_ptr<std::shared_ptr<void>> returnData = std::make_shared<std::shared_ptr<void>>();
    bool returnValue = model.getSensorData(MOCK_ID_1, returnData);
    REQUIRE(returnValue == true);
    REQUIRE(*(static_cast<uint8_t*>(returnData.get()->get())) == MOCK_SENSOR_DATA);
}
