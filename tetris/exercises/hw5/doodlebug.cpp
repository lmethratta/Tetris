#include "doodlebug.hpp"
#include "ant.hpp"

char Doodlebug::print() {
    return 'X';
}

// Adds new Doodlebug to Doodlebug vector
void Doodlebug::breed(int xPos, int yPos) {
    (*dbs).push_back(Doodlebug(ants, dbs, xPos, yPos));
}

// Moves the Doodlebug
bool Doodlebug::move() {
    vector< pair<int,int> > avail = getAvailableSquares();
    bool ateAnt = false;
    // Checks if any adjacent square is a ant, if so it eats it
    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < (*ants).size(); j++) {
            if((*ants)[j].x == avail[i].first && (*ants)[j].y == avail[i].second) {
                (*ants)[j].kill();
                starveTime = 0;
                ateAnt = true;
                x = avail[i].first;
                y = avail[i].second;
                return true;
            }
        }
    }
    // Otherwise move normally
    if(!ateAnt) {
        starveTime++;
        return Organism::move();
    }
}

// Attempts to breed Doodlebug
void Doodlebug::operator++(int) {
    if(!empty) {
        if(breedTime >= breedThreshold) {
            tryBreed();
            breedTime = 0;
        }
    }
}

// Checks starveTime on decrement operator
void Doodlebug::operator--(int) {
    if(starveTime == starveThreshold) {
        kill();
    }
}


void Doodlebug::kill() {
    for(int i = 0; i < (*dbs).size(); i++) {
        if((*dbs)[i].x == x && (*dbs)[i].y == y) {
            // Removes DB from array
            (*dbs).erase((*dbs).begin() + i);
        }
    }
}