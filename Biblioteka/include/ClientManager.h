#ifndef PROJEKT_CLIENTMANAGER_H
#define PROJEKT_CLIENTMANAGER_H

#include "iostream"
#include <memory>

using namespace std;

class Client;

class ClientRepository;

class ClientManager {
private:
    shared_ptr<ClientRepository> clientRepository;
public:
    ClientManager(shared_ptr<ClientRepository>);
    ~ClientManager();
    bool addClient(shared_ptr<Client>);
    bool removeClient(shared_ptr<Client>);
    shared_ptr<Client> getClient(shared_ptr<Client>);
    shared_ptr<ClientRepository> getClientRepository();
    string clientInfo();
    shared_ptr<Client> getClientByNumber(unsigned int);
};
typedef shared_ptr<ClientManager> spCM;


#endif //PROJEKT_CLIENTMANAGER_H
