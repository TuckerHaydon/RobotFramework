/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "catch.hpp"
#include "SensorModel.h"

const HardwareID MOCK_ID{1};
const uint8_t MOCK_SENSOR_DATA{12};

template <class SensorDataType>
class MockSensorModel : public SensorModel {
public:
    MockSensorModel(const HardwareID &ID) : SensorModel(ID) {

    }

    bool do_update_function_called{false}, do_get_function_called{false};

protected:
    bool do_update(const std::shared_ptr<void> &data) override {
        do_update_function_called = true;
        // this->data_ = *(static_cast<SensorDataType*>(data.get()));
        return true;
    }

    bool do_get(const std::shared_ptr<std::shared_ptr<void>> &returnData) override {
        do_get_function_called = true;
        // Temporarily copies data to the heap
        // (*returnData) = std::make_shared<SensorDataType>(data_);
        return true;
    }

private:
    SensorDataType data_;
};

TEST_CASE( "Calling to update function calls the do_update function", "[RobotModel]" ) {
    MockSensorModel<uint8_t> sensorModel{MOCK_ID};
    sensorModel.update(NULL);
    REQUIRE(sensorModel.do_update_function_called == true);
}

TEST_CASE( "Calling the get function calls the do_get function", "[RobotModel]" ) {
    MockSensorModel<uint8_t> sensorModel{MOCK_ID};
    sensorModel.get(NULL);
    REQUIRE(sensorModel.do_get_function_called == true);
}