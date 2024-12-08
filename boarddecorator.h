#ifndef BOARDDECORATOR_H
#define BOARDDECORATOR_H
#include "board.h"

class BoardDecorator : public Board {
    protected: 
        Board *myBoard; 
    public:
        BoardDecorator(Board *myBoard);
        virtual ~BoardDecorator();
        virtual char charAt(int row, int col);
        virtual bool addPlay(int x, int y); 
};  

#endif
