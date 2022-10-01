#include "teams.hpp"
#include <iostream>
#include "string"
#include <vector>
#include <map>
using namespace std;

int main(void) {

    cout << "What team size would you like? (2-6)\n";

    bool valid = false;
    int teamSize;
    while(!valid) {
        cin >> teamSize;
        if (2 <= teamSize && teamSize <= 6) {
            valid = true;
        } else {
            cout << "Please input a number 2-6 \n";
        }
        if(cin.fail()) {
            cin.clear();
            string temp;
            cin >> temp;
        }
    }

    map<int, vector<string> > teamAssignments;
    teamAssignments = createTeams(teamSize);

    bool done = false;
    while(!done) {
        cout << "Please type the username of a student to print their team information, or \"q\" to quit:\n";
        string input;
        cin >> input;
        if(input == "q") {
            done = true;
        } else {
            bool found = false;
            for(int i = 0; i < teamAssignments.size(); i++) {
                for(int j = 0; j < teamAssignments[i].size(); j++) {
                    if(teamAssignments[i][j] == input) {
                        found = true;
                        cout << "\nUser found on Team " << (i + 1) << endl;
                        cout << "Team includes: ";
                        for(int k = 0; k < teamAssignments[i].size(); k++) {
                            cout << teamAssignments[i][k] << " ";
                        }
                        cout << "\n\n";
                    }
                }
            }
            if (!found) {
                cout << "User not found." << endl;
            }
        }
    }

    return 0;
}