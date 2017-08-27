/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "SensorModel.h"

SensorModel::SensorModel(const HardwareID &ID)
        : ID_{ID}
{

}

bool SensorModel::update(const std::shared_ptr<void> data) {
    return do_update(data);
}

bool SensorModel::get(const std::shared_ptr<std::shared_ptr<void>> returnData) const {
    return do_get(returnData);
}

HardwareID SensorModel::getID() const {
    return this->ID_;
}