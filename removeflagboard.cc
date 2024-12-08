#include "removeflagboard.h"


RemoveFlagBoard::RemoveFlagBoard(Board *myBoard, int x, int y): BoardDecorator{myBoard} {
    flagLocation = {x, y};
}

char RemoveFlagBoard::charAt(int row, int col) {
    Coordinate currLocation = {col, row};
    if(flagLocation.equals(currLocation) && myBoard->charAt(row, col) == 'F') { return '*'; }
    return myBoard->charAt(row, col);
}

bool RemoveFlagBoard::addPlay(int x, int y) { 
    return myBoard->addPlay(x, y);
}
