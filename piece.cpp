#include "piece.h"
#include <array>
#include <iostream>
#include <windows.h>
using namespace std;

#define RED 12
#define WHITE 15
#define DEFAULT 7

Piece::Piece()
{
}

Piece::Piece(char inputSymbol, PLAYER inputPlayer, Coordinate inputCoord)
    :owner(inputPlayer), symbol(inputSymbol), position(inputCoord)
{
}

Piece::Piece(char inputSymbol, PLAYER inputPlayer, int x, int y)
    :owner(inputPlayer), symbol(inputSymbol)
{
    Coordinate inputCoord(x, y);
    setPosition(inputCoord);
}

Piece::~Piece()
{
}

bool Piece::move(Coordinate moveCoord)
{
    for (Coordinate possibleMove : possibleMoves)
       if (possibleMove == moveCoord)
            return true;

    return false;
}


bool Piece::check(Piece* kingPtr, PLAYER playerBoard[][8])
{
   //Update possible moves for piece:
    updatePossibleMoves(playerBoard);

   //Get king's coordinate:
    Coordinate kingCoordinate = kingPtr->getPosition();

   //Check if any possible move is the king's position:
    for (Coordinate space : possibleMoves)
       if (space == kingCoordinate)
            return true;

    return false;
}

void Piece::print()
{
    HANDLE  hConsole;

   //Determine color:
    int color = (owner == ONE ? WHITE : RED);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   //Set color:
    SetConsoleTextAttribute(hConsole, color);
    cout << symbol;

   //Set back to default:
    SetConsoleTextAttribute(hConsole, DEFAULT);
}

void Piece::setPosition(Coordinate inputCoord)
{
    position = inputCoord;
}

void Piece::setSymbol(char inputSymbol)
{
    symbol = inputSymbol;
}

PLAYER Piece::getOwner()
{
    return owner;
}

char Piece::getSymbol()
{
    return symbol;
}

Coordinate Piece::getPosition()
{
    return position;
}

bool Piece::outOfBounds(Coordinate Coord)
{
    if (Coord.getX() >= 0 && Coord.getX() <= 7 && Coord.getY() >= 0 && Coord.getY() <= 7)
        return false;
    return true;
}
