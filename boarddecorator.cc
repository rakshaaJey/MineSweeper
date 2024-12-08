#include "boarddecorator.h"

BoardDecorator::BoardDecorator(Board *myBoard): myBoard{myBoard} {}

BoardDecorator::~BoardDecorator() { delete myBoard; } 

char BoardDecorator::charAt(int row, int col) { 
    myBoard->charAt(row, col);
}

bool BoardDecorator::addPlay(int x, int y) {
    myBoard->addPlay(x, y);
}
