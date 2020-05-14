#include <boost/test/unit_test.hpp>
#include <iostream>
#include <memory>
#include "Client.h"
#include "Address.h"
#include "ClientRepository.h"
#include "ClientManager.h"
#include "Room.h"
#include "Book.h"
#include "BookRepository.h"
#include "BookManager.h"
#include "Exceptions.h"
#include "RoomRepository.h"
#include "RoomManager.h"
#include "RoomType.h"
#include "RoomBasic.h"
#include "RoomPA.h"
#include "RoomPB.h"

typedef shared_ptr<ClientRepository> spCR;
typedef shared_ptr<ClientManager> spCM;
typedef shared_ptr<Client> spC;

BOOST_AUTO_TEST_CASE(BookTest) {
    shared_ptr<RoomPB>rPB (new RoomPB(6,300));
    shared_ptr<Room>room1(new Room(rPB));
    shared_ptr<RoomRepository> rR(new RoomRepository());
    shared_ptr<RoomManager> rM(new RoomManager(rR));
    rM->addRoom(room1);
    spA adres1(new Address("Rymanowska 13", "21", "Łódź", "Polska"));
    spC c1(new Client("Andrzej Nowak", adres1));
    spCR cRepository(new ClientRepository);
    spCM cManager(new ClientManager(cRepository));
    cManager->addClient(c1);
    shared_ptr<BookRepository> bookcurrrepo(new BookRepository());
    shared_ptr<BookManager> bookman(new BookManager(bookcurrrepo));
    shared_ptr<Book> book1(new Book(c1,room1,ptime(second_clock::local_time()-days(3)),ptime(second_clock::local_time())));
    shared_ptr<Book> book2(new Book(c1,room1,ptime(second_clock::local_time()-days(2)),ptime(second_clock::local_time())));

    BOOST_CHECK(c1==book1->getClient());
    BOOST_CHECK(room1==book1->getRoom());
    BOOST_CHECK(book1->getBookID()!=book2->getBookID());
}

BOOST_AUTO_TEST_CASE(BookDuplicatesTest) {
    shared_ptr<RoomPB>rPB (new RoomPB(6,300));
    shared_ptr<Room>room1(new Room(rPB));
    shared_ptr<Room>room2(new Room(rPB));
    shared_ptr<RoomRepository> rR(new RoomRepository());
    shared_ptr<RoomManager> rM(new RoomManager(rR));
    rM->addRoom(room1);
    rM->addRoom(room2);
    spA adres1(new Address("Rymanowska 13", "21", "Łódź", "Polska"));
    spC c1(new Client("Andrzej Nowak", adres1));
    spC c2(new Client("Krystian Kowalski", adres1));
    spCR cRepository(new ClientRepository);
    spCM cManager(new ClientManager(cRepository));
    cManager->addClient(c1);
    cManager->addClient(c2);
    shared_ptr<BookRepository> bookcurrrepo(new BookRepository());
    shared_ptr<BookManager> bookman(new BookManager(bookcurrrepo));

    shared_ptr<Book> book1(new Book(c1, room1, ptime(date(2018, Nov, 2)), ptime(date(2018, Nov, 5))));
    shared_ptr<Book> book2(new Book(c1, room1, ptime(date(2018, Nov, 5)), ptime(date(2018, Nov, 7))));
    shared_ptr<Book> book3(new Book(c1, room1, ptime(date(2018, Nov, 4)), ptime(date(2018, Nov, 5))));
    shared_ptr<Book> book4(new Book(c2, room1, ptime(date(2018, Dec, 5)), ptime(date(2018, Dec, 12))));
    shared_ptr<Book> book5(new Book(c2, room2, ptime(date(2018, Dec, 5)), ptime(date(2018, Dec, 7))));
    shared_ptr<Book> book6(new Book(c2, room1, ptime(date(2018, Dec, 6)), ptime(date(2018, Dec, 7))));
    BOOST_CHECK(bookman->addBook(book1)); //  klient 1 nov 2-5 pokoj 1
    BOOST_CHECK(bookman->addBook(book2)); //  klient 1 nov 5-7 pokoj 1
    BOOST_CHECK(!bookman->addBook(book3)); // klient 1 nov 4-5 pokoj 1 - pokoj juz zajety, ten sam klient w tych samych dniach
    BOOST_CHECK(bookman->addBook(book4)); //  klient 2 dec 5-12 pokoj 1
    BOOST_CHECK(!bookman->addBook(book5)); // klient 2 dec 5-7 pokoj 2 - nie mozna temu samemu klientowi dac dwoch pokojow
    BOOST_CHECK(!bookman->addBook(book6)); // klient 2 dec 6-7 pokoj 1 - ten sam klient w tych samych dniachw
    BOOST_CHECK(bookman->removeBook(book4)); // usuniecie wypozyczenia
    BOOST_TEST_MESSAGE(bookman->booksInfo());





}

