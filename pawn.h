#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece
{
    public:

       //Constructors:
        Pawn(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        Pawn(char inputSymbol, PLAYER inputPlayer, int x, int y);

       //Destructor:
       ~Pawn();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);

    private:
        Coordinate startPosition;
};

#endif
