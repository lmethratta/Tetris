#include "movie.hpp"
#include "string"

using namespace std;

Movie::Movie (string t, int y, double r, string p, string g) {
    title = t;
    pgRating = p;
    rating = r;
    year = y;
    genre = g;
}

bool Movie::operator==(const Movie& other) const {
    return other.title == title;
}

bool Movie::operator<(const Movie& other) const {
    return rating > other.rating;
}