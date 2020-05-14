
#include <RoomPB.h>

#include "RoomPB.h"

RoomPB::RoomPB(int people,double baseBookPrice) : Premium(people,baseBookPrice) {
}

RoomPB::~RoomPB() {

}




string RoomPB::typeName() {
return "RoomPB";
}
