/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#pragma once

#include "GenericSensorModel.h"

/**
 * Model class for an encoder sensor. Stores wheel speed in cm/s. Positive wheel speed indicates forward movement of wheel, negative the opposite.
 */
class EncoderModel : public GenericSensorModel<double> {
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
};