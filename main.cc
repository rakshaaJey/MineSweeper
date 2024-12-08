#include "board.h"
#include "blankboard.h"
#include "coordinate.h"
#include "gameboard.h"
#include "hiddenboard.h"
#include "flagboard.h"
#include "removeflagboard.h"
#include "game.h"
#include "textobserver.h"
#include <iostream>
#include <string>

const int ROWMAX = 10; 
const int COLMAX = 10;
const int DEFAULT_BOMB = 5;
const string CHANGE_SIZE = "-size";
const string CHANGE_LEVEL = "-lvl";
const string NUM_BOMBS = "-bomb";

using namespace std;

int main(int argc, char* argv[]) {
    int row = ROWMAX;
    int col = COLMAX;
    int bomb = 5;
    int argBomb;
    if(argc != 1) {
        for(int i = 1; i < argc; ++i) {
            string currentArg = argv[i];
            if(currentArg == CHANGE_SIZE) {
                row = stoi(argv[i + 1]);
                col = stoi(argv[i + 2]);
                i += 2;
            }
            if(currentArg == NUM_BOMBS) {
                bomb = stoi(argv[i + 1]);
                i += 1;
            }
        }
    }
    
    string cmd;
    int x, y;
    bool game = true;
    Game g{row, col, bomb};
    g.attach(new TextObserver{g});
    while(game) {
        g.render();
        cout << "Your move: ";
        while(cin >> cmd) {
            if(cmd == "r") {
                cin >> x >> y;
                game = g.picture()->addPlay(x, y);
                g.render();
            }
            if(cmd == "f") {
                cin >> x >> y;
                game = g.picture() = new FlagBoard{g.picture(), x, y};
                g.render();
            }
            if(cmd == "rmf") {
                cin >> x >> y;
                game = g.picture() = new RemoveFlagBoard{g.picture(), x, y};
                g.render();
            }
            if(!game) {
                cout << endl;
                g.reset();
                cout << "YOU LOST :(" << endl;
                cout << "Play again? (Y/N)" << endl;
                string playAgain; 
                cin >> playAgain; 
                if(playAgain == "Y") {
                    game = true; 
                }
                break;
            }
            if(g.won()) {
                cout << endl;
                g.reset();
                cout << "YOU WON!" << endl;
                cout << "Play again? (Y/N)" << endl;
                string playAgain; 
                cin >> playAgain; 
                if(playAgain == "Y") {
                    game = true; 
                }
                break;
            }
            cout << "Your move: ";
        }
    }
}
