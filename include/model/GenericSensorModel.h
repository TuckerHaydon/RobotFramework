/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#pragma once
#include "ISensorModel.h"
#include "HardwareID.h"
#include <atomic>

/**
 *  Generic model class for sensors
 * @tparam SensorDataType Type of data returned by a sensor.
 */
template <class SensorDataType>
class GenericSensorModel : public ISensorModel {
public:
    /**
    * Constructor.
    * @param ID Identifier that matches this model object to the actual sensor.
    */
    GenericSensorModel(const HardwareID &ID) : ISensorModel(ID) {

    };

protected:
    /**
     * @inheritDoc See superclass
     */
    bool do_update(const std::shared_ptr<void> data) override {
        this->data_ = *(static_cast<SensorDataType*>(data.get()));
        return true;
    }

    /**
     * @inheritDoc See superclass
     */
    bool do_get(const std::shared_ptr<std::shared_ptr<void>> returnData) const override {
        (*returnData) = std::make_shared<SensorDataType>(this->data_);
        return true;
    }

    /**
    * Sensor Model Data.
    */
    std::atomic<SensorDataType> data_;
};
