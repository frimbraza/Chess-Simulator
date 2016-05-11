#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
    public:

       //Constructor:
        Bishop(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        Bishop(char inputSymbol, PLAYER inputPlayer, int x, int y);
       ~Bishop();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);

    private:

       //Helper function for updatePossibleMoves():
        void BishopMovement(PLAYER[8][8], int diagX, int diagY);
};

#endif
