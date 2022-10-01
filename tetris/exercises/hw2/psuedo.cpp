// int main() {
//     while(running) {
//         display menu options 1-9;
//         get user input;
//         verify input;

//         switch (input) {
//             cases 1-9, calling corresponding functions;
//         }
//     }
// }

// void save(vector of seatingAssignments) {
//     print each SA to a line in .txt file;
// }

// void load(2d array of occupied seats, vector of seatingAssignments) {
//     read data from .txt file and fill into two parameters (passed by reference);
// }

// void printSeatingChart(2d array of occupied seats) {
//     print (ABDEFGIJK)
//     for loop over 2d array printing it;
// }

// void printPassengerManifest(vector of seatingAssignments) {
//     ask for input on how to sort;
//     sort vector based on input;
//     forloop over vector printing each element;
// }

// void chooseSeat() {
//     Ask for users name;
//     Ask for class they want to fly (F, B, E);
//     call assignSeat function with inputed class;
// }

// void printBoardingPass(seatingAssignment) {
//     print all fields of seatingAssignment;
// }

// void getBoardingPass(vector of assignments) {
//     loop 3 times:
//         ask for seat (i.e. b4);
//         if seat assigned, printBoardingPass();
//         else ask again;

//     if fail return error message;
// }

// updateSeatingAssignment(2d array of assigned seats, vector of assignments) {
//     Ask for seat input;
//     If not assigned, return error;
//     if available upgrade:
//         propose upgrade;
//         if accepted:
//             clear seat from vector and 2d array and reassign in higher class;
//     Ask for name change:
//         if yes, ask for new name;
//         update name;
//     print new assigenment;
// }

// getClass(int row) {
//     if row == 0:
//         return fc
//     if row <= 2
//         return bc
//     else:
//         return ec
// }

// assignSeat(2d array of assigned seats, vector of assignments, char class) {
//     check if requested class is full:
//         if yes, ask if lower class is okay.
//     Offer seat upgrade if available;
//     loop over seats in class:
//         if available, add to available vector
//     assign random seat from available vector
// }

// cancelSeatingAssignment(2d array of assigned seats, vector of assignments) {
//     ask for name;
//     ask for seatNumber;
//     if valid seat/name:
//         remove assignment from array and vector;
//     else return error message;
// }

// classFull(2d array of assigned seats, char class) {
//     loop over 2d array with indices based on class:
//         if any empty, return false
    
//     return true;
// }

// toSeat(int i, int j) {
//     turns int i into letter in switch statement;
//     returns letter + (j+1);
// }
