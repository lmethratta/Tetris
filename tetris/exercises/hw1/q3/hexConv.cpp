#include <iostream>
#include <string>

int main(){
    std::string hex;
    int dec;

    std::cout << "Please input a hex number:\n";
    std::cin >> hex;

    std::string truncHex = hex.substr(2);
    int length = truncHex.length();

    for(int i = 0; i < length; i++) {
        dec *= 16;
        char c = truncHex[i];
        if(c >= 'a' && c <= 'z') {
            dec += c - 'a' + 10;
            continue;
        }
        if(c >= 'A' && c <= 'Z') {
            dec += c - 'A' + 10;
            continue;
        }

        dec += (int) c - '0';
    }

    std::cout << "Your number " << hex << " (in hex) is equivalent to " << dec << " (in decimal)\n";

    return 0;
}
