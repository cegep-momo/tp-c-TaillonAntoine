#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;

// constucteur par defaut
Book::Book() : title(""), author(""), isbn("") {}

// constructeur avec parametre
Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn) {}