#include "textobserver.h"

using namespace std;

TextObserver::TextObserver(Game &g): g{g} {
    xMax = g.getCols();
    yMax = g.getRows();
}

void TextObserver::notify() {
    cout << "    ";
    for(int i = 0; i < xMax; ++i) {
        cout << i % 10 << " ";
    } 
    cout << " \n";
    cout << "  + ";
    for(int i = 0; i < xMax; ++i) {
        cout << "- ";
    } 
    cout << "+ ";
    cout << " \n";
    for(int i = 0; i < yMax; ++i) {
        cout << i % 10 << " ";
        cout << "| ";
        for(int j = 0; j < xMax; ++j) {
            cout << g.picture()->charAt(i, j) << " ";
        }
        cout << "|\n";
    } 
    cout << "  + ";
    for(int i = 0; i < xMax; ++i) {
        cout << "- ";
    } 
    cout << "+" << endl;
}

TextObserver::~TextObserver() {}
