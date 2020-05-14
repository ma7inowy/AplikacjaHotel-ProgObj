
#include <RoomPA.h>

#include "RoomPA.h"

RoomPA::RoomPA(int people, double baseBookPrice):Premium(people, baseBookPrice) {

}

RoomPA::~RoomPA() {

}


bool RoomPA::getFreeDinner() {
  return freeDinner;
}

string RoomPA::typeName() {
return "RoomPA";
}




