#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <cmath>

using namespace std;

class Knight : public Piece
{
    public:
       //Constructors:
        Knight(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        Knight(char inputSymbol, PLAYER inputPlayer, int x, int y);

       //Destructor:
        ~Knight();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);
};

#endif

