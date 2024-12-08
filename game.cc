#include "game.h"

bool Game::won() {
    bool won = true; 
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(picture()->charAt(i, j) == '*') won = false;
        }
    }  
    return won;
}

char Game::getState(int row, int col) {
    theBoard->charAt(row, col);
}

void Game::render() {
    notifyObservers();
}

void Game::reset() {
    cout << "    ";
    for(int i = 0; i < cols; ++i) {
        cout << i % 10 << " ";
    } 
    cout << " \n";
    cout << "  + ";
    for(int i = 0; i < cols; ++i) {
        cout << "- ";
    } 
    cout << "+ ";
    cout << " \n";
    for(int i = 0; i < rows; ++i) {
        cout << i % 10 << " ";
        cout << "| ";
        for(int j = 0; j < cols; ++j) {
            cout << underBoard->charAt(i, j) << " ";
        }
        cout << "|\n";
    } 
    cout << "  + ";
    for(int i = 0; i < cols; ++i) {
        cout << "- ";
    } 
    cout << "+" << endl;
    delete theBoard;
    theBoard = new BlankBoard;
    theBoard = new GameBoard{theBoard, numBombs, cols - 1, rows - 1};
    underBoard = theBoard;
    theBoard = new HiddenBoard{theBoard, cols - 1, rows - 1};
}

Game::~Game() {
    for (auto *observer : observers) {
        delete observer; 
    }    
    observers.clear();
    delete theBoard; 
    delete underBoard;
}
