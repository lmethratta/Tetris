// int main(void) {
//     accept user input for team size

//     call createTeams()
//     store in map<int, vector<string> > teamAssignments;

//     // ^^ stored in map of team numbers to names of group members to keep it simple

//     prompt user for student lookup
//     search map for user, print user
// }

// void printToFile(map<int, vector<string> > assignments, int teamSize, map<string, vector<string> > studentInfo) {
//     for each assignment {
//         print line of team members + scores from studentInfo
//     }
// }
// map<string, vector<string> > readFile() {
//     for each line in file {
//         add to map where
//         1. key = name
//         2. value = string vector of rest of values in file
//     }

//     return map;
// }
// map<int, vector<string> > createTeams(int teamSize) {
//     // using map of string to vector of strings because this allows the program to keep track of names
//     // while still having all the details in the vector of strings (like scores)
//     map<string, vector<string> > studentInfo = readFile();

//     for each student in student info:
//         if they are high scoring in programming, add to list of "experts"

//     for each team {
//         add an expert in programming
//         if not experts:
//             look for novice (score 2-3)
//         else:
//             add anyone
//     }

//     for each team {
//         add members 2 through team size
//         for each:
//             check if adding would be against anyones wishes, if so dont add
//             check for students that want to be with group leader first or vice versa
//             otherwise any student
//     }

//     return teamAssignments to main;
// }