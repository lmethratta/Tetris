#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

int main(){
    srand (time(NULL));
    std::string s = "";
    int spaces = 0, alphanums = 0, nums = 0;
    for(int i = 0; i < 1000; i++) {
        int randomInt = rand() % 96 + 32;
        if (randomInt <= 57 && randomInt >= 47) {
            //nums++;
            //alphanums++;
            continue;
        } else if ((randomInt <= 90 && randomInt >= 65) || (randomInt <= 122 && randomInt >= 97)) {
            alphanums++;
        } else if (randomInt == 32) {
            spaces++;
            if (spaces % 10 == 0) {
                randomInt = 10;
            }
        } else if (randomInt != 46) {
            spaces++;
            randomInt = 32;
            if (spaces % 10 == 0) {
                randomInt = 10;
            }
        }
        s.push_back((char) randomInt);
    }
    std::cout << "Spaces: " << spaces << "\n";
    std::cout << "Numbers: " << nums << "\n";
    std::cout << "Alphanumeric Characters: " << alphanums << "\n";
    std::cout << s;

    // First run: 7 valid words
    // Second run: 8 valid words
    // Third run: 6 valid words
    return 0;
}
