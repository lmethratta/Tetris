#include "ant.hpp"

char Ant::print () {
    return 'O';
}

// Calls base class move function
bool Ant::move () {
    bool moved = Organism::move();
    if(!moved) {
        // Starves if move was unsuccesful
        starveTime++;
    }
}

// Attempts to breed ant
void Ant::operator++() {
    if(!empty) {
        if(breedTime >= breedThreshold) {
            tryBreed();
            breedTime = 0;
        }
    }
}

void Ant::operator--() {
    if(starveTime == starveThreshold) {
        kill();
    }
}

// Breeds ant, breeds twins if its been 10+ timesteps
void Ant::breed (int xPos, int yPos) {
    (*ants).push_back(Ant(ants, dbs, xPos, yPos));
    if(breedTime > breedThreshold * 2) {
        (*ants).push_back(Ant(ants, dbs, xPos, yPos));
    }
}

void Ant::kill() {
    for(int i = 0; i < (*ants).size(); i++) {
        if((*ants)[i].x == x && (*ants)[i].y == y) {
            (*ants).erase((*ants).begin() + i);
        }
    }
}