#ifndef HIDDENBOARD_H
#define HIDDENBOARD_H
#include "board.h"
#include "boarddecorator.h"
#include <vector>
#include <algorithm>

class HiddenBoard : public BoardDecorator { 
    int xMax, yMax, xMin, yMin; 
    vector<Coordinate> inputtedLocations;
    public: 
        HiddenBoard(Board *myBoard, int xMax, int yMax, int xMin = 0, int yMin = 0);
        char charAt(int row, int col);
        bool addPlay(int x, int y); 
};

#endif
