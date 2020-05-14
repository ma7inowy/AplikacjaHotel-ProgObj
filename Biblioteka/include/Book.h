#ifndef PROJEKT_BOOK_H
#define PROJEKT_BOOK_H

#define BOOST_UUID_RANDOM_PROVIDER_FORCE_WINCRYPT
#include <iostream>
#include <memory>
#include "Room.h"
#include "Client.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "boost/date_time/local_time/local_time.hpp"
using namespace std;
using namespace boost::gregorian;
using namespace boost::local_time;
using namespace boost::posix_time;

class Client;
class Room;


typedef shared_ptr<Room> spR;

class Book {
private:
    boost::uuids::uuid bookID;
    ptime bookFirstDay;
    ptime bookLastDay;
    double bookPrice;
    spC client;
    spR room;
public:
    Book(spC,spR,ptime,ptime);
    boost::uuids::uuid getBookID();
    string bookInfo();
    unsigned int bookDays();
    spC getClient();
    spR getRoom();
    string getBookIDstr();
    ptime getBookFirstDay();
    ptime getBookLastDay();
    ~Book();
};

typedef shared_ptr<Book> spB;


#endif //PROJEKT_BOOK_H
