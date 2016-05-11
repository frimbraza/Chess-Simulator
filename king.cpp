#include "King.h"


King::King(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition)
    :Piece(inputSymbol, inputPlayer, inputPosition)
{
}

King::King(char inputSymbol, PLAYER inputPlayer, int x, int y)
    :Piece(inputSymbol, inputPlayer, x, y)
{
}


King::~King()
{
}

void King::KingMovement(PLAYER playerBoard[][8])
{
   //Check the eight positions around the king:
    for (int x = -1; x < 2; x++)
        for (int y = -1; y < 2; y++)
        {
            if (x == 0 && y == 0) continue;
            else
            {
                Coordinate futureCoords(position.getX() + x, position.getY() + y);
                if (outOfBounds(futureCoords) || playerBoard[futureCoords.getY()][futureCoords.getX()] == owner)
                    continue;
                else
                    possibleMoves.push_back(futureCoords);
            }
        }
}

void King::updatePossibleMoves(PLAYER playerBoard[][8])
{
   //Clear possible Moves:
    possibleMoves.clear();

   //Update possible moves:
    KingMovement(playerBoard);
}
