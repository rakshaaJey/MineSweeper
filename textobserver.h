#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include <iostream>
#include "observer.h"
#include "game.h"

class TextObserver: public Observer {
	Game &g;
	int xMax, yMax;
    int xMin = 0;
    int yMin = 0;

	public: 
        TextObserver(Game &g);
		void notify();
        ~TextObserver();
};

#endif
