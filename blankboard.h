#ifndef BLANKBOARD_H
#define BLANKBOARD_H
#include "board.h"

using namespace std;

class BlankBoard: public Board {
    public:
        char charAt(int row, int col) override;
        bool addPlay(int x, int y);
};

#endif
