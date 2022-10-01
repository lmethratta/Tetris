#include "teams.hpp"
#include <map>
#include <vector>
#include "string"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdlib.h> 
#include <algorithm>

using namespace std;
vector<string> names;


void printToFile(map<int, vector<string> > assignments, int teamSize, map<string, vector<string> > studentInfo) {
    std::ofstream saveFile ("teamAssignments.txt");
    for(int i = 0; i < assignments.size(); i++) {
        saveFile << (i + 1) << ",";
        int progScore = 0;
        int bugScore = 0;
        int leaderScore = 0;
        for(int j = 0; j < teamSize; j++) {
            saveFile << assignments[i][j] << ",";
            int prog, bug, leader;
            std::istringstream ( studentInfo[assignments[i][j]][1] ) >> prog;
            std::istringstream ( studentInfo[assignments[i][j]][2] ) >> bug;
            std::istringstream ( studentInfo[assignments[i][j]][3] ) >> leader;
            progScore += prog;
            bugScore += bug;
            leaderScore += leader;
        }
        saveFile << progScore << "," << bugScore << "," << leaderScore << "," 
            << (progScore + bugScore + leaderScore) << endl;
    };
    saveFile.close();
}

map<int, vector<string> > createTeams(int teamSize) {
    map<string, vector<string> > studentInfo = readFile();


    map<int, vector<string> > teamAssignments;

    // teamAssignments[i][j]][4] is DO NOT wanna work with
    // teamAssignments[i][j]][5] is DO wanna work with

    // Total number of teams to create
    int numTeams = studentInfo.size() / teamSize;
    
    vector<string> experts;
    for(int i = 0; i < names.size(); i++) {
        vector<string> info = studentInfo[names[i]];
        if (info[1] == "4" || info[1] == "5") {
            experts.push_back(names[i]);
        }
    }
    vector<string> assigned;
    for(int i = 0; i < numTeams; i++) {
        vector<string> tempTeam;

        bool found = false;
        if(i < experts.size()) {
            for(int k = 0; k < experts.size() && !found; k++) {
                if(find(assigned.begin(), assigned.end(), experts[k]) == assigned.end()) {
                    found = true;
                    assigned.push_back(experts[k]);
                    tempTeam.push_back(experts[k]);
                }
            }
        } else {
            for(int k = 0; k < names.size() && !found; k++) {
                if(find(assigned.begin(), assigned.end(), names[k]) == assigned.end()
                    && (studentInfo[names[k]][1] == "3" || studentInfo[names[k]][1] == "2")) {
                    found = true;
                    assigned.push_back(names[k]);
                    tempTeam.push_back(names[k]);
                }
            }
        }

        if(tempTeam.size() == 0) {
            for(int k = 0; k < names.size() && !found; k++) {
                if(find(assigned.begin(), assigned.end(), names[k]) == assigned.end()) {
                    found = true;
                    assigned.push_back(names[k]);
                    tempTeam.push_back(names[k]);
                }
            }
        }
        teamAssignments.insert(pair<int, vector<string> >(i, tempTeam));
    }

    for(int i = 0; i < numTeams; i++) {
        for(int j = 0; j < teamSize - 1; j++) {
            bool found = false;
            for(int k = 0; k < names.size() && !found; k++) {
                bool badGroup = false;
                for(int l = 0; l < j+1; l++) {
                    vector<string> donts;
                    stringstream s_stream(studentInfo[names[k]][4]);
                    string temp;
                    while(s_stream.good()) {
                        getline(s_stream, temp, ' ');
                        donts.push_back(temp);
                    }
                    if(find(donts.begin(), donts.end(), teamAssignments[i][l]) != donts.end()) {
                        badGroup = true;
                    }
                }
                if(find(assigned.begin(), assigned.end(), names[k]) == assigned.end() && !badGroup) {
                    found = true;
                    assigned.push_back(names[k]);
                    teamAssignments[i].push_back(names[k]);
                }
            }
            for(int k = 0; k < names.size() && !found; k++) {
                if(find(assigned.begin(), assigned.end(), names[k]) == assigned.end()) {
                    found = true;
                    assigned.push_back(names[k]);
                    teamAssignments[i].push_back(names[k]);
                }
            }
        }
    }
    printToFile(teamAssignments, teamSize, studentInfo);

    return teamAssignments;
}

map<string, vector<string> > readFile() {
    map<string, vector<string> > studentInfo;

    string line;
    fstream studentsFile ("students.txt");

    // First gitline to ignore top of students file with prompts.
    getline(studentsFile,line);

    while ( getline(studentsFile,line) ) {
        vector<string> info;
        string name;
        string temp;

        stringstream s_stream(line);

        getline(s_stream, name, ',');

        while(s_stream.good()) {
            getline(s_stream, temp, ',');
            info.push_back(temp);
        }
        names.push_back(name);
        studentInfo.insert(pair<string, vector<string> >(name, info));
    }
    studentsFile.close();

    return studentInfo;
}