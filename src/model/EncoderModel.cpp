/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#include "EncoderModel.h"

EncoderModel::EncoderModel(const HardwareID &ID) : SensorModel(ID) {

}

bool EncoderModel::do_update(const std::shared_ptr<void> data) {
    this->wheelSpeed_ = *(static_cast<double*>(data.get()));
    return true;
}

bool EncoderModel::do_get(const std::shared_ptr<std::shared_ptr<void>> returnData) const {
    (*returnData) = std::make_shared<double>(this->wheelSpeed_);
    return true;
}

double EncoderModel::getWheelSpeed_cm_per_s() const {
    return this->wheelSpeed_;
}
