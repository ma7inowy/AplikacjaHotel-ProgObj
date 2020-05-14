#include "Room.h"
#include "RoomRepository.h"
#include <sstream>
#include <RoomRepository.h>


RoomRepository::RoomRepository() {}
RoomRepository::~RoomRepository() {}

string RoomRepository::roomsInfo() {
    list<shared_ptr<Room>>::iterator it;
    stringstream strumyk;
    int i = 1;
    for(it=roomList.begin();it!=roomList.end();it++)
        strumyk<<"    "<< i++ <<"    "<<(*it)->roomInfo()<<";"<<endl;
    return strumyk.str();
}

bool RoomRepository::addRoom(shared_ptr<Room> room) {
    roomList.push_back(room);
        return true;
}

bool RoomRepository::removeRoom(shared_ptr<Room> room) {
    list<shared_ptr<Room>>::iterator it;
    if(!roomList.empty())
    {
        for(it = roomList.begin(); it != roomList.end(); it++)
        {
            if ((*it)->roomInfo() == room->roomInfo())
            {
                roomList.erase(it);
                return true;
            }

        }
        return false;
    }
    else
    {
        return false;
    }
}

bool RoomRepository::duplication(shared_ptr<Room> room)
{
    list<shared_ptr<Room>>::iterator it;
    for(it = roomList.begin(); it != roomList.end(); it++)
        if((*it)->roomInfo() == room->roomInfo())
            return true;
    return false;
}

shared_ptr<Room> RoomRepository::getRoomByN(unsigned int liczba) {
    list<spR>::iterator it;
    unsigned int i = 1;
    for(it = roomList.begin(); it != roomList.end(); it++,i++) {
        if (liczba == i)
            return (*it);

    }
    return nullptr;
}
