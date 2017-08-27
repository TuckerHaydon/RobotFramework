/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#pragma once

#include "SensorModel.h"
#include <limits>

/**
 * Model class for an encoder sensor. Stores wheel speed in cm/s. Positive wheel speed indicates forward movement of wheel, negative the opposite.
 */
class EncoderModel : public SensorModel {
public:
    /**
     * Constructor.
     * @param ID Identifier that matches this model object to the actual sensor.
     */
    EncoderModel(const HardwareID &ID);

    /**
    * Returns the current wheel speed
    * @return The current wheel speed
    */
    double getWheelSpeed_cm_per_s() const;

protected:
    /**
     * @inheritDoc See superclass
     */
    bool do_update(const std::shared_ptr<void> data) override;

    /**
     * @inheritDoc See superclass
     */
    bool do_get(const std::shared_ptr<std::shared_ptr<void>> returnData) const override;

private:
    /**
     * Model data. Stored as a double representing the wheel speed in cm/s
     */
    std::atomic<double> wheelSpeed_{std::numeric_limits<double>::infinity()};
};