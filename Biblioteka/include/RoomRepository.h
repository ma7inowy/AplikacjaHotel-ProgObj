#ifndef PROJECT_ROOMREPOSITORY_H
#define PROJECT_ROOMREPOSITORY_H

#include <memory>
#include <list>
#include <iostream>
class Room;
using namespace std;

class RoomRepository{
    list<shared_ptr<Room>> roomList;
public:
    RoomRepository();
    ~RoomRepository();
    string roomsInfo();
    bool addRoom(shared_ptr<Room>);
    bool removeRoom(shared_ptr<Room>);
    bool duplication(shared_ptr<Room>);
    shared_ptr<Room> getRoomByN(unsigned int);
};

typedef shared_ptr<RoomRepository> spRR;
#endif //PROJECT_ROOMREPOSITORY_H
