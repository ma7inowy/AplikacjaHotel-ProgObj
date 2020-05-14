#include "Address.h"
#include <sstream>
using namespace std;

Address::Address(string street,string number, string city, string country) {
    this->street=street;
    this->number=number;
    this->city=city;
    this->country=country;
}

string Address::getStreet() {
    return street;
}

string Address::getNumber() {
    return number;
}

string Address::getCity() {
    return city;
}

string Address::getCountry() {
    return country;
}

string Address::stringInfo() {
    stringstream str;
    str<<"Street: "<<street<<", Number: "<<number<<", City: "<<city<<", Country: "<<country<<endl;
    return str.str();
}
Address::~Address()=default;