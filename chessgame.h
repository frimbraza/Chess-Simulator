#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <iostream>
#include "chessboard.h"

using namespace std;

enum GAME_STATUS{WIN, CONTINUE, DRAW};

class ChessGame
{
    public:
        ChessGame();
       ~ChessGame();
        void gameLoop(int command);//"KEY_UP", "KEY_DOWN", "KEY_LEFT", "KEY_RIGHT", "KEY_SPACE" as input.
                              //Sets board's cursor postion or selects
                              //piece/tile at current cursor position
        bool gameOver();
        void reset();

    private:
        ChessBoard board;
        unsigned int spaceCount;
        string notification;
        PLAYER currentPlayer;
        GAME_STATUS gameStatus;
};

#endif // CHESSGAME_H
