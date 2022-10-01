#include "organism.hpp"

#ifndef DOODLEBUG_H
#define DOODLEBUG_H

class Doodlebug : public Organism {
    public:
        Doodlebug(vector<Ant>* a, vector<Doodlebug>* d, int xPos, int yPos) : Organism(a,d,xPos,yPos,5,10) {}
        char print();
        bool move();
        void breed(int xPos, int yPos);
        void kill();
        void operator++(int);
        void operator--(int);
};

#endif