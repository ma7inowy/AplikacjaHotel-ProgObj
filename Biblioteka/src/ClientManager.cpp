#include "ClientManager.h"
#include "ClientRepository.h"
#include <list>
#include <memory>
#include <ClientManager.h>


ClientManager::ClientManager(shared_ptr<ClientRepository> clientRepository) {
    this->clientRepository = clientRepository;
}

ClientManager::~ClientManager()=default;

bool ClientManager::addClient(shared_ptr<Client> client) {
    if(clientRepository->checkIfNotDuplicate(client)) {
        clientRepository->addClient(client);
        return true;
    }
    else
        return false;
}

bool ClientManager::removeClient(shared_ptr<Client> client) {
   if(clientRepository->removeClient(client))
        return true;
   else
       return false;
}

shared_ptr<Client> ClientManager::getClient(shared_ptr<Client> client) {
    return client;
}

shared_ptr<ClientRepository> ClientManager::getClientRepository() {
    return clientRepository;
}

string ClientManager::clientInfo() {
    return clientRepository->clientsInfo();

}

shared_ptr<Client> ClientManager::getClientByNumber(unsigned int liczba) {
    return clientRepository->getClientByN(liczba);
}
