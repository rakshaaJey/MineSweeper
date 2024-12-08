#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <vector>
#include <algorithm>

class Subject {
  protected:
    std::vector<Observer*> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual char getState( int row, int col ) = 0;
  virtual ~Subject() = default;
};

#endif
