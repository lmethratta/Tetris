#include "functions.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>

void save(std::vector<seatingAssignment>& assignments) {
    std::ofstream saveFile ("saveData.txt");
    for(int i = 0; i < assignments.size(); i++) {
        saveFile << assignments[i].fName << '\n' << assignments[i].lName << '\n' 
        << assignments[i].row << '\n' << assignments[i].column << '\n';
    };
    saveFile.close();
    std::cout << "\nSave Successful\n\n";
}

void load(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 9; j++) {
            assignedSeats[i][j] = false;
        }
    }
    assignments.clear();

    std::string fName;
    std::fstream saveFile ("saveData.txt");
    while ( getline(saveFile,fName) ) {
        seatingAssignment sa;

        std::string lName;
        std::string row;
        std::string column;
        getline(saveFile, lName);
        getline(saveFile, row);
        getline(saveFile, column);

        int rowInt;
        int columnInt;
        std::istringstream ( row ) >> rowInt;
        std::istringstream ( column ) >> columnInt;

        sa.fName = fName;
        sa.lName = lName;
        sa.row = rowInt;
        sa.column = columnInt;

        assignments.push_back(sa);
        assignedSeats[sa.row][sa.column] = true;
    }
    saveFile.close();
    std::cout << "\nLoad Successful\n\n";
}

