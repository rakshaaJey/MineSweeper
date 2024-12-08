#ifndef REMOVEFLAGBOARD_H
#define REMOVEFLAGBOARD_H
#include "board.h"
#include "boarddecorator.h"
#include "coordinate.h"

class RemoveFlagBoard : public BoardDecorator { 
    Coordinate flagLocation; 
    public:
        RemoveFlagBoard(Board *myBoard, int x, int y);
        char charAt(int row, int col);
        bool addPlay(int x, int y); 
};    

#endif
