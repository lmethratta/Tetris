#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <vector>

struct seatingAssignment {
    std::string fName;
    std::string lName;
    int row;
    int column;
};

void printSeatingChart(bool assignedSeats[8][9]);
void chooseSeat(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments);
bool classFull(bool assignedSeats[8][9], char c);
std::string toSeat(int i, int j);
bool assignSeat(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments, char c, seatingAssignment& sa);
void printBoardingPass(seatingAssignment sa);
void cancelSeatingAssignment(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments);
void getBoardingPass(std::vector<seatingAssignment>& assignments);
void updateSeatAssignment(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments);
void printPassengerManifest(std::vector<seatingAssignment>& assignments);
void save(std::vector<seatingAssignment>& assignments);
void load(bool assignedSeats[8][9], std::vector<seatingAssignment>& assignments);
std::string getClass(int row);
#endif