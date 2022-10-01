
#include <iostream>

int main() {

    int size;
    std::cout << "Please enter size of pattern (Minimum 1): ";
    std::cin >> size;

    std::cout << "\n";

    // Thin to thick triangle pattern
    for (int i = 1; i < size + 1; i++) {
        for (int j = i; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    // Thick to thin triangle pattern
    for (int i = size; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            std::cout << "+";
        }
        std::cout << "\n";
    }

    // Thin to thick hollow triangle pattern
    std::cout << "\n" << "." << "\n";

    for (int i = 0; i < size - 1; i++) {
        std::cout << ".";
        for (int j = i; j > 0; j--) {
            std::cout << " ";
        }
        std::cout << ".";
        std::cout << "\n";
    }

    return 0;
}   