#ifndef PROJECT_ROOM_H
#define PROJECT_ROOM_H

#include <iostream>
#include "RoomType.h"
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace std;

class Room{
private:
    shared_ptr<RoomType> roomType=nullptr;
    boost::uuids::uuid ID;
public:
    Room(shared_ptr<RoomType>);
    ~Room();
    string roomInfo();
    shared_ptr<RoomType> getRoomType();
    boost::uuids::uuid getID();
};
typedef shared_ptr<Room> spR;
#endif //PROJECT_ROOM_H
