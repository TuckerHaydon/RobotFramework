/* 
 * Created by Tucker Haydon on 8/25/17. 
 */

#include "ISensorModel.h"

ISensorModel::ISensorModel(const HardwareID &ID)
        : ID_{ID}
{

}

bool ISensorModel::update(const std::shared_ptr<void> data) {
    return do_update(data);
}

bool ISensorModel::get(const std::shared_ptr<std::shared_ptr<void>> returnData) const {
    return do_get(returnData);
}

HardwareID ISensorModel::getID() const {
    return this->ID_;
}
