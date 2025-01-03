#include "subject.h"

using namespace std;

void Subject::attach( Observer* o ) {
    observers.emplace_back(o);
}

void Subject::detach( Observer* o ) {
    observers.erase(find(observers.begin(), observers.end(), o));
}

void Subject::notifyObservers() {
    for(auto ob: observers) ob->notify();
}
