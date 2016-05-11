#include <iostream>
#include <conio.h>
#include <windows.h> // WinApi header
#include "chessgame.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_Q 81
#define KEY_q 113

typedef void (*fptr)(int key, ChessGame&);

void moveCursorUp(int key, ChessGame&);
void moveCursorDown(int key, ChessGame&);
void moveCursorLeft(int key, ChessGame&);
void moveCursorRight(int key, ChessGame&);
void processSpace(int key ,ChessGame&);
void doNothing(int key, ChessGame&);

int main()
{
  //Create Game object:
    ChessGame game;

  //Create function pointers to process key presses.
  //This is also eliminates the use of switch statement:
    fptr gameProcess[114];

  //Initialize function pointers:
   for(int i = 0; i < 114; i++)
       gameProcess[i] = &doNothing;

    gameProcess[KEY_UP] = &moveCursorUp;
    gameProcess[KEY_DOWN] = &moveCursorDown;
    gameProcess[KEY_LEFT] = &moveCursorLeft;
    gameProcess[KEY_RIGHT] = &moveCursorRight;
    gameProcess[KEY_SPACE] = &processSpace;

  //Print out board:
    game.gameLoop(KEY_UP);

  //Game Loop:
    while(!game.gameOver())
    {
        int key = getch();

       //Check if player surrendered:
        if(key == KEY_Q || key == KEY_q)
        {system("cls"); cout << "QUIT GAME!!" << endl; break;}

       //Process key input via chess game:
        if(key <= 113 && key >= 0)
            gameProcess[key](key, game);
    }

    return 0;
}

void moveCursorUp(int key, ChessGame& g)
{
    g.gameLoop(key);
}

void moveCursorDown(int key, ChessGame& g)
{
    g.gameLoop(key);
}

void moveCursorLeft(int key, ChessGame& g)
{
    g.gameLoop(key);
}

void moveCursorRight(int key, ChessGame& g)
{
    g.gameLoop(key);
}

void processSpace(int key, ChessGame& g)
{
    g.gameLoop(key);
}

void doNothing(int key, ChessGame& g)
{
}
