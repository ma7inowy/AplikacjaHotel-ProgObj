#include <boost/test/unit_test.hpp>

#include "Client.h"
#include "ClientRepository.h"
#include "ClientManager.h"
#include "Exceptions.h"
#include "Address.h"
#include <memory>

using namespace std;

BOOST_AUTO_TEST_CASE(ClientTest) {
    shared_ptr<Address> adres1(new Address("Szeroka 1","2","Tomaszów Mazowiecki","Polska"));
    Client* c1 = new Client("Andrzej Orzinski",adres1);
    Client* c2 = new Client("Szymon Pawlak",adres1);
    BOOST_CHECK(c1->getName()=="Andrzej Orzinski");
    BOOST_CHECK(c1->getAddress()==adres1);
    BOOST_CHECK(c2->getAddress()==c1->getAddress());
    BOOST_CHECK(c2->getName()!=c1->getName());
    BOOST_CHECK(c2->getClientID()!=c1->getClientID());
    BOOST_CHECK_THROW(Client c3("A B",nullptr),ClientCreationException);
    delete c1;
    delete c2;
}

BOOST_AUTO_TEST_CASE(ClientRepoTest) {
    shared_ptr<Address> adres1(new Address("Szeroka 1","2","Tomaszów Mazowiecki","Polska"));
    shared_ptr<Client> c1 ( new Client("Andrzej Orzinski",adres1));
    shared_ptr<Client> c2 ( new Client("Szymon Orzinski",adres1));
    shared_ptr<ClientRepository> cr(new ClientRepository ());
    BOOST_CHECK(cr->addClient(c1));
    BOOST_CHECK(cr->removeClient(c1));
    BOOST_CHECK(c1->getAddress()==adres1);
    BOOST_CHECK(cr->addClient(c1));
    BOOST_CHECK(!cr->checkIfNotDuplicate(c1));
    BOOST_CHECK(cr->checkIfNotDuplicate(c2));
}

BOOST_AUTO_TEST_CASE(ClientManagerTest) {
    shared_ptr<Address> adres1(new Address("Szeroka 1","2","Tomaszów Mazowiecki","Polska"));
    shared_ptr<Client> c1 ( new Client("Andrzej Orzinski",adres1));
    shared_ptr<Client> c2 ( new Client("Szymon Orzinski",adres1));
    shared_ptr<ClientRepository> cr(new ClientRepository ());
    shared_ptr<ClientManager> cm(new ClientManager (cr));
    BOOST_CHECK(cm->getClientRepository()==cr); //konstruktor
    BOOST_CHECK(cm->addClient(c1)); //dodanie
    BOOST_CHECK(!cm->addClient(c1)); // duplikat
    BOOST_CHECK(cm->removeClient(c1)); //usuwanie
    BOOST_CHECK(!cm->removeClient(c1)); //usuwanie z pustego repozytorium
}