#include "string"

using namespace std;

class Book {
    private:
        string title;
        // Year format: xxxx, (ex: 1984)
        int year;
        // Author full name (ex: Quinn Dyer)
        string author;
        // Rating between 0-10
        double rating;
        string genre;
    public:
        // Constructor
        Book (string t, int y, string a, double r, string g);
        bool operator==(const Book& other) const;
        bool operator<(const Book& other) const;
};