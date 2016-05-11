#include "Pawn.h"


Pawn::Pawn(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition)
    :Piece(inputSymbol, inputPlayer, inputPosition)
{
    //Set start position:
     startPosition.set(inputPosition.getX(), inputPosition.getY());
}

Pawn::Pawn(char inputSymbol, PLAYER inputPlayer, int x, int y)
    :Piece(inputSymbol, inputPlayer, x, y)
{
    //Set start position:
     startPosition.set(x, y);
}


Pawn::~Pawn()
{
}

void Pawn::updatePossibleMoves(PLAYER currentBoard[][8])
{
   //Clear possibleMoves vector:
    possibleMoves.clear();

   //Possible move positions://PL ONE LEFT SIDE,
    Coordinate ahead;
    Coordinate upperDiag;
    Coordinate lowerDiag;
    Coordinate doubleMove;

  //Set the coordinates for move positions:
   if(owner == ONE)//Left side of the board
   {
       ahead.set(position.getX() + 1, position.getY());
       upperDiag.set(position.getX() + 1, position.getY() - 1);
       lowerDiag.set(position.getX() + 1, position.getY() + 1);
       doubleMove.set(position.getX() + 2, position.getY());
   }
   else//right side of the board
   {
       ahead.set(position.getX() - 1, position.getY());
       upperDiag.set(position.getX() - 1, position.getY() - 1);
       lowerDiag.set(position.getX() - 1, position.getY() + 1);
       doubleMove.set(position.getX() - 2, position.getY());
   }

   //Check if ahead position is valid:
    if (!outOfBounds(ahead) && currentBoard[ahead.getY()][ahead.getX()] == NONE)
        possibleMoves.push_back(ahead);

   //Check if upper diagonal move is valid:
    if (!outOfBounds(upperDiag) && currentBoard[upperDiag.getY()][upperDiag.getX()] != owner && currentBoard[upperDiag.getY()][upperDiag.getX()] != NONE)
        possibleMoves.push_back(upperDiag);

   //Check if lower diagonal move is valid:
    if (!outOfBounds(lowerDiag) && currentBoard[lowerDiag.getY()][lowerDiag.getX()] != owner && currentBoard[lowerDiag.getY()][lowerDiag.getX()] != NONE)
        possibleMoves.push_back(lowerDiag);

   //Check if double move is valid:
    if (position == startPosition && currentBoard[doubleMove.getY()][doubleMove.getX()] == NONE)
        possibleMoves.push_back(doubleMove);
}
