#ifndef PROJEKT_BOOKMANAGER_H
#define PROJEKT_BOOKMANAGER_H
#include <iostream>
#include <memory>

using namespace std;
class BookRepository;
class Book;
class BookManager{
    shared_ptr<BookRepository> bookRepository;
public:
    BookManager(shared_ptr<BookRepository>);
    bool addBook(shared_ptr<Book>);
    bool removeBook(shared_ptr<Book>);
    shared_ptr<Book> getBook(shared_ptr<Book>);
    ~BookManager()=default;
    string booksInfo();
    string archiveBooksInfo();
    shared_ptr<Book> getBookByNumber(unsigned int);
};

typedef shared_ptr<BookManager> spBM;

#endif //PROJEKT_BOOKMANAGER_H
