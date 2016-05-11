#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece
{
    public:
       //Constructors:
        Rook(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        Rook(char inputSymbol, PLAYER inputPlayer, int x, int y);

       //Destructor:
        ~Rook();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);

    private:
       //Helper function for updatePossibleMoves():
        void RookMovement(PLAYER[8][8], int, int changeY);
};

#endif
