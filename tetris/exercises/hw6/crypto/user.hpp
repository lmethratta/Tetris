#include <string>
#include <vector>
#include "wallet.hpp"
#include "transaction.hpp"

class User {
    private:
        // Users full name (ex: Quinn Dyer)
        string name;
        // User date of birth (format: xx/xx/xx)
        string dob;
        // User's wallet
        Wallet wallet;
        // Transaction history, list of transactions
        vector<Transaction> transactions;
    public:
        // Constructor, will initialize with empty wallet and transaction history
        User(string name, string dob);
        // Access the wallet for starting buy/sell transactions
        Wallet getWallet();
}