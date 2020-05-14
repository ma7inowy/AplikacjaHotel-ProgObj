#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include <iostream>
#include <memory>
using namespace std;

class Address{
private:
    string street;
    string number;
    string city;
    string country;
public:
    Address(string,string,string,string);
    ~Address();
    string getStreet();
    string getNumber();
    string getCity();
    string getCountry();
    string stringInfo();
};

typedef shared_ptr<Address> spA;

#endif //PROJECT_PREMIUM_H
