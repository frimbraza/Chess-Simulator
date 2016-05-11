#include "Knight.h"


Knight::Knight(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition)
    :Piece(inputSymbol, inputPlayer, inputPosition)
{
}

Knight::Knight(char inputSymbol, PLAYER inputPlayer, int x, int y)
    :Piece(inputSymbol, inputPlayer, x, y)
{
}


Knight::~Knight()
{
}

void Knight::updatePossibleMoves(PLAYER currentBoard[][8])
{
   //Temporary vector to hold positions:
    vector<Coordinate> knightMovement;

   //Clear possibleMoves vector:
    possibleMoves.clear();

   //Get all possible L-movements for knight:
    for (int x = -2; x < 3; x++)
    {
        if (x == 0)
            continue;
        else if (x != 0)
        {
            int y = abs(3) - abs(x);
            knightMovement.push_back(Coordinate(position.getX() + x, position.getY() + y));
            knightMovement.push_back(Coordinate(position.getX() + x, position.getY() - y));
        }
    }

   //Get all valid position to move to:
    for (Coordinate movePosition : knightMovement)
    {
       //If movePosition is owned by piece's owner or if movePostion is out of bounds:
        if (outOfBounds(movePosition) || currentBoard[movePosition.getY()][movePosition.getX()] == owner)
            continue;
        else
            possibleMoves.push_back(movePosition);
    }
}
