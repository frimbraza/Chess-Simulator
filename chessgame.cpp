#include "chessgame.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

ChessGame::ChessGame()
{
    spaceCount = 0;
    notification = "\n-> Player 1(WHITE), select a piece to move.";
    currentPlayer = ONE;
    gameStatus = CONTINUE;
}

ChessGame::~ChessGame()
{

}

void ChessGame::gameLoop(int command)
{
   //Get current x, y position for cursor:
    int x = board.getCursorX();
    int y = board.getCursorY();

  //Get current player:
    string player = (currentPlayer == ONE ? "Player 1(WHITE)" : "Player 2(RED)");
    string nextPlayer = (currentPlayer == ONE ? "Player 2(RED)" : "Player 1(WHITE)");

   //Move cursor or select/move a piece:
    switch(command)
    {
        case KEY_UP: board.setCursorPosition(x, y - 1);break;
        case KEY_DOWN: board.setCursorPosition(x, y + 1); break;
        case KEY_LEFT: board.setCursorPosition(x - 1, y);break;
        case KEY_RIGHT: board.setCursorPosition(x + 1, y);break;
        case KEY_SPACE:

           //If player is selecting a piece to move:
            if(spaceCount == 0)
            {
                if(board.validPieceSelection(currentPlayer))
                {
                    spaceCount++;
                    char piece = board.getSelectedPiece()->getSymbol();
                    notification = "\n->" + player + ", select a position to move " + piece + ".";
                }
                else
                    notification = "\n->" + player + ", invalid piece selected!\n->Please try again!";
            }

           //If player is selecting a position to move a selected piece:
            else if(spaceCount == 1)
             {
                if(board.validMove())
                {
                    spaceCount = 0;
                    notification = "\n->" + nextPlayer + ", select a piece to move.";

                   //Switch players:
                    currentPlayer = (currentPlayer == ONE ? TWO : ONE);
                    board.endTurn();
                }
                else
                {
                    spaceCount = 0;
                    notification = "\n->" + player + ", invalid move selection!\n->" + player + ", please select a piece to move.";
                }
            }

           //Add notification if player is checked:
            if(board.check() != NONE)
            {
                string playerChecked = (board.check() == ONE ? "Player 1" : "Player 2");
                notification = notification + "\n->" + playerChecked + ", Checked!";
            }

            break;
        default: break;
    }

   //Print Board:
    system("cls");
    board.print();

   //Print notification:
    cout << "Notification(s): " << notification << endl;
}

bool ChessGame::gameOver()
{
    if(board.checkMate() != NONE)
    {
        string winner = (board.checkMate() == ONE ? "Player 2" : "Player 1");
        cout << endl;
        cout << winner << " WINS!!!" << endl;
        gameStatus = WIN;
        return true;
    }
    else if(board.draw())
    {
        cout << endl;
        cout << "DRAW!" << endl;
        gameStatus = DRAW;
        return true;
    }

    return false;
}

void ChessGame::reset()
{
    spaceCount = 0;
    notification = "\n-> Player 1, select a piece to move.";
    currentPlayer = ONE;
    gameStatus = CONTINUE;
    board.resetBoard();
}
