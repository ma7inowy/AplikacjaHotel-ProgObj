
#include <RoomType.h>

#include "RoomType.h"

RoomType::RoomType(int people, double baseBookPrice): people(people), baseBookPrice(baseBookPrice) {
}

RoomType::~RoomType() {}

int RoomType::getPeople() {
    return people;
}

double RoomType::getBaseBookPrice() {
    return baseBookPrice;
}

void RoomType::setMultiplierBaseBookPrice(int multiplier) {
    baseBookPrice*=multiplier;
}




