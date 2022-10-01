#include <utility>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "organism.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
using namespace std;


// Constructor
Organism::Organism (vector<Ant>* a, vector<Doodlebug>* d, int xPos, int yPos, int st, int bt) {
    x = xPos;
    y = yPos;
    ants = a;
    dbs = d;
    empty = false;
    starveThreshold = st;
    breedThreshold = bt;
    breedTime = 0;
    starveTime = 0;
    moved = false;
}
        
// Moves ants and keeps track of brred time
void Organism::tick() {
    if(!empty && !moved) {
        breedTime++;
        move();
    }
    moved = true;
}

// Sets move to false so they can move again next tick
void Organism::reset() {
    moved = false;
}


// Attempts to breed if there is room
void Organism::tryBreed() {
    vector< pair<int,int> > avail;
    vector< pair<int,int> > searching = getAvailableSquares();
    for(int i = 0; i < 8; i++) {
        if(emptySpot(searching[i].first, searching[i].second)) {
            avail.push_back(searching[i]);
        }
    }
    if(avail.size() > 0) {
        pair<int,int> spot = avail[rand()%avail.size()];
        breed(spot.first, spot.second);
    }
}

// Returns wether or not x,y pos is empty on the board
bool Organism::emptySpot(int xPos, int yPos) {
    bool emptySpot = true;
    for (int i = 0; i < (*ants).size(); i++) {
        if((*ants)[i].x == xPos && (*ants)[i].y == yPos) {
            emptySpot = false;
        }
    }
    for (int i = 0; i < (*dbs).size(); i++) {
        if((*dbs)[i].x == xPos && (*dbs)[i].y == yPos) {
            emptySpot = false;
        }
    }
    return emptySpot;
}

// Will move organism if randomly selected adjacent space is available
bool Organism::move() {
    if(!empty) {
        vector< pair<int,int> > avail = getAvailableSquares();
        pair<int,int> spot = avail[rand()%avail.size()];
        if(emptySpot(spot.first, spot.second)) {
            x = spot.first;
            y = spot.second;
            return true;
        } else {
            return false;
        }
    }
}
        
// Returns the 8 squares around the organism
vector< pair<int,int> > Organism::getAvailableSquares() {
    vector< pair<int,int> > available;
    available.push_back(make_pair((x - 1) == -1 ? 99 : (x - 1), (y + 1) == 100 ? 0 : (y + 1)));
    available.push_back(make_pair((x - 1) == -1 ? 99 : (x - 1), (y - 1) == -1 ? 99 : (y - 1)));
    available.push_back(make_pair((x - 1) == -1 ? 99 : (x - 1), y));
    available.push_back(make_pair((x + 1) == 100 ? 0 : (x + 1), (y + 1) == 100 ? 0 : (y + 1)));
    available.push_back(make_pair((x + 1) == 100 ? 0 : (x + 1), (y - 1) == -1 ? 99 : (y - 1)));
    available.push_back(make_pair((x + 1) == 100 ? 0 : (x + 1), y));
    available.push_back(make_pair(x,(y + 1) == 100 ? 0 : (y + 1)));
    available.push_back(make_pair(x,(y - 1) == -1 ? 99 : (y - 1)));
    return available;
}