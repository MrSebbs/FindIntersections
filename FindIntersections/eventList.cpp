#ifndef EVENT_LIST
#define EVENT_LIST

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "util.h"
using namespace std;


class EventList{

private:
	list <vector2f*> evList;

public:

	EventList(list <Segment> * data) {
		for (list<Segment>::iterator i = data->begin(); i != data->end(); i++) {
			evList.push_back(i->getStart());
			evList.push_back(i->getEnd());
		}
		//evList.sort(y_desc);
	}

	list <vector2f*> * getList() {
		return &evList;
	}

	void addPoint(vector2f* p) {
		list <vector2f*>::iterator i = evList.begin();
		for (i; i != evList.end(); i++) {
			if ((*i)->y < p->y || (*i)->y == p->y && (*i)->x >= p->x) {
				break;
			}
		}
		evList.insert(i, p);
	}

	string print() {
		stringstream ss;
		ss << "EventList:" << endl;
		for (list <vector2f*>::iterator i = evList.begin(); i != evList.end(); i++) {
			ss << (*i)->print() << endl;
		}
		return ss.str();
	}

	string printFathers() {
		stringstream ss;
		ss << "Fathers:" << endl;
		for (list <vector2f*>::iterator i = evList.begin(); i != evList.end(); i++) {
			if ((*i)->father != NULL)
				ss << ((*i)->father)->print() << endl;
			else
				ss << "NULL" << endl;
		}
		return ss.str();
	}

};

#endif


