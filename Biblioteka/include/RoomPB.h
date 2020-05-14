#ifndef PROJECT_ROOMPB_H
#define PROJECT_ROOMPB_H

#include "Premium.h"
#include <iostream>
using namespace std;

class RoomPB:public Premium{
public:
    RoomPB(int people, double baseBookPrice);
   virtual  ~RoomPB();

    virtual string typeName();
};

typedef shared_ptr<RoomPB> spRPB;
#endif //PROJECT_ROOMPB_H
