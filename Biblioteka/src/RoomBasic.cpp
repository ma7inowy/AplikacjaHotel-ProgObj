
#include <RoomBasic.h>

#include "RoomBasic.h"

RoomBasic::RoomBasic(int people, double baseBookPrice) : RoomType(people, baseBookPrice) {
}

RoomBasic::~RoomBasic() {
}



string RoomBasic::typeName() {
return "RoomBasic";
}
