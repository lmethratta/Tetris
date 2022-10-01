#include "functions.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

bool assignedSeats[8][9] = {0};

std::vector<seatingAssignment> assignments;

int main() {

    bool running = true;

    while(running) {
        std::cout << "Please choose an option: \n"
        << "(1) Load Seating Assignment \n"
        << "(2) Save Seating Assignment \n"
        << "(3) Display Seating Chart \n"
        << "(4) Choose a Seat \n"
        << "(5) Update Seat Assignment \n"
        << "(6) Cancel Seating Assignment \n"
        << "(7) Print Boarding Pass \n"
        << "(8) Print Passengar Manifest \n"
        << "(9) Quit \n";
        bool valid = false;
        int option;
        while(!valid) {
            std::cin >> option;
            if (1 <= option && option <= 9) {
                valid = true;
            } else {
                std::cout << "Please input a number 1-9 \n";
            }
            if(std::cin.fail()) {
                std::cin.clear();
                std::string temp;
                std::cin >> temp;
            }
        }

        switch (option) {
            case 1: 
                load(assignedSeats, assignments);
                break;
            case 2: 
                save(assignments);
                break;
            case 3: 
                printSeatingChart(assignedSeats);
                break;
            case 4: 
                chooseSeat(assignedSeats, assignments);
                save(assignments);
                break;
            case 5: 
                updateSeatAssignment(assignedSeats, assignments);
                save(assignments);
                break;
            case 6: 
                cancelSeatingAssignment(assignedSeats, assignments);
                save(assignments);
                break;
            case 7: 
                getBoardingPass(assignments);
                break;
            case 8: 
                printPassengerManifest(assignments);
                break;
            case 9: running = false;
                break;
        }
    }


    return 0;
}