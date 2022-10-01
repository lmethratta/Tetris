#include <utility>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef ORGANISM_H
#define ORGANISM_H

class Ant;
class Doodlebug;

class Organism {
    public:
        int x;
        int y;
        int breedTime;
        int breedThreshold;
        int starveThreshold;
        int starveTime;
        bool moved;
        vector<Ant>* ants;
        vector<Doodlebug>* dbs;
        bool empty;
        Organism (vector<Ant>* a, vector<Doodlebug>* d, int xPos, int yPos, int st, int bt);
        void tick();
        void tryBreed();
        virtual bool move();
        bool emptySpot(int xPos, int yPos);
        vector< pair<int,int> > getAvailableSquares();
        virtual char print() = 0;
        virtual void breed(int xPos, int yPos) = 0;
        virtual void kill() = 0;
        void reset();
};

#endif