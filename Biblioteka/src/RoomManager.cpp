#include "RoomRepository.h"
#include "RoomManager.h"
#include "Room.h"
#include <sstream>
#include <memory>
#include <RoomManager.h>

RoomManager::RoomManager(shared_ptr<RoomRepository> roomRepository): roomRepository(roomRepository){}

RoomManager::~RoomManager() {}

bool RoomManager::addRoom(shared_ptr<Room> room) {

   if(!roomRepository->duplication(room))
   {
       roomRepository->addRoom(room);
       return true;
   }
return false;
}


bool RoomManager::removeRoom(shared_ptr<Room> room) {
    if(roomRepository->removeRoom(room))
    {
        return true;
    }
    else return false;

}

shared_ptr<Room> RoomManager::getRoom(shared_ptr<Room> room)
{
    return room;
}

string RoomManager::roomInfo() {
    return roomRepository->roomsInfo();
}

shared_ptr<Room> RoomManager::getRoomByNumber(unsigned int liczba) {
    return roomRepository->getRoomByN(liczba);
}
