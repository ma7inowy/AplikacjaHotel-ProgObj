#include "Client.h"
#include "Address.h"
#include "Exceptions.h"

#include <sstream>

Client::Client(string name, spA address)
{
    this->name = name;
    this->clientID = boost::uuids::random_generator()();
    if(address==nullptr)
        throw ClientCreationException("Nie można stworzyć klienta bez adresu (z adresem o wartości nullptr).");
    this->address  = address;
}
string Client::getName()
{
    return name;
}
boost::uuids::uuid Client::getClientID()
{
    return clientID;
}

spA Client::getAddress()
{
    return address;
}

Client::~Client()=default;

string Client::clientInfo()
{
    stringstream str;
    str<<"Name: "<<name<<", ID: "<<clientID<<", Address:\n"<<address->stringInfo();
    return str.str();
}