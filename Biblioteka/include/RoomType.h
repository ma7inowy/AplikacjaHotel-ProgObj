#ifndef PROJECT_ROOMTYPE_H
#define PROJECT_ROOMTYPE_H

#include <iostream>
#include <memory>

using namespace std;

class RoomType{
    int people;
    double baseBookPrice;
public:
    RoomType(int people,double baseBookPrice);
    virtual ~RoomType();
    int getPeople();
    virtual string typeName()=0;
    double getBaseBookPrice();
    void setMultiplierBaseBookPrice(int);
};

typedef shared_ptr<RoomType> spRT;
#endif //PROJECT_ROOMTYPE_H
