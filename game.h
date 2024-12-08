#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "board.h"
#include "blankboard.h"
#include "gameboard.h"
#include "hiddenboard.h"
#include "subject.h"
#include "observer.h"

class Board;

class Game : public Subject {
    int rows, cols;
    int numBombs = 5;

    Board *theBoard;
    Board *underBoard;

    public:
        Game(Board *board, int rows = 10, int cols = 10): theBoard{board}, rows{rows}, cols{cols} {}
        Game(int rows = 10, int cols = 10, int numOfBombs = 5): rows{rows}, cols{cols}, numBombs{numOfBombs} {
            theBoard = new BlankBoard; 
            theBoard = new GameBoard{theBoard, numOfBombs, cols - 1, rows - 1};
            underBoard = theBoard;
            theBoard = new HiddenBoard{theBoard, cols - 1, rows - 1};
        }

        Board *&picture() { return theBoard; }
        int getRows() { return rows; }
        int getCols() { return cols; }
        char getState(int row, int col);
        bool won();
        void render();
        void reset();
        ~Game();
};

#endif