void printSeatingChart(bool assignedSeats[8][9]) {
    std::cout << "\n  AB DEFG IJK\n";
    for(int i = 0; i < 8; i++) {
        std::cout << i + 1 << " ";
        for(int j = 0; j < 9; j++) {
            if(assignedSeats[i][j]) {
                std::cout << "X";
            } else {
                std::cout << "O";
            }
            if (j == 1 || j == 5) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool compareBySeatAscending(const seatingAssignment &a, const seatingAssignment &b) {
    return a.row == b.row ? a.column < b.column : a.row < b.row;
}

bool compareBySeatDescending(const seatingAssignment &a, const seatingAssignment &b) {
    return a.row == b.row ? a.column > b.column : a.row > b.row;
}

bool compareByNameAscending(const seatingAssignment &a, const seatingAssignment &b) {
    return a.lName < b.lName;
}

bool compareByNameDescending(const seatingAssignment &a, const seatingAssignment &b) {
    return a.lName > b.lName;
}

void printPassengerManifest(std::vector<seatingAssignment>& assignments) {
    std::cout << "\nHow would you like to sort the manifest?\n"
    << "SA - By seat ascending\n"
    << "SD - By seat descending\n"
    << "NA - By name ascending\n"
    << "ND - By seat descending\n";
    std::string sortType = "SA";
    std::cin >> sortType;
    if (sortType == "SA") {
        std::sort(assignments.begin(), assignments.end(), compareBySeatAscending);
    } else if (sortType == "SD") {
        std::sort(assignments.begin(), assignments.end(), compareBySeatDescending);
    } else if (sortType == "NA") {
        std::sort(assignments.begin(), assignments.end(), compareByNameAscending);
    } else if (sortType == "ND") {
        std::sort(assignments.begin(), assignments.end(), compareByNameDescending);
    } else {
        std::cout << "\nInvalid input, sorting by seat (ascending).\n";
        std::sort(assignments.begin(), assignments.end(), compareBySeatAscending);
    }
    std::cout << "\n SEAT | NAME\n";
    std::cout << "========================\n";
    for(int i = 0; i < assignments.size(); i++) {
        std::cout << "  " << toSeat(assignments[i].column, assignments[i].row) << "  | " 
            << assignments[i].lName << ", " << assignments[i].fName << "\n";
    }
    std::cout << "\n";
}

void chooseSeat(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments) {
    seatingAssignment sa;
    std::cout << "\nWhat is your first name?\n";
    std::string firstName;
    std::cin >> firstName;
    std::cout << "What is your last name?\n";
    std::string lastName;
    std::cin >> lastName;
    std::transform(firstName.begin(), firstName.end(),firstName.begin(), ::toupper);
    std::transform(lastName.begin(), lastName.end(),lastName.begin(), ::toupper);
    sa.fName = firstName;
    sa.lName = lastName;

    bool valid = false;
    char classSelect;
    std::cout << "\nWhat class would you like to fly?\n"
        << "(F) First Class\n"
        << "(B) Business Class\n"
        << "(E) Economy Class\n";
    while(!valid) {
        std::cin >> classSelect;
        if (classSelect == 'F' || classSelect == 'B' || classSelect == 'E') {
            valid = true;
        } else {
            std::cout << "Please input F, B or E \n";
        }
        if(std::cin.fail()) {
            std::cin.clear();
            std::string temp;
            std::cin >> temp;
        }
    }

    if(!assignSeat(assignedSeats, assignments, classSelect, sa)) {
        return;
    }


     std::cout << "Seat Assigned:\n";
     printBoardingPass(sa);

    assignedSeats[sa.row][sa.column] = true;
    assignments.push_back(sa);
}

void printBoardingPass(seatingAssignment sa) {
    std::cout << sa.fName << " " << sa.lName << ", SEAT: " << toSeat(sa.column, sa.row) << ", LEVEL: " << getClass(sa.row) << "\n\n";
}

void getBoardingPass(std::vector<seatingAssignment>& assignments) {
    std::cout << "\nWhich seat would you like the boarding pass for? (ex: B4)\n";
    for(int i = 0; i < 3; i++) {
        if(i != 0) {
            std::cout << "\nSeat Unassigned - No Boarding pass available. Try Again!\n";
        }
        std::string seatNum;
        std::cin >> seatNum;
        for(int i = 0; i < assignments.size(); i++) {
            seatingAssignment sa = assignments[i];
            if(seatNum == toSeat(sa.column, sa.row)) {
                std::cout << "\n";
                printBoardingPass(sa);
                return;
            }
        }
    }
    std::cout << "\nBoarding pass is not available at this time. Try Again later!\n\n";
}

void updateSeatAssignment(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments) {
    std::cout << "\nWhich seating assignment would you like to update? (ex: B4)\n";
    std::string seatNum;
    std::cin >> seatNum;
    for(int a = 0; a < assignments.size(); a++) {
        seatingAssignment sa = assignments[a];
        if(seatNum == toSeat(sa.column, sa.row)) {
            std::cout << "Seat Found:\n";
            printBoardingPass(assignments[a]);
            bool updating = true;
            std::string seatClass = getClass(sa.row);
            int classInt;
            if (seatClass == "FIRST CLASS") {
                classInt = 0;
            } else if (seatClass == "BUSINESS CLASS") {
                classInt = 1;
            } else {
                classInt = 2;
            }
            switch (classInt) {
                case 0: break;
                case 1: {
                    if(!classFull(assignedSeats, 'F')) {
                        std::cout << "First class has an opening, upgrade seat? (Y/N)\n";
                        char ug;
                        std::cin >> ug;
                        std::cout << "\n";
                        if (ug == 'Y') {
                            assignedSeats[sa.row][sa.column] = false;
                            std::vector<int> availableSeats;
                            for(int j = 0; j < 9; j++) {
                                if(!assignedSeats[0][j]){
                                    availableSeats.push_back(j);
                                }
                            }
                            assignments[a].row = 0;
                            assignments[a].column = availableSeats.at(rand() % availableSeats.size());
                            assignedSeats[assignments[a].row][assignments[a].column] = true;
                        } 
                    }
                    break;
                }
                case 2: {
                    if(!classFull(assignedSeats, 'F')) {
                        std::cout << "First class has an opening, upgrade seat? (Y/N)\n";
                        char ug;
                        std::cin >> ug;
                        std::cout << "\n";
                        if (ug == 'Y') {
                            assignedSeats[sa.row][sa.column] = false;
                            std::vector<int> availableSeats;
                            for(int j = 0; j < 9; j++) {
                                if(!assignedSeats[0][j]){
                                    availableSeats.push_back(j);
                                }
                            }
                            assignments[a].row = 0;
                            assignments[a].column = availableSeats.at(rand() % availableSeats.size());
                            assignedSeats[assignments[a].row][assignments[a].column] = true;
                        } else {
                            if(!classFull(assignedSeats, 'F')) {
                                std::cout << "Business class has an opening, upgrade seat? (Y/N)\n";
                                char ug;
                                std::cin >> ug;
                                std::cout << "\n";
                                if (ug == 'Y') {
                                    assignedSeats[sa.row][sa.column] = false;
                                    std::vector<int> availableSeats;
                                    for(int i = 1; i < 3; i++) {
                                        for(int j = 0; j < 9; j++) {
                                            if(!assignedSeats[i][j]){
                                                availableSeats.push_back(i * 8 + j);
                                            }
                                        }
                                    }
                                    int availIndex = rand() % availableSeats.size();
                                    assignments[a].row = availableSeats.at(availIndex) / 8;
                                    assignments[a].column = availableSeats.at(availIndex) % 8;
                                    assignedSeats[assignments[a].row][assignments[a].column] = true;
                                }
                            }
                        }
                    }
                    break;
                }
                default: break;
            }
            std::cout << "\nWould you like to update your name? (Y/N)\n";
            std::string nameUpdate;
            std::cin >> nameUpdate;
            if (nameUpdate == "Y") {
                std::cout << "What would you like to update your first name to?\n";
                std::string firstName;
                std::cin >> firstName;
                std::cout << "What would you like to update your last name to?\n";
                std::string lastName;
                std::cin >> lastName;
                std::transform(firstName.begin(), firstName.end(),firstName.begin(), ::toupper);
                std::transform(lastName.begin(), lastName.end(),lastName.begin(), ::toupper);
                assignments[a].fName = firstName;
                assignments[a].lName = lastName;
            }
            std::cout << "\n\nUpdated boarding pass:\n";
            printBoardingPass(assignments[a]);
            return;
        }
    }
    std::cout << "\nSeat not found.\n\n";
}

std::string getClass(int row) {
    if(row == 0) {
        return "FIRST CLASS";
    } else if (row <= 2) {
        return "BUSINESS CLASS";
    } else {
        return "ECONOMY CLASS";
    }
}

bool assignSeat(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments, char c, seatingAssignment& sa) {
    switch(c) {
        case 'F': {
            if(classFull(assignedSeats, 'F')) {
                std::cout << "First class full, are you okay flying business? (Y/N)\n";
                char dg;
                std::cin >> dg;
                if (dg == 'Y') {
                    return assignSeat(assignedSeats, assignments, 'B', sa);
                } else {
                    std::cout << "The next flight leaves in 3 hours.\n";
                    return false;
                }
            } else {
                std::vector<int> availableSeats;
                for(int j = 0; j < 9; j++) {
                    if(!assignedSeats[0][j]){
                        availableSeats.push_back(j);
                    }
                }
                sa.row = 0;
                sa.column = availableSeats.at(rand() % availableSeats.size());
                return true;
            }
            break;
        }
        case 'B': {
            if(classFull(assignedSeats, 'B')) {
                std::cout << "Business class full, are you okay flying economy? (Y/N)\n";
                char dg;
                std::cin >> dg;
                if (dg == 'Y') {
                    return assignSeat(assignedSeats, assignments, 'E', sa);
                } else {
                    std::cout << "The next flight leaves in 3 hours.\n";
                    return false;
                }
            } else {
                if(!classFull(assignedSeats, 'F')) {
                    std::cout << "First class has an opening, upgrade seat? (Y/N)\n";
                    char ug;
                    std::cin >> ug;
                    std::cout << "\n";
                    if (ug == 'Y') {
                        return assignSeat(assignedSeats, assignments, 'F', sa);
                    } 
                }
                std::vector<int> availableSeats;
                for(int i = 1; i < 3; i++) {
                    for(int j = 0; j < 9; j++) {
                        if(!assignedSeats[i][j]){
                            availableSeats.push_back(i * 9 + j);
                        }
                    }
                }
                int availIndex = rand() % availableSeats.size();
                sa.row = availableSeats.at(availIndex) / 9;
                sa.column = availableSeats.at(availIndex) % 9;
                return true;
            }
            break;
        }
        case 'E': {
            if(classFull(assignedSeats, 'E')) {
                std::cout << "Economy class is full, sorry.\n";
                std::cout << "The next flight leaves in 3 hours.\n";
                return false;
            } else {
                if(!classFull(assignedSeats, 'B')) {
                    std::cout << "Business class has an opening, upgrade seat? (Y/N)\n";
                    char ug;
                    std::cin >> ug;
                    std::cout << "\n";
                    if (ug == 'Y') {
                        return assignSeat(assignedSeats, assignments, 'B', sa);
                    } 
                } else if(!classFull(assignedSeats, 'F')) {
                    std::cout << "First class has an opening, upgrade seat? (Y/N)\n";
                    char ug;
                    std::cin >> ug;
                    std::cout << "\n";
                    if (ug == 'Y') {
                        return assignSeat(assignedSeats, assignments, 'F', sa);
                    } 
                }
                std::vector<int> availableSeats;
                for(int i = 3; i < 8; i++) {
                    for(int j = 0; j < 9; j++) {
                        if(!assignedSeats[i][j]){ 
                            availableSeats.push_back(i * 9 + j);
                        }
                    }
                }
                int availIndex = rand() % availableSeats.size();
                sa.row = availableSeats.at(availIndex) / 9;
                sa.column = availableSeats.at(availIndex) % 9;
                return true;
            }
            break;
        }
        default: return false;
    }
}

void cancelSeatingAssignment(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments) {
    std::cout << "What is your first name?\n";
    std::string firstName;
    std::cin >> firstName;
    std::cout << "What is your last name?\n";
    std::string lastName;
    std::cin >> lastName;
    std::cout << "What is your seat number? (ex: B4)\n";
    std::string seatNum;
    std::cin >> seatNum;
    std::transform(firstName.begin(), firstName.end(),firstName.begin(), ::toupper);
    std::transform(lastName.begin(), lastName.end(),lastName.begin(), ::toupper);
    for(int i = 0; i < assignments.size(); i++) {
        seatingAssignment sa = assignments[i];
        if(sa.fName == firstName && sa.lName == lastName && seatNum == toSeat(sa.column, sa.row)) {
            assignedSeats[sa.row][sa.column] = false;
            assignments.erase(assignments.begin() + i);
            std::cout << "\nSeating assignment successfully cancelled.\n\n";
            return;
        }
    }

    std::cout << "\nSeat not found, please try again.\n\n";
}

bool classFull(bool assignedSeats[8][9], char c) {
    int firstRow, lastRow;
    if(c == 'F') {
        firstRow = 0;
        lastRow = 0;
    } else if(c == 'B') {
        firstRow = 1;
        lastRow = 2;
    } else if(c == 'E') {
        firstRow = 3;
        lastRow = 7;
    } else {
        return false;
    }
    for(int i = firstRow; i < lastRow + 1; i++) {
        for(int j = 0; j < 9; j++) {
            if (!assignedSeats[i][j]) {
                return false;
            }
        }
    }
    return true;
}

std::string toSeat(int i, int j) {
    char seatLetter;
    switch (i) {
        case 0: seatLetter = 'A';
            break;
        case 1: seatLetter = 'B';
            break;
        case 2: seatLetter = 'D';
            break;
        case 3: seatLetter = 'E';
            break;
        case 4: seatLetter = 'F';
            break;
        case 5: seatLetter = 'G';
            break;
        case 6: seatLetter = 'I';
            break;
        case 7: seatLetter = 'J';
            break;
        case 8: seatLetter = 'K';
            break;
        default: seatLetter = '?';
            break;
    }
    std::ostringstream stringRow;
    stringRow << (j + 1);
    std::string seat = seatLetter + stringRow.str();
    return seat;
}