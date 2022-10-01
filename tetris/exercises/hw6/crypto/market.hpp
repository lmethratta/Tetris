#include <vector>
#include <string>
#include "coin.hpp"

class Market {
    private:
        // List of all coins on market, including exchange rates.
        std::vector<Coin> coins;
    
    public:
        // Empty constructor
        Market ();
        // Adds new coin to the market with the given name and exchange rate value
        void addCoin(std::string name, double newValue);
        // Remove the given coin from the market
        void removeCoin(std::string name);
        // Updates value of given coin with given value
        void updateCoin(std::string name, double newValue);
};
