#ifndef PROJECT_ROOMPA_H
#define PROJECT_ROOMPA_H
#include "Premium.h"
#include <iostream>
using namespace std;

class RoomPA: public Premium{
    const bool freeDinner=true;
public:
    RoomPA(int people,double baseBookPrice);
    virtual ~RoomPA();

    bool getFreeDinner();
    virtual string typeName();

};

typedef shared_ptr<RoomPA> spRPA;
#endif //PROJECT_ROOMPA_H
