#include <sstream>
#include <Room.h>

#include "Room.h"

Room::Room(shared_ptr<RoomType> roomType) {
    this->roomType=roomType;
    this->ID = boost::uuids::random_generator()();
}

string Room::roomInfo() {
    stringstream strumyk;
    strumyk<<"Room ID: "<<getID()<<", room type: "<<roomType->typeName()<<", base price: "<<roomType->getBaseBookPrice()<<", number of people: "<<roomType->getPeople()<<endl;
    return strumyk.str();
}

Room::~Room()=default;

shared_ptr<RoomType> Room::getRoomType() {
    return roomType;
}

boost::uuids::uuid Room::getID() {
    return ID;
}

