#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H
#define BOOST_UUID_RANDOM_PROVIDER_FORCE_WINCRYPT
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <memory>
using namespace std;

class Address;
typedef shared_ptr<Address> spA;

class Client
{
private:
    string name;
    boost::uuids::uuid clientID;
    spA address;
public:
    Client(string,spA);
    string getName();
    boost::uuids::uuid getClientID();
    spA getAddress();
    string clientInfo();
    ~Client();

};

typedef shared_ptr<Client> spC;

#endif //PROJECT_CLIENT_H