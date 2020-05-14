#include "Book.h"
#include "Exceptions.h"

Book::Book(spC client,spR room,ptime bookFirstDay,ptime bookLastDay)
{
    if(client==nullptr)
        throw BookCreationException("Nie można utworzyć wynajmu bez klienta (obiekt Client o wartości nullptr).");
    this->client = client;
    if(room==nullptr)
        throw BookCreationException("Nie można utworzyć wynajmu bez pokoju (obiekt Room o wartości nullptr).");
    this->room = room;
    this->bookID = boost::uuids::random_generator()();

    time_period periodOfRent{bookFirstDay, bookLastDay};
    int length=periodOfRent.length().hours()/24;
    if(length<=0)
        throw BookCreationException("Nie można utworzyć wynajmu z datą końcową wcześniejszą lub taką samą jak data końcowa.");
    this->bookFirstDay = bookFirstDay;
    this->bookLastDay = bookLastDay;
    bookPrice = bookDays() * room->getRoomType()->getBaseBookPrice();
}

unsigned int Book::bookDays()
{
    stringstream xtime;
    xtime<<bookLastDay;
    time_period periodOfBook{bookFirstDay, bookLastDay};
    return (unsigned int)periodOfBook.length().hours()/24;
}
boost::uuids::uuid Book::getBookID()
{
    return bookID;
}
Book::~Book()=default;
string Book::bookInfo()
{
    stringstream ss;
    stringstream pom1;
    stringstream pom2;
    pom1<<bookFirstDay;
    pom2<<bookLastDay;
    string bookFD = pom1.str().substr(0,11);
    string bookLD = pom2.str().substr(0,11);
    ss<<"Book ID: "<<bookID<<endl;
    ss<<"Client:\n"<<client->clientInfo()<<"Room:\n"<<room->roomInfo()<<"Info:\n";
    ss<<"First book day: "<<bookFD<<" , last book day: "<<bookLD<<" , number of days: "<<bookDays()<<endl;
    ss<<"Price: "<<bookPrice<<endl;

    return ss.str();
}
spC Book::getClient()
{
    return client;
}

spR Book::getRoom()
{
    return room;
}

string Book::getBookIDstr() {
    stringstream ss;
    ss<<bookID<<endl;
    return ss.str();
}

ptime Book::getBookLastDay() {
    return bookLastDay;
}

ptime Book::getBookFirstDay() {
    return bookFirstDay;
}
