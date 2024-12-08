#include "coordinate.h"

using namespace std;

Coordinate::Coordinate(int x, int y): x{x}, y{y} { }

Coordinate Coordinate::getCoordinate() {return {getX(), getY()}; }

int Coordinate::getX() { return x; }

int Coordinate::getY() { return y; }

bool Coordinate::equals(Coordinate c) { return ((x == c.x) && (y == c.y)); }

void Coordinate::randomCoordinate(int xMax, int yMax, int xMin, int yMin) {
    x = xMin + (rand() % xMax);
    y = yMin + (rand() % yMax);
}

bool Coordinate::around(Coordinate c) {
    if(equals(c)) return false; 
    if(c.x >= x - 1 && c.x <= x + 1 && c.y >= y -1 && c.y <= y + 1) return true;
    return false;
}

ostream &operator<<(ostream &out, Coordinate c) {
    out << "(" << c.getX() << "," << c.getY() << ")"; 
    return out; 
}
