
#include <BookManager.h>

#include "BookRepository.h"
#include "Book.h"
#include "BookManager.h"

BookManager::BookManager(shared_ptr<BookRepository> bookRepository) {
    this->bookRepository=bookRepository;
}

bool BookManager::addBook(shared_ptr<Book> book) {
    if(!bookRepository->duplication(book))
    {
        bookRepository->addCurrentBook(book);
        return true;
    }
    else return false;
}

bool BookManager::removeBook(shared_ptr<Book>book) {
    if(bookRepository->removeBook(book))
    {
        return true;
    }
    else return false;
}

shared_ptr<Book> BookManager::getBook(shared_ptr<Book>book) {
    return book;
}

string BookManager::booksInfo() {
    return bookRepository->booksInfo();
}

string BookManager::archiveBooksInfo() {
    return bookRepository->archiveBooksInfo();
}

shared_ptr<Book> BookManager::getBookByNumber(unsigned int liczba) {
    return bookRepository->getBookByNumber(liczba);
}
