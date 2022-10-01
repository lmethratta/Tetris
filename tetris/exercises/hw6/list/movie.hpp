#include "string"

using namespace std;

class Movie {
    private:
        string title;
        // Year format: xxxx, (ex: 1984)
        int year;
        // Rating between 0-10
        double rating;
        // One of: G, PG, PG-13, R
        string pgRating;
        string genre;
    public:
        // Constructor
        Movie (string t, int y, double r, string p, string g);
        bool operator==(const Movie& other) const;
        bool operator<(const Movie& other) const;
};