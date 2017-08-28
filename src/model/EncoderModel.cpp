/* 
 * Created by Tucker Haydon on 8/27/17. 
 */

#include "EncoderModel.h"

EncoderModel::EncoderModel(const HardwareID &ID) : GenericSensorModel<double>(ID) {

}

double EncoderModel::getWheelSpeed_cm_per_s() const {
    return this->data_;
}
