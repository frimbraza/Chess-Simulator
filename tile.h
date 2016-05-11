#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "piece.h"

using namespace std;

class Tile
{
    public:
       //Constructors:
        Tile();
        Tile(Piece*);

       //Destructor:
       ~Tile();

       //Member fucntions:
        void setOccupant(Piece*);
        Piece* getOccupant();
        bool empty();
        void print();

    private:
        Piece* occupant;
};

#endif
