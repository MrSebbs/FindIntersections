#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "util.h"
#include "eventList.cpp"

using namespace std;

EventList* eventList;
list <vector2f*> status;
list <PairOfSegments*> checks;
list <vector2f*> save;

void addPoint(vector2f* p);
void insertToStatus(vector2f* p);
bool isChecked(vector2f* s, vector2f* q);
void check(PairOfSegments* pair);
void swapStatus(PairOfSegments* pair);
void printStatus();

#endif


