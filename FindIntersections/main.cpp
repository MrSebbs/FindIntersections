#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "main.h"


using namespace std;

bool y_desc(vector2f* first, vector2f* second) {
	if (first->y != second->y)
		return (first->y > second->y);
	else
		return (first->x < second->x);
}

int main(int arg, char** argv) {

	//Data entry
	list <Segment> data;
	data.push_back(Segment(new vector2f(-1, 2), new vector2f(4, 5)));
	data.push_back(Segment(new vector2f(3, -1), new vector2f(5, 4)));
	data.push_back(Segment(new vector2f(5, 2), new vector2f(3, 1)));
	data.push_back(Segment(new vector2f(3, 3), new vector2f(5, 6)));
	data.push_back(Segment(new vector2f(2, 9), new vector2f(0, 0)));
	//printData(data);

	eventList = new EventList(&data);
	(eventList->getList())->sort(y_desc);
	
	//Aquí comença l'algorisme!!
	while (!eventList->isEmpty()) {
		vector2f* p = eventList->getNext();
		addPoint(p);
		eventList->removeFront();

		cout << eventList->print() << endl;
		print(status);

	}

	system("pause");
	return 0;
}

void printData(list <Segment> data) {
	for (list<Segment>::iterator i = data.begin(); i != data.end(); i++) {
		cout << i->print() << endl;
	}
}

void addPoint(vector2f* p) {
	if (p->father != NULL) {		//Això s'hauria de comprobar en un altre lloc. Aquesta linia s'haura d'eliminar
		if ((p->father)->inStatus == false) {
			p->setStart();
			insertToStatus(p);
			(p->father)->inStatus = true;
		}
		else {
			status.remove((p->father)->getOpposite(p));
			//S'han de fer més checks
		}
	}
}

void insertToStatus(vector2f* p) {
	list<vector2f*>::iterator i = status.begin();
	for (i; i != status.end(); i++) {
		if ((*i)->x >= p->x) {
			break;
		}
	}
	status.insert(i, p);

	if (status.begin() != status.end()) {
		if (i != status.begin()) {
			i--;
			Intersection* pair = new Intersection((*i)->father, p->father);
			pair->setCheck(pair->checkIntersection());
			if (pair->getCheck())
				eventList->addPoint(pair->computeIntersection());
			i++;
		}
		else if (i != status.end()) {
			i++;
			Intersection* pair = new Intersection((*i)->father, p->father);
			pair->setCheck(pair->checkIntersection());
			if (pair->getCheck())
				eventList->addPoint(pair->computeIntersection());
			i--;
		}
	}
}

void print(list <vector2f*> status) {
	cout << "Status: " << endl;
	for (list<vector2f*>::iterator i = status.begin(); i != status.end(); i++) {
		if ((*i)->father != NULL) {
			cout << ((*i)->father)->print() << endl;
		}
		else if ((*i)->intr != NULL) {
			cout << ((*i)->intr)->print() << endl;
		}
	}
	cout << endl;

}

