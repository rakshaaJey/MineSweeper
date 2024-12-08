#include "gameboard.h"

using namespace std;


GameBoard::GameBoard(Board *myBoard, int numOfBombs, int xMax, int yMax, int xMin, int yMin, bool random): 
    BoardDecorator{myBoard}, numOfBombs{numOfBombs}, xMax{xMax}, yMax{yMax}, xMin{xMin}, yMin{yMin} {
    if(random) {
        int i = 0; 
        while(i < numOfBombs) {
            Coordinate newCoord;
            newCoord.randomCoordinate(xMax, yMax, xMin, yMin);
            for (auto it = begin(bombLocations); it != end(bombLocations);) {
                if(it->equals(newCoord)) {
                    newCoord.randomCoordinate(xMax, yMax, xMin, yMin);
                    it = begin(bombLocations);
                } else {
                    ++it;
                }
            }
            bombLocations.emplace_back(newCoord);
            ++i;
        }
    }
}

char GameBoard::charAt(int row, int col) {
    Coordinate coord = {col, row};
    int bombCounter = 0;
    for (auto it = begin(bombLocations); it != end(bombLocations); ++it) {
        if(it->equals(coord)) return 'B';
        if(it->around(coord)) bombCounter += 1; 
    }

    if(bombCounter != 0) {
        string t = to_string(bombCounter);
        return t[0];
    }

    return myBoard->charAt(row, col);
}

bool GameBoard::addPlay(int x, int y) { return true; }
