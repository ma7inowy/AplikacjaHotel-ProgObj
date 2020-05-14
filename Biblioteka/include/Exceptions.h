#ifndef PROJEKT_EXCEPTIONS_H
#define PROJEKT_EXCEPTIONS_H

#include <stdexcept>
#include <iostream>
using namespace std;
using std::logic_error;

class ClientException : public logic_error {
public:
    explicit ClientException(const string &s): logic_error(s) {}
    virtual ~ClientException() {}
};

class ClientCreationException : public ClientException
{
public:
    explicit ClientCreationException(const string &s): ClientException(s) {}
    virtual ~ClientCreationException() {}
};

class BookException : public logic_error {
public:
    explicit BookException(const string &s): logic_error(s) {}
    virtual ~BookException() {}
};


class BookCreationException : public BookException
{
public:
    explicit BookCreationException(const string &s): BookException(s) {}
    virtual ~BookCreationException() {}
};

#endif //PROJEKT_EXCEPTIONS_H
