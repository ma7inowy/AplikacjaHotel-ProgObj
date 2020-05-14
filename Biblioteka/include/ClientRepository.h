#ifndef PROJEKT_CLIENTREPOSITORY_H
#define PROJEKT_CLIENTREPOSITORY_H

#include "iostream"
#include <memory>
#include <list>
using namespace std;

class Client;
class ClientRepository {
private:
    list<shared_ptr<Client>> clientList;
public:
    ClientRepository();
    string clientsInfo();
    bool addClient(shared_ptr<Client>);
    bool removeClient(shared_ptr<Client>);
    bool checkIfNotDuplicate(shared_ptr<Client>); // true if there are no duplicates, false if there's duplicate
    ~ClientRepository();
    shared_ptr<Client> getClientByN(unsigned int);
};

typedef shared_ptr<ClientRepository> spCR;

#endif //PROJEKT_CLIENTREPOSITORY_H
