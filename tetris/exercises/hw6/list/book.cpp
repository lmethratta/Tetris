#include "book.hpp"
#include "string"

using namespace std;

Book::Book (string t, int y, string a, double r, string g) {
    title = t;
    author = a;
    rating = r;
    genre = g;
}

bool Book::operator==(const Book& other) const {
    return other.title == title;
}

bool Book::operator<(const Book& other) const {
    return rating > other.rating;
}