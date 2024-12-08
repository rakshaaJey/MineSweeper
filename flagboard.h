#ifndef FLAGBOARD_H
#define FLAGBOARD_H
#include "board.h"
#include "boarddecorator.h"
#include "coordinate.h"

class FlagBoard : public BoardDecorator { 
    Coordinate flagLocation; 
    public:
        FlagBoard(Board *myBoard, int x, int y);
        char charAt(int row, int col);
        bool addPlay(int x, int y); 
};    

#endif
