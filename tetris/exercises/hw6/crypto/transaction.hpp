#include <string>

class Transaction {
    private:
        // Type of transaction (0 = buy, 1 = sell)
        int type;
        // Coin being traded
        string coinName;
        // Amount of coin being bought/sold
        double amount;
        // Exchange rate value at the time of transation
        double valueSnapshot;
    
    public:
        // Constructor
        Transaction (int type, string coinName, double amount, double valueSnapshot);
};
