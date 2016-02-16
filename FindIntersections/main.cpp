#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "EventList.cpp"
#include "Status.cpp"

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

void handleEventPoint(vector2f* p);

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

	/*
	Intersection* a = new Intersection(new vector2f(0.7, 3));
	Intersection* b = new Intersection(new vector2f(8, 13));
	Intersection* c = new Intersection(new vector2f(-2, -13));
	eventList.addPoint(a->getPoint());
	eventList.addPoint(b->getPoint());
	eventList.addPoint(c->getPoint());
	*/

	cout << eventList.print() << endl;
	cout << eventList.printFathers() << endl;

	Status* status = new Status();
	//printStatus(&status);
	list <vector2f*> ::iterator i = (eventList.getList())->begin();
	status->addPoint(*i);
	status->addPoint(*(++i));
	status->addPoint(*(++i));
	status->addPoint(*(++i));
	status->print();


	//Aquí comença l'algorisme!!
	while (!eventList.isEmpty()) {
		handleEventPoint(eventList.getNext());
		eventList.removeFront();
	}

	system("pause");
	return 0;
}

void handleEventPoint(vector2f* p) {

}