#include "Rook.h"


Rook::Rook(char inputSymbol, PLAYER inputPlayer, Coordinate inputPosition)
    :Piece(inputSymbol, inputPlayer, inputPosition)
{
}

Rook::Rook(char inputSymbol, PLAYER inputPlayer, int x, int y)
    : Piece(inputSymbol, inputPlayer, x, y)
{
}


Rook::~Rook()
{
}

void Rook::RookMovement(PLAYER playerBoard[][8], int changeX, int changeY)
{
    //Keep track of current tile position and next tile owner:
      Coordinate currentPos = position;
      PLAYER nextTileOwner = NONE;

    //Traverse tiles in a straight line:
     while (true)
     {
        //Get coordinate of next tile:
         Coordinate nextTileCoord(currentPos.getX() + changeX, currentPos.getY() + changeY);

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


void Rook::updatePossibleMoves(PLAYER currentBoard[8][8])
{
    //Clear possibleMoves vector:
     possibleMoves.clear();

    //Set all possible moves:
     RookMovement(currentBoard, 0, 1);
     RookMovement(currentBoard, 0, -1);
     RookMovement(currentBoard, 1, 0);
     RookMovement(currentBoard, -1, 0);
}
