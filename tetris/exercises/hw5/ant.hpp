#include "organism.hpp"

#ifndef ANT_H
#define ANT_H

class Ant : public Organism {
    public:
        Ant(vector<Ant>* a, vector<Doodlebug>* d, int xPos, int yPos) : Organism(a,d,xPos,yPos,10,5) {}
        char print();
        bool move();
        void breed (int xPos, int yPos);
        void kill();
        void operator++();
        void operator--();
};

#endif