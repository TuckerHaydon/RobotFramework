/* 
 * Created by Tucker Haydon on 8/23/17. 
 */

#pragma once

#include "HardwareID.h"
#include <memory>

/**
 * Interface for various sensor models. Models cache the most recent sensor data and make it available for other system functions to access it immediately.
 * Data is passed and requested using void pointers due to template and polymorphic limits of the compiler and runtime environments.
 */
class SensorModel {
public:

    /**
     * Constructor.
     * @param ID ID that should be identical to the sensor's ID
     */
    SensorModel(const HardwareID &ID);

    /**
     * Updates the sensor model with the most recent sensor data
     * @param data Incoming data. Passed as a shared void* pointer. Should be cast for interpretation.
     * @return Whether or not the data was successfully cached.
     */
    bool update(const std::shared_ptr<void> &data);

    /**
     * Returns the cached data to a shared void* pointer.
     * @param returnData Shared void* pointer where the data should be written to.
     * @return Whether or not the data was successfully returned.
     */
    bool get(const std::shared_ptr<std::shared_ptr<void>> &returnData);

protected:
    /**
    * Performs the public update function.
    * @param data Incoming data. Passed as a shared void* pointer. Should be cast for interpretation.
    * @return Whether or not the data was successfully cached.
    */
    virtual bool do_update(const std::shared_ptr<void> &data) = 0;

    /**
     * Performs the public get function.
     * @param returnData Shared void* pointer where the data should be written to.
     * @return Whether or not the data was successfully returned.
     */
    virtual bool do_get(const std::shared_ptr<std::shared_ptr<void>> &returnData) = 0;

    /**
     * Hardware ID associated with the sensor.
     */
    HardwareID ID_;
};