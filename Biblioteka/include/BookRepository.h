#ifndef PROJEKT_BOOKREPOSITORY_H
#define PROJEKT_BOOKREPOSITORY_H
#include <memory>
#include <iostream>
#include <list>

using namespace std;

class Book;

class BookRepository{
    list<shared_ptr<Book>>currentBookList;
    list<shared_ptr<Book>>archiveBookList;
public:
    BookRepository();
    string booksInfo();
    string archiveBooksInfo();
    bool addCurrentBook(shared_ptr<Book>);
    bool removeBook(shared_ptr<Book>);
    bool duplication(shared_ptr<Book>); // true if there is duplicate, false if not
    ~BookRepository()=default;
    shared_ptr<Book> getBookByNumber(unsigned int);
};

typedef shared_ptr<BookRepository> spBR;
#endif //PROJEKT_BOOKREPOSITORY_H
