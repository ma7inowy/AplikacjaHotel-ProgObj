#include "ClientRepository.h"
#include "Client.h"
#include <sstream>
#include <ClientRepository.h>


ClientRepository::ClientRepository() {

}

string ClientRepository::clientsInfo() {
    stringstream str;
    list<shared_ptr<Client>> ::iterator it;
    int i = 1;
    for(it = clientList.begin(); it != clientList.end();it++) {
        str <<"    "<< i <<"    "<< (*it)->clientInfo()<<endl;
        i++;
    }
    return str.str();
}

bool ClientRepository::addClient(shared_ptr<Client> client) {
    clientList.push_back(client);
    return true;
}

bool ClientRepository::removeClient(shared_ptr<Client> client) {
    list<shared_ptr<Client>> ::iterator it;
    if(clientList.empty())
        return false;
    else {
        for (it = clientList.begin(); it != clientList.end(); it++) {
            if ((*it)->clientInfo() == client->clientInfo()) {
                clientList.erase(it);
                return true;
            }
        }
        return false;
    }
}

ClientRepository::~ClientRepository() = default;

bool ClientRepository::checkIfNotDuplicate(shared_ptr<Client> client)
{
    list<shared_ptr<Client>> ::iterator it;
    for(it=clientList.begin(); it!=clientList.end(); it++)
    {
        if(client->clientInfo()==(*it)->clientInfo())
            return false;
    }
    return true;
}

shared_ptr<Client> ClientRepository::getClientByN(unsigned int liczba)  {
    list<spC>::iterator it;
    unsigned int i = 1;
    for(it = clientList.begin(); it != clientList.end(); it++, i++) {
        if (liczba == i)
            return (*it);
    }
    return nullptr;
}
