#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "board.h"
#include "boarddecorator.h"
#include "coordinate.h"
#include <cstdlib>
#include <string>
#include <sstream>

class GameBoard : public BoardDecorator {  
    int xMax, yMax, xMin, yMin;
    int numOfBombs;
    char c;        
    vector<Coordinate> bombLocations;
    public:
        GameBoard(Board *myBoard, int numOfBombs, int xMax, int yMax, int xMin = 0, int yMin = 0, bool random = true);
        char charAt(int row, int col);
        bool addPlay(int x, int y); 
};    

#endif
