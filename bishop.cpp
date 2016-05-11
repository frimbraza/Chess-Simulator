#include "Bishop.h"


Bishop::Bishop(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition)
    :Piece(inputSymbol, inputPlayer, inputPosition)
{
}

Bishop::Bishop(char inputSymbol, PLAYER inputPlayer, int x, int y)
    :Piece(inputSymbol, inputPlayer, x, y)
{
}


Bishop::~Bishop()
{
}

void Bishop::BishopMovement(PLAYER playerBoard[][8], int diagX, int diagY)
{
   //Keep track of current tile position and next tile owner:
     Coordinate currentPos = position;
     PLAYER nextTileOwner = NONE;

   //Traverse tiles in a diagonal direction:
    while (true)
    {
       //Get coordinate of next tile:
        Coordinate nextTileCoord(currentPos.getX() + diagX, currentPos.getY() + diagY);

       //Check if nextCoord is out of bounds:
        if(outOfBounds(nextTileCoord))
            return;

       //Get the owner of the piece on next tile:
        nextTileOwner = playerBoard[nextTileCoord.getY()][nextTileCoord.getX()];

       //If next tile owner is the piece's owner:
        if(nextTileOwner == owner)
            return;

       //If next tile owner is the opposing player:
        if(nextTileOwner != owner && nextTileOwner != NONE)
        {
            possibleMoves.push_back(nextTileCoord);
            return;
        }

       //If next tile belongs to no one(NONE):
        possibleMoves.push_back(nextTileCoord);

       //Update current position:
        currentPos = nextTileCoord;
    }
}

void Bishop::updatePossibleMoves(PLAYER currentBoard[][8])
{
   //Clear possible moves:
    possibleMoves.clear();

   //Set possible moves:
    BishopMovement(currentBoard, 1, 1);
    BishopMovement(currentBoard, 1, -1);
    BishopMovement(currentBoard, -1, -1);
    BishopMovement(currentBoard, -1, 1);
}

