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

void addPoint(vector2f* p);

void insertToStatus(vector2f* p);

void print(list <vector2f*> status);


#endif


