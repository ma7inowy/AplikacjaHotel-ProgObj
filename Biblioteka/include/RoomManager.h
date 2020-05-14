#ifndef PROJECT_ROOMMANAGER_H
#define PROJECT_ROOMMANAGER_H
#include <iostream>
#include <memory>
using namespace std;

class RoomRepository;
class Room;

class RoomManager{
    shared_ptr<RoomRepository> roomRepository;
public:
    RoomManager(shared_ptr<RoomRepository> roomRepository);
    ~RoomManager();
    bool addRoom(shared_ptr<Room>);
    bool removeRoom(shared_ptr<Room>);
    shared_ptr<Room> getRoom(shared_ptr<Room>);
    string roomInfo();
    shared_ptr<Room> getRoomByNumber(unsigned int);


};

typedef shared_ptr<RoomManager> spRM;

#endif //PROJECT_ROOMMANAGER_H
