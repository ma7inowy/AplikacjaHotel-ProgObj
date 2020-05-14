#ifndef PROJECT_ROOMBASIC_H
#define PROJECT_ROOMBASIC_H

#include "RoomType.h"
#include <iostream>
using namespace std;

class RoomBasic: public RoomType{
public:
    RoomBasic(int people,double baseBookPrice);
    virtual ~RoomBasic();

    virtual string typeName();


};

typedef shared_ptr<RoomBasic> spRB;
#endif //PROJECT_ROOMBASIC_H
