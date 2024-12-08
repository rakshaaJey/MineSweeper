#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Coordinate {
    int x;
    int y;

    public:
        Coordinate(int x = 0, int y = 0);
        Coordinate getCoordinate();
        int getX();
        int getY();
        bool equals(Coordinate c);
        void randomCoordinate(int xMax, int yMax, int xMin = 0, int yMin = 0);
        bool around(Coordinate c);
};

ostream &operator<<(ostream &out, Coordinate c);


#endif
