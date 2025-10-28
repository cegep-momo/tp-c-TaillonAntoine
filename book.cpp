#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;

// constucteur par defaut
Book::Book() : title(""), author(""), isbn("") {}

// constructeur avec parametre
Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn) {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; };
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }

// Setters
void Book::setTitle(const string &title) { this->title = title; }
void Book::setAuthor(const string &author) { this->author = author; }
void Book::setISBN(const string &isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerName(const string &name) { this->borrowerName = name; }

// Methods
void Book::checkOut(const string &borrower)
{
    if (isAvailable)
    {
        borrowerName = borrower;
    }
}

void Book::returnBook()
{
    isAvailable = true;
    borrowerName = "";
}

string Book::toString() const
{
    string result = "Nom: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nDisponible: " + to_string(isAvailable) + "\nNom du detenteur: " + borrowerName;
    return result;
}

string Book::toFileFormat() const
{
    string result = title + "|" + author + "|" + isbn + "|" + to_string(isAvailable) + "|" + borrowerName;
    return result;
}

void Book::fromFileFormat(const string &line)
{
    stringstream ss(line);
    string token;

    getLine(ss, title, '|');
    getLine(ss, author, '|');
    getLine(ss, isbn, '|');
    getLine(ss, to_string(isAvailable) '|');
    getLine(ss, borrowerName, '|');
}