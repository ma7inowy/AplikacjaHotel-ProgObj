#include <sstream>
#include <BookRepository.h>

#include "BookRepository.h"
#include "Book.h"

BookRepository::BookRepository()=default;

string BookRepository::booksInfo() {
    list<shared_ptr<Book>>::iterator it;
    stringstream strumyk;
    int i = 1;
    for (it = currentBookList.begin(); it != currentBookList.end(); it++)
    {
        strumyk<<"    "<< i++ <<"    "<<(*it)->bookInfo()<<endl;
    }
    return strumyk.str();
}

bool BookRepository::removeBook(shared_ptr<Book> book) {
    list<shared_ptr<Book>>::iterator it;
    for(it=currentBookList.begin();it!=currentBookList.end();it++)
    {
        if((*it)->bookInfo()==book->bookInfo()) {
            currentBookList.erase(it);
            archiveBookList.push_back(*it);
            return true;
        }
    }
    return false;
}

bool BookRepository::addCurrentBook(shared_ptr<Book> book) {
    currentBookList.push_back(book);
    return true;
}

bool BookRepository::duplication(shared_ptr<Book> book)
{
    list<shared_ptr<Book>>::iterator it;
    int check = 0;
    for(it = currentBookList.begin(); it != currentBookList.end(); it++)
    {
        if ((*it)->getBookID() == book->getBookID())
            ++check;
        if((*it)->getRoom() == book->getRoom())
        {
            if(!((book->getBookFirstDay() < (*it)->getBookFirstDay() && book->getBookLastDay() <= (*it)->getBookFirstDay())
             || (book->getBookFirstDay() >= (*it)->getBookLastDay()  && book->getBookLastDay() > (*it)->getBookLastDay()) ))
            {
               ++check;
            }
        }
        if((*it)->getClient() == book->getClient())
        {
            if( !((book->getBookFirstDay() < (*it)->getBookFirstDay() && book->getBookLastDay() <= (*it)->getBookFirstDay())
            || (book->getBookFirstDay() >= (*it)->getBookLastDay()  && book->getBookLastDay() > (*it)->getBookLastDay())))
            {
                ++check;
            }
        }
    }
    if(check==0)
        return false;
    else
        return true;
}

string BookRepository::archiveBooksInfo() {
    list<shared_ptr<Book>>::iterator it;
    stringstream strumyk;
    int i = 1;
    for (it = archiveBookList.begin(); it != archiveBookList.end(); it++)
    {
        strumyk<<"    "<< i++ <<"    "<<(*it)->bookInfo()<<endl;
    }
    return strumyk.str();
}

shared_ptr<Book> BookRepository::getBookByNumber(unsigned int liczba) {
    list<shared_ptr<Book>>::iterator it;
    unsigned int i = 1;
    for(it = currentBookList.begin(); it != currentBookList.end(); it++,i++) {
        if (liczba == i)
            return (*it);

    }
    return nullptr;
}

