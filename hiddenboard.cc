#include "hiddenboard.h"

using namespace std;

HiddenBoard::HiddenBoard(Board *myBoard, int xMax, int yMax, int xMin, int yMin): BoardDecorator{myBoard}, xMax{xMax}, yMax{yMax}, xMin{xMin}, yMin{yMin} {}

char HiddenBoard::charAt(int row, int col) { 
    Coordinate coord = {col, row};
    if(inputtedLocations.size() != 0) {
        for (auto it = begin(inputtedLocations); it != end(inputtedLocations); ++it) {
            if(it->equals(coord)) return myBoard->charAt(row, col);
        } 
    }
    return '*';
}

vector<Coordinate> aroundCoord(Coordinate c, int xMax, int yMax, int xMin, int yMin) {
    vector<Coordinate> around; 
    int x = c.getX();
    int y = c.getY();
    Coordinate a;

    if(x - 1 >= xMin) {
        if(y - 1 >= yMin) {
            a = {x - 1, y - 1};
            around.emplace_back(a);
        }
        a = {x - 1, y};
        around.emplace_back(a);
        if(y + 1 <= yMax) {
            a = {x - 1, y + 1};
            around.emplace_back(a);
        }
    }


    if(x + 1 <= xMax) {
        if(y - 1 >= yMin) {
            a = {x + 1, y - 1};
            around.emplace_back(a);
        }
        a = {c.getX() + 1, c.getY()};
        around.emplace_back(a);
        if(y + 1 <= yMax) {
            a = {x + 1, y + 1};
            around.emplace_back(a);
        }
    }

    if(y - 1 >= yMin) {
        a = {x, y - 1};
        around.emplace_back(a);
    }
    if(y + 1 <= yMax) {
        a = {x, y + 1};
        around.emplace_back(a);
    }

    return around;
}

bool HiddenBoard::addPlay(int x, int y) {
    Coordinate anchor = {x, y};
    inputtedLocations.emplace_back(anchor);
    char below = myBoard->charAt(y, x);
    if(below == 'B') {
        return false;
    }
    if(below != ' ') return true; 
    
    vector<Coordinate> aroundAnchor = aroundCoord(anchor, xMax, yMax, xMin, yMin);
    int size = aroundAnchor.size();

    for (int i = 0; i < size; ++i) {
        // checks if current coordinate is blank
        if(myBoard->charAt(aroundAnchor.at(i).getY(), aroundAnchor.at(i).getX()) == ' ') {
            Coordinate c = {aroundAnchor.at(i).getX(), aroundAnchor.at(i).getY()};
            vector<Coordinate> arroundCurr = aroundCoord(c, xMax, yMax, xMin, yMin); 
            for(auto ac : arroundCurr) {
                Coordinate i = {ac.getX(), ac.getY()}; 
                bool found = false; 
                for(auto aa : aroundAnchor) {
                    Coordinate curr = {aa.getX(), aa.getY()}; 
                    if(i.equals(curr)) {
                        found = true; 
                        break;
                    }
                }
                if(!found) {
                    aroundAnchor.emplace_back(i);
                    ++ size;
                }
            }
        }
    } 

    inputtedLocations.insert(inputtedLocations.end(), aroundAnchor.begin(), aroundAnchor.end());
    
    return true; 

}
