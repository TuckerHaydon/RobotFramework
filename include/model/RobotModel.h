/* 
 * Created by Tucker Haydon on 8/23/17. 
 */

#pragma once

#include <map>
#include "HardwareID.h"
#include "ISensorModel.h"

/**
 * Interface to store and access the most recent sensor data in a thread-safe, non-blocking manner.
 * Maps incoming data from the sensors to storage objects.
 * Provides an interface to access the data stored in the storage objects.
 */
class RobotModel {
public:
    /**
     * Updates the model with a new ISensorModel. Adds the id and ISensorModel to the map. If the sensor model has
     * already been attached, return false.
     * @param id Hardware ID of the component
     * @param component ISensorModel pointer to add
     * @return true if successful, false if any error occurred.
     */
    bool updateModel(const HardwareID &id, const std::shared_ptr<ISensorModel> sensorModel);

    /**
     * Updates a sensor model object with the most recent sensor data
     * @param id The unique id associated with the sensor
     * @param data The data from the sensor
     * @return true if successful, false if any error occurred.
     */
    bool updateSensorData(const HardwareID &id, const std::shared_ptr<void> data) const;

    /**
     * Gets the cached sensor data
     * @param id The unique id associated with the sensor
     * @param returnData Data object to be filled with the sensor data
     * @return true if successful, false if any error occurred.
     */
    bool getSensorData(const HardwareID &id, const std::shared_ptr<std::shared_ptr<void>> returnData) const;

private:
    /**
     * Map from HardwareID to ISensorModel pointers
     */
    std::map<HardwareID, std::shared_ptr<ISensorModel>> model_;
};
