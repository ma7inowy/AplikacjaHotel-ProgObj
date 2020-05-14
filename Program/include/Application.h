#ifndef PROJEKT_APPLICATION_H
#define PROJEKT_APPLICATION_H

#include <iostream>
#include "ClientManager.h"
#include "BookManager.h"
#include "RoomManager.h"

using namespace std;

class Application{
private:
    spCM cm;
    spBM bm;
    spRM rm;
public:
    Application(spCM, spBM, spRM);
    ~Application();
    void start();
    string months();
    bool checkDate(unsigned int, unsigned int, unsigned int);

};

#endif //PROJEKT_APPLICATION_H
