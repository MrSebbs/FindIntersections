#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "EventList.cpp"

using namespace std;


void printData(list <Segment> data){
	for (list<Segment>::iterator i = data.begin(); i != data.end(); i++) {
		cout << i->print() << endl;
	}
}

bool y_desc(vector2f* first, vector2f* second) {
	if (first->y != second->y)
		return (first->y > second->y);
	else
		return (first->x < second->x);
}

//S'haurà de modificar addPoint dins de eventList
void addToStatus(list <Segment*> * status, vector2f* p) {
	list<Segment*>::iterator i = status->begin();
	for (i; i != status->end(); i++) {
		if (((*i)->getStart())->x >= p->x) {
			break;
		}
	}
	
	if (p->father != NULL) {
		p->setStart();
		status->insert(i, p->father);
	}
	else {
		status->insert(i, new Segment(p, NULL));
	}
}

void printStatus(list <Segment*> * status) {
	cout << "Status: " << endl;
	for (list<Segment*>::iterator i = status->begin(); i != status->end(); i++) {
		if ((*i)->getEnd() != NULL) {
			cout << (*i)->print() << endl;
		}
		else {
			cout << "Intersection Point: " << ((*i)->getStart())->print() << endl;
		}	
	}
	cout << endl;
	
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

	EventList eventList = EventList(&data);
	eventList.getList()->sort(y_desc);
	//cout << eventList.print() << endl;
	eventList.addPoint(new vector2f(0.7, 3));
	eventList.addPoint(new vector2f(8, 13));
	eventList.addPoint(new vector2f(-2, -13));
	cout << eventList.print() << endl;
	cout << eventList.printFathers() << endl;

	list <Segment*> status;
	//printStatus(&status);
	list <vector2f*> ::iterator i = (eventList.getList())->begin();
	addToStatus(&status, *i);
	addToStatus(&status, *(++i));
	addToStatus(&status, *(++i));
	addToStatus(&status, *(++i));
	printStatus(&status);



	system("pause");
	return 0;
}

