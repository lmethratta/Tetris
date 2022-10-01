#include "organism.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include <string>
using namespace std;
#include <stdlib.h>

int main(void) {
    int move_counter = 0;
    int move_timeout = 300000000;  
    int time = 0;

    std::vector<Ant> ants;
    std::vector<Doodlebug> dbs;
    int x, y;
    bool spawning, avail;

    // Create 77 Ants
    for(int i = 0; i < 77; i++) {
        spawning = true;
        while(spawning) {
            x = rand()%100;
            y = rand()%100;
            avail = true;
            for(int i = 0; i < ants.size(); i++) {
                if(ants[i].x == x && ants[i].y == y) {
                    avail = false;
                }
            }
            if(avail) {
                ants.push_back((*new Ant(&ants, &dbs, x, y)));
                spawning = false;
            }
        }
    }

    // Create 11 Doodlebugs
    for(int i = 0; i < 11; i++) {
        spawning = true;
        while(spawning) {
            x = rand()%100;
            y = rand()%100;
            avail = true;
            for(int i = 0; i < ants.size(); i++) {
                if(ants[i].x == x && ants[i].y == y) {
                    avail = false;
                }
            }
            for(int i = 0; i < dbs.size(); i++) {
                if(dbs[i].x == x && dbs[i].y == y) {
                    avail = false;
                }
            }
            if(avail) {
                dbs.push_back(*(new Doodlebug(&ants, &dbs, x, y)));
                spawning = false;
            }
        }
    }
    
    cout << "Type 1 for automatic simulation and 2 for manual simulation (Pressing Enter)\n";
    int option;
    cin >> option;

    while(true) {
        if((move_counter++ >= move_timeout) || option == 2) {
            if(option == 2) {
                cin.ignore();
            }

            cout << "------------------------------------------------------------------------------------------------------" << endl;
            for(int i = 0; i < 100; i++) {
                cout << "|";
                for(int j = 0; j < 100; j++) {
                    bool empty = true;
                    for(int k = 0; k < ants.size(); k++) {
                        if(ants[k].x == i && ants[k].y == j) {
                            cout << ants[k].print();
                            empty = false;
                        }
                    }
                    for(int k = 0; k < dbs.size(); k++) {
                        if(dbs[k].x == i && dbs[k].y == j) {
                            cout << dbs[k].print();
                            empty = false;
                        }
                    }
                    if(empty) {
                        cout << " ";
                    }
                }
                cout << "|\n";
            }
            cout << "------------------------------------------------------------------------------------------------------  Time: " << time << endl;
            
            // Moves the Doodlebugs
            for(int i = 0; i < dbs.size(); i++) {
                dbs[i].tick();
            }  

            // Moves the Ants
            for(int i = 0; i < ants.size(); i++) {
                ants[i].tick();
            }  

            // Restet, starve, and breed the Doodlebugs
            for(int i = 0; i < dbs.size(); i++) {
                dbs[i].reset();
                dbs[i]--;
                dbs[i]++;
            }

            // Restet, starve, and breed the Ants
            for(int i = 0; i < ants.size(); i++) {
                ants[i].reset();
                --ants[i];
                ++ants[i];
            }

            move_counter = 0;
            time++;
        }
    }

    return 0;
}