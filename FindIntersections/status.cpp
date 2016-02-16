#ifndef STATUS
#define STATUS

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "util.h"
using namespace std;


class Status {

private:
	list <vector2f*> _status;

public:

	Status() {

	}

	void addPoint(vector2f* p) {
		list<vector2f*>::iterator i = _status.begin();
		for (i; i != _status.end(); i++) {
			if ((*i)->x >= p->x) {
				break;
			}
		}
		_status.insert(i, p);
		if (p->father != NULL)
			p->setStart();
	}
	
	list <vector2f*>  getList() {
		return _status;
	}

	void print() {
		cout << "Status: " << endl;
		for (list<vector2f*>::iterator i = _status.begin(); i != _status.end(); i++) {
			if ((*i)->father != NULL) {
				cout << ((*i)->father)->print() << endl;
			}
			else if ((*i)->intr != NULL) {
				cout << ((*i)->intr)->print() << endl;
			}
		}
		cout << endl;

	}

};

#endif


