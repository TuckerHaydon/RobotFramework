/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#include "RobotModel.h"

bool RobotModel::updateModel(const HardwareID &id, const std::shared_ptr <SensorModel> sensorModel) {
    // Prevent insertion of null HardwareID or duplicate
    if(this->model_.find(id) != this->model_.end() || id == HardwareID(HardwareID::NULL_ID)) {
        // TODO Log the error.
        return false;
    }

    this->model_[id] = sensorModel;
    return true;
}

bool RobotModel::updateSensorData(const HardwareID &id, const std::shared_ptr<void> data) const {
    if(this->model_.find(id) == this->model_.end()) {
        // TODO Log the error.
        return false;
    }

    this->model_.at(id)->update(data);
    return true;
}

bool RobotModel::getSensorData(const HardwareID &id, const std::shared_ptr<std::shared_ptr<void>> returnData) const {
    if(this->model_.find(id) == this->model_.end()) {
        // TODO Log the error.
        return false;
    }

    this->model_.at(id)->get(returnData);
    return true;
}