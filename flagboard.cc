#include "flagboard.h"


FlagBoard::FlagBoard(Board *myBoard, int x, int y): BoardDecorator{myBoard} {
    flagLocation = {x, y};
}

char FlagBoard::charAt(int row, int col) {
    Coordinate currLocation = {col, row};
    if(flagLocation.equals(currLocation) && myBoard->charAt(row, col) == '*') { return 'F'; }
    return myBoard->charAt(row, col);
}

bool FlagBoard::addPlay(int x, int y) { 
    return myBoard->addPlay(x, y);
}
