/* 
 * Created by Tucker Haydon on 8/24/17. 
 */

#include "catch.hpp"
#include "RobotModel.h"

const HardwareID MOCK_ID_1{1};
const HardwareID MOCK_ID_2{2};
const uint8_t MOCK_SENSOR_DATA{12};

template <class SensorDataType>
class MockSensorModel : public SensorModel {
public:
    MockSensorModel(const HardwareID &ID) : SensorModel(ID) {}

protected:
    bool do_update(const std::shared_ptr<void> &data) override {
        return true;
    }

    bool do_get(const std::shared_ptr<void*> &returnData) override {
        return true;
    }
};

TEST_CASE( "Updating the model with null ID -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Updating the model with a duplicate ID -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Updating the model correctly -> returns true", "[RobotModel]" ) {

}

TEST_CASE( "Updating sensor data with null id -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Updating sensor with nonexistent id -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Updating sensor correctly -> returns true, passes data to SensorModel object", "[RobotModel]" ) {

}

TEST_CASE( "Get sensor data with null id -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Get sensor data with nonexistent id -> returns false", "[RobotModel]" ) {

}

TEST_CASE( "Get sensor data correctly -> returns true, returns expected data", "[RobotModel]" ) {

}