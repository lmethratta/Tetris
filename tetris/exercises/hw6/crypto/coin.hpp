#include <string>

class Coin {
    private:
        // Name of coin (ex: Bitcoin)
        std::string name;
        // Value in USD (ex: 2,320.29)
        double value;
    
    public:
        // Constructor
        Coin (std::string name, double value);
        // Updates value of coin
        void updateValue(double newValue);
};
