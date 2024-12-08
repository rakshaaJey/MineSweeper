#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "coordinate.h"

using namespace std;

class Board {
  public:
    virtual ~Board();

    virtual char charAt(int row, int col) = 0;
    virtual bool addPlay(int x, int y) = 0; 
};

#endif
