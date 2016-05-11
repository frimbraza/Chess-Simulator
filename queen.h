#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen: public Piece
{
    public:
       //Constructors:
        Queen(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        Queen(char inputSymbol, PLAYER inputPlayer, int x, int y);

       //Destructor:
        ~Queen();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);

       private:
        //Helper functions for updatePossibleMoves():
        void RookMovement(PLAYER[8][8], int changeX, int changeY);
        void BishopMovement(PLAYER[8][8], int diagX, int diagY);
};

#endif

