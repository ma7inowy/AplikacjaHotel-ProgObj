#ifndef PROJECT_PREMIUM_H
#define PROJECT_PREMIUM_H

#include <iostream>
#include "RoomType.h"
using namespace std;

class Premium: public RoomType{
    const bool kitchenette=true;
public:
    Premium(int people, double baseBookPrice);
    virtual ~Premium();
    bool getKitchenette();


};
#endif //PROJECT_PREMIUM_H
