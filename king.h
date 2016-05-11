#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{
    public:
       //Constructors:
        King(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition);
        King(char inputSymbol, PLAYER inputPlayer, int x, int y);

       //Destructor:
        ~King();

       //Virtual function for all pieces:
        void updatePossibleMoves(PLAYER[8][8]);

   private:
       //Helper function for updatePossibleMoves():
        void KingMovement(PLAYER[8][8]);
};

#endif
