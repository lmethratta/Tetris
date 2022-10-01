#include "top100.hpp"
#include "book.hpp"
#include "movie.hpp"
#include <vector>

using namespace std;

int main(void) {
    //Test Checklist
    //  -Over 100 items
    //  -Adding item
    //  -Adding vector of items
    //  -Remove item
    //  -Remove vector of items
    //  -Update item on duplicate adding
    //  -Return ranking of item, including out of bounds
    //  -Return number of items in list
    //  -User input test

    // Book list
    top100<Book> bookList;
    cout << endl << "Book Test:" << endl;
    cout << "Creating four books..." << endl;
    Book* book1 = new Book("Book Title", 1984, "Quinn Dyer", 7.2, "Mystery");
    Book* book2 = new Book("Book Title", 1984, "Quinn Dyer", 5.2, "Drama");
    Book* book3 = new Book("Book Title!!", 1312, "Bob Dyer", 6.2, "History");
    Book* book4 = new Book("Book Title!!!", 1231, "Dyer Dyer", 8.2, "Mystery");
    cout << "Adding book 1-3 to top100 list... (one repeat title)" << endl;
    bookList.addItem(*book1);
    bookList.addItem(*book2);
    bookList.addItem(*book3);
    cout << "Book in list: " << bookList.numItems() << endl;
    cout << "Position of book1 (rating 7.2, updated to 5.2): " << bookList.itemRanking(*book1) << endl;
    cout << "Position of book2 (rating 5.2): " << bookList.itemRanking(*book2) << endl;
    cout << "Position of book3 (rating 6.2): " << bookList.itemRanking(*book3) << endl;
    cout << "Position of book4 (rating 8.2): " << bookList.itemRanking(*book4) << endl;
    cout << "Removing book1..." << endl;
    bookList.removeItem(*book1);
    cout << "Book in list: " << bookList.numItems() << endl << endl << endl;

    // Movie list
    top100<Movie> movieList;
    cout << "Movie Test:" << endl;
    cout << "Creating six movies..." << endl;
    Movie* movie1 = new Movie("Movie1", 2003, 3.2, "PG", "Horror");
    Movie* movie2 = new Movie("Movie2", 2001, 7.2, "G", "Action");
    Movie* movie3 = new Movie("Movie3", 1975, 1.2, "PG", "Thriller");
    Movie* movie4 = new Movie("Movie4", 1920, 9.2, "PG", "Horror");
    Movie* movie5 = new Movie("Movie5", 2020, 4.2, "R", "Comedy");
    Movie* movie6 = new Movie("Movie6", 2022, 4.6, "G", "Comedy");
    vector<Movie> movies1;
    movies1.push_back(*movie1);
    movies1.push_back(*movie2);
    movies1.push_back(*movie3);
    movies1.push_back(*movie4);
    movies1.push_back(*movie5);
    movies1.push_back(*movie6);
    cout << "Adding all 6 movies to top100 list via one vector..." << endl;
    movieList.addItems(movies1);
    cout << "Movies in list: " << movieList.numItems() << endl;
    cout << "All movie item rankings:"  << endl;
    cout << "Position of movie1 (rating 3.2): " << movieList.itemRanking(*movie1) << endl;
    cout << "Position of movie2 (rating 7.2): " << movieList.itemRanking(*movie2) << endl;
    cout << "Position of movie3 (rating 1.2): " << movieList.itemRanking(*movie3) << endl;
    cout << "Position of movie4 (rating 9.2): " << movieList.itemRanking(*movie4) << endl;
    cout << "Position of movie5 (rating 4.2): " << movieList.itemRanking(*movie5) << endl;
    cout << "Position of movie6 (rating 4.6): " << movieList.itemRanking(*movie6) << endl;
    vector<Movie> movies2;
    cout << "Removing vector of movies 1,3,5" << endl;
    movies2.push_back(*movie1);
    movies2.push_back(*movie3);
    movies2.push_back(*movie5);
    movieList.removeItems(movies2);
    cout << "Movies in list: " << movieList.numItems() << endl;
    cout << "All movie item rankings:"  << endl;
    cout << "Position of movie1 (rating 3.2): " << movieList.itemRanking(*movie1) << endl;
    cout << "Position of movie2 (rating 7.2): " << movieList.itemRanking(*movie2) << endl;
    cout << "Position of movie3 (rating 1.2): " << movieList.itemRanking(*movie3) << endl;
    cout << "Position of movie4 (rating 9.2): " << movieList.itemRanking(*movie4) << endl;
    cout << "Position of movie5 (rating 4.2): " << movieList.itemRanking(*movie5) << endl;
    cout << "Position of movie6 (rating 4.6): " << movieList.itemRanking(*movie6) << endl << endl << endl;

    // int list
    top100<int> intList;
    cout << "Int Test:"  << endl;
    cout << "Adding ints 1-200..."  << endl;
    for(int i = 1; i < 201; i++) {
        intList.addItem(i);
    }
    cout << "Ints in list (should cap at 100): " << intList.numItems() << endl;
    cout << "Position of int 3: " << intList.itemRanking(3) << endl;
    cout << "Position of int 20: " << intList.itemRanking(20) << endl;
    cout << "Position of int 100: " << intList.itemRanking(100) << endl;
    cout << "Position of int 101: " << intList.itemRanking(101) << endl;
    cout << "Position of int 150: " << intList.itemRanking(150) << endl;
    cout << "Removing int 20..."  << endl;
    intList.removeItem(20);
    cout << "Ints in list (should cap at 100): " << intList.numItems() << endl;
    cout << "Position of int 3: " << intList.itemRanking(3) << endl;
    cout << "Position of int 20: " << intList.itemRanking(20) << endl;
    cout << "Position of int 100: " << intList.itemRanking(100) << endl;
    cout << "Position of int 101: " << intList.itemRanking(101) << endl;
    cout << "Position of int 150: " << intList.itemRanking(150) << endl << endl << endl;

    // user int list
    top100<int> intList2;
    cout << "User Int Test:"  << endl;
    cout << "Please enter 5 integers..."  << endl;
    int temp;
    vector<int> ints;
    for(int i = 1; i < 6; i++) {
        cout << "Enter integer " << i << ":" << endl;
        cin >> temp;
        ints.push_back(temp);
        intList2.addItem(temp);
    }
    cout << "Ints in list: " << intList2.numItems() << endl;
    cout << "Position of int " << ints[0] << ": " << intList2.itemRanking(ints[0]) << endl;
    cout << "Position of int " << ints[1] << ": " << intList2.itemRanking(ints[1]) << endl;
    cout << "Position of int " << ints[2] << ": " << intList2.itemRanking(ints[2]) << endl;
    cout << "Position of int " << ints[3] << ": " << intList2.itemRanking(ints[3]) << endl;
    cout << "Position of int " << ints[4] << ": " << intList2.itemRanking(ints[4]) << endl;
    return 0;
}