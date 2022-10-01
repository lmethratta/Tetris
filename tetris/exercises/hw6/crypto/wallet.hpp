#include <vector>
#include <string>
#include "market.hpp"

using namespace std;

class Wallet {
    private:
        // Pointer to the market, used for referencing exchange rates
        Market* market;
        // List of coins owned, and quantity of each coin
        vector< pair<string,double> > coins;
    public:
        // Constructor
        Wallet (Market* market);
        // Add a given amount of the given coin to the wallet
        void addFunds(string coin, double value);
        // Attempt to sell given amount of given coin, returns 0 on success and 1 on failure
        int sellCoin(string coin, double value);
        // Attempt to buy given amount of given coin, returns 0 on success and 1 on failure
        int buyCoin(string coin, double value);
};
