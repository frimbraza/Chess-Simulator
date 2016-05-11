#ifndef PIECE_H
#define PIECE_H
#include "coordinate.h"
#include <vector>

enum PLAYER {ONE, TWO, NONE};
using namespace std;

class Piece
{
    public:
       //Constructors:
        Piece();
        Piece(char, PLAYER, Coordinate);
        Piece(char, PLAYER, int, int);

       //Destructor:
        virtual ~Piece();

       //Polymorphic function:
        virtual void updatePossibleMoves(PLAYER[8][8]) = 0; //Get possible places that piece can be moved to

       //Member functions:
        bool move(Coordinate moveCoord);//Checks to see if moveCoord is valid
        bool check(Piece *kingPtr, PLAYER playerBoard[8][8]);//Checks to see if piece checks the king of opposing player
        void print();
        void setPosition(Coordinate);
        void setSymbol(char);
        PLAYER getOwner();
        char getSymbol();
        Coordinate getPosition();
        bool outOfBounds(Coordinate);

    protected:
        vector<Coordinate> possibleMoves;//All possible moves from current position
        PLAYER owner;
        char symbol;
        Coordinate position;
};

#endif //Piece_H
