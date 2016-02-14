#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "util.cpp"
#include "EventList.cpp"

using namespace std;


void printData(list <segment> data){
	for (list<segment>::iterator i = data.begin(); i != data.end(); i++) {
		cout << i->print() << endl;
	}
}

bool y_desc(vector2f* first, vector2f* second) {
	if (first->y != second->y)
		return (first->y > second->y);
	else
		return (first->x < second->x);
}

int main(int arg, char** argv) {

	//Data entry
	list <segment> data;
	data.push_back(segment(new vector2f(-1, 2), new vector2f(4, 5)));
	data.push_back(segment(new vector2f(3, -1), new vector2f(5, 4)));
	data.push_back(segment(new vector2f(5, 2), new vector2f(3, 1)));
	data.push_back(segment(new vector2f(3, 3), new vector2f(5, 6)));
	data.push_back(segment(new vector2f(2, 9), new vector2f(0, 0)));
	//printData(data);

	EventList eventList = EventList(&data);
	eventList.getList()->sort(y_desc);
	eventList.addPoint(new vector2f(0.7, 3));
	cout << eventList.print()<<endl;
	
	


	system("pause");
	return 0;
}

