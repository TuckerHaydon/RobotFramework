/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "catch.hpp"
#include "ISensorModel.h"

const HardwareID MOCK_ID{1};
const uint8_t MOCK_SENSOR_DATA{12};

template <class SensorDataType>
class MockISensorModel : public ISensorModel {
public:
    MockISensorModel(const HardwareID &ID) : ISensorModel(ID) {

    }

    mutable bool do_update_function_called{false}, do_get_function_called{false};

protected:
    bool do_update(const std::shared_ptr<void> data) override {
        do_update_function_called = true;
        return true;
    }

    bool do_get(const std::shared_ptr<std::shared_ptr<void>> returnData) const override {
        do_get_function_called = true;
        return true;
    }

private:
    SensorDataType data_;
};

TEST_CASE( "Calling to update function calls the do_update function", "[ISensorModel]" ) {
    MockISensorModel<uint8_t> sensorModel{MOCK_ID};
    sensorModel.update(NULL);
    REQUIRE(sensorModel.do_update_function_called == true);
}

TEST_CASE( "Calling the get function calls the do_get function", "[ISensorModel]" ) {
    MockISensorModel<uint8_t> sensorModel{MOCK_ID};
    sensorModel.get(NULL);
    REQUIRE(sensorModel.do_get_function_called == true);
}

TEST_CASE( "Hardware ID is properly stored", "[ISensorModel]" ) {
    MockISensorModel<uint8_t> sensorModel{MOCK_ID};
    REQUIRE(sensorModel.getID() == MOCK_ID);
}
