#include "ChessBoard.h"
#include "enum.h"
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "coordinate.h"

#define RED 12
#define WHITE 15
#define DEFAULT 7

ChessBoard::ChessBoard()
{
    //Assemble Pieces of board:
    assemblePieces();

    //Set Initial Cursor Position:
    cursor.set(0, 0);

    //Set king pointers:
    playerOneKing = board[4][0].getOccupant();
    playerTwoKing = board[3][7].getOccupant();
}

void ChessBoard::assemblePieces()
{
   //Set players for playerBoard:
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
            playerBoard[y][x] = NONE;

    for(int x = 0; x < 2; x++)
        for(int y = 0; y < 8; y++)
            playerBoard[y][x] = ONE;

    for(int x = 6; x < 8; x++)
        for(int y = 0; y < 8; y++)
            playerBoard[y][x] = TWO;

   //Set Pieces for player 1:
    board[0][0].setOccupant(new Rook('R', ONE, 0, 0));
    board[1][0].setOccupant(new Knight('k', ONE, 0, 1));
    board[2][0].setOccupant(new Bishop('B', ONE, 0, 2));
    board[3][0].setOccupant(new Queen('Q', ONE, 0, 3));
    board[4][0].setOccupant(new King('K', ONE, 0, 4));
    board[5][0].setOccupant(new Bishop('B', ONE, 0, 5));
    board[6][0].setOccupant(new Knight('k', ONE, 0, 6));
    board[7][0].setOccupant(new Rook('R',  ONE, 0, 7));

   //Set pawns for player 1:
    for (int i = 0; i < 8; i++)
        board[i][1].setOccupant(new Pawn('P', ONE, 1, i));

   //Set Pieces for player 2:
    board[0][7].setOccupant(new Rook('R', TWO, 7, 0));
    board[1][7].setOccupant(new Knight('k', TWO, 7, 1));
    board[2][7].setOccupant(new Bishop('B', TWO, 7, 2));
    board[3][7].setOccupant(new King('K', TWO, 7, 3));
    board[4][7].setOccupant(new Queen('Q', TWO, 7, 4));
    board[5][7].setOccupant(new Bishop('B', TWO, 7, 5));
    board[6][7].setOccupant(new Knight('k', TWO, 7, 6));
    board[7][7].setOccupant(new Rook('R', TWO, 7, 7));

   //Set pawns for player 2:
    for (int i = 0; i < 8; i++)
        board[i][6].setOccupant(new Pawn('P', TWO, 6, i));
}

ChessBoard::~ChessBoard()
{
    disassemblePieces();
}

void ChessBoard::print()
{
    cout << "          Chess Board:          " << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < 8; i++)//y: 0 - 7
    {
        for (int j = 0; j < 8; j++)//x: 0 - 7
        {
            if (j == cursor.getX() && i == cursor.getY())
            {cout << "["; board[i][j].print(); cout << "]"; cout << "|";}
            else
            {cout << " "; board[i][j].print(); cout << " "; cout << "|";}
        }

        cout << endl;
        cout << "--------------------------------" << endl;
    }

   //Print out player 1 graveyard:
    cout << "P-1 Graveyard: ";

    for(Piece* p : playerOneTrash)
        cout << p->getSymbol() << " ";
    cout << endl;

   //Print out player 2 graveyard:
    cout << "P-2 Graveyard: ";
    for(Piece* p : playerTwoTrash)
        cout << p->getSymbol() << " ";
    cout << endl;
    cout << endl;
}

void ChessBoard::setCursorPosition(int x, int y)
{
    //If coordinates valid, then set cursor position:
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
        cursor.set(x, y);
}

void ChessBoard::resetBoard()
{
    disassemblePieces();
    assemblePieces();
}

void ChessBoard::endTurn()
{
    selectedPiece = NULL;
}

