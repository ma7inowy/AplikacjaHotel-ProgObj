#include "Premium.h"

Premium::Premium(int people, double baseBookPrice) : RoomType(people, baseBookPrice) {

}

Premium::~Premium() {

}

bool Premium::getKitchenette() {
    return kitchenette;
}
