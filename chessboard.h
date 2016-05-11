#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "tile.h"
#include "coordinate.h"
#include <vector>
#include <iostream>

using namespace std;

class ChessBoard
{
    public:
        ChessBoard();
       ~ChessBoard();
        void resetBoard();
        void print();//print out board
        void endTurn();//Resets selected piece to NULL
        PLAYER check();
        PLAYER checkMate();//Make sure to set player One/Two king coordinate to -1,-1 if either are defeated
        bool draw();
        void setCursorPosition(int x, int y);
        int getCursorX();
        int getCursorY();
        Piece* getSelectedPiece();
        bool validMove(); //Checks if piece selected can move at current cursor position
        bool validPieceSelection(PLAYER);//Checks to see if tile located at current cursor position
                                        //has a piece and if piece can be selected by current player
        Tile getTile(Coordinate);

    private:
        Tile board[8][8];//board[y][x]
        PLAYER playerBoard[8][8];//playerBoard[y][x]
        Piece* selectedPiece;
        Coordinate cursor;
        Piece* playerOneKing;//Keeps track of player one king's position
        Piece* playerTwoKing;//Keeps track of player two king's position
        vector<Piece*> playerOneTrash;
        vector<Piece*> playerTwoTrash;
        void updatePlayerBoard();
        void assemblePieces(); //Assembles pieces at the start of the game
        void disassemblePieces();//Releases memory for assembled pieces at the end of the game
};

#endif //ChessBoard_H