PLAYER ChessBoard::check()
{
  //Return which player's king is checked:

    //Check if any player one pieces check player two's king:
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j].getOccupant() != NULL && board[i][j].getOccupant()->getOwner() == ONE)
                if (board[i][j].getOccupant()->check(playerTwoKing,playerBoard))
                    return TWO;

    //Check if any player two pieces check player one's king:
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j].getOccupant() != NULL && board[i][j].getOccupant()->getOwner() == TWO)
                if (board[i][j].getOccupant()->check(playerOneKing, playerBoard))
                    return ONE;

    return NONE;
}

void ChessBoard::updatePlayerBoard()
{
    for(int y = 0; y < 8; y++)
        for(int x = 0; x < 8; x++)
            if(board[y][x].empty())
                playerBoard[y][x] = NONE;
            else
                playerBoard[y][x] = board[y][x].getOccupant()->getOwner();
}

PLAYER ChessBoard::checkMate()
{
   //Return who has their king in the graveyard:
    if(playerOneKing->getPosition().getX() == -1)
        return ONE;
    else if(playerTwoKing->getPosition().getX() == -1)
        return TWO;
    else
        return NONE;
}

int ChessBoard::getCursorX()
{
    return cursor.getX();
}

int ChessBoard::getCursorY()
{
    return cursor.getY();
}

bool ChessBoard::validMove()
{
   //Update possibleMoves vector of piece:
    selectedPiece->updatePossibleMoves(playerBoard);

   //Check if specific position to be moved is within possibleMoves vector:
   //If yes, then make the move and return true.
    if(selectedPiece->move(cursor))
    {
        //Set the selected piece's previous tile occupant to NULL:
          int x = selectedPiece->getPosition().getX();
          int y = selectedPiece->getPosition().getY();
          board[y][x].setOccupant(NULL);

        //If tile moved to has has an enemy piece:
        if(!board[cursor.getY()][cursor.getX()].empty())
        {
            Piece* enemyPiece = board[cursor.getY()][cursor.getX()].getOccupant();

           //Set enemy position off the board:
            enemyPiece->setPosition(Coordinate(-1,-1));

           //Put enemy piece into respective trash pile:
            if(enemyPiece->getOwner() == ONE)
                playerOneTrash.push_back(enemyPiece);
            else
                playerTwoTrash.push_back(enemyPiece);

           //Place selected piece into tile:
            board[cursor.getY()][cursor.getX()].setOccupant(selectedPiece);
        }
        else
            board[cursor.getY()][cursor.getX()].setOccupant(selectedPiece);

        //Update selected piece's position:
         selectedPiece->setPosition(cursor);

        //Update playerBoard:
         updatePlayerBoard();

        return true;
    }

    return false;
}

bool ChessBoard::validPieceSelection(PLAYER p)
{
    Piece* tilePiece = board[cursor.getY()][cursor.getX()].getOccupant();

    //If tile has a piece on it and it is the current player's piece,
    //then it is a valid piece selection:
    if(tilePiece != NULL && tilePiece->getOwner() == p)
    {selectedPiece = tilePiece; return true;}

    return false;
}

Piece* ChessBoard::getSelectedPiece()
{
    return selectedPiece;
}


Tile ChessBoard::getTile(Coordinate coord)
{
    return board[coord.getY()][coord.getX()];
}

void ChessBoard::disassemblePieces()
{
    //Release all memory from board:
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (!board[i][j].empty())
                delete board[i][j].getOccupant();

    //Release memory from trash pile for player 1:
    for (size_t i = 0; i < playerOneTrash.size(); i++)
        if (playerOneTrash[i] != NULL)
            delete playerOneTrash[i];

    //Release memory from trash pile for player 2:
    for (size_t i = 0; i < playerTwoTrash.size(); i++)
        if (playerTwoTrash[i] != NULL)
            delete playerTwoTrash[i];
}

bool ChessBoard::draw()
{
   //If only two kings remain on board then a draw has taken place:
    if(   playerOneTrash.size() == 15
       && playerTwoTrash.size() == 15
       && playerOneKing->getPosition().getX() != -1
       && playerTwoKing->getPosition().getX() != -1)
        return true;

    return false;
}

