#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "main.h"

using namespace std;

void printData(list <Segment> data) {
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
	
	while (!eventList->isEmpty()) {
		vector2f* p = eventList->getNext();
		if (p->father != NULL)
			addPoint(p);
		else if (p->intr != NULL)
			swapStatus(p->intr);

		eventList->removeFront();
	}
	system("pause");
	return 0;
}

void addPoint(vector2f* p) {
	//Si el Segment no és dins de l'Status l'insertem a l'Status
	if ((p->father)->inStatus == false) {
		p->setStart();
		insertToStatus(p);
		(p->father)->inStatus = true;
	}else {		//Si el segment ja era dins de l'Status eliminem el Segment de la EventList i fem més checks
		for (list<vector2f*>::iterator i = status.begin(); i != status.end(); i++) {
			if ((*i == (p->father)->getOpposite(p) )&( *i != status.front() & *i != status.back())) {
				vector2f* s = *(--i);
				i++;
				vector2f* q = *(++i);
				if (!isChecked(s, q)) {
					check(new PairOfSegments(s->father, q->father));
				}
				i--;
				status.erase(i);
				break;
			}
		}
	}
	
}

void insertToStatus(vector2f* p) {
	//Recorrem Status per insertar el punt en el lloc que li toca
	list<vector2f*>::iterator i = status.begin();
	for (i; i != status.end(); i++) {
		if ((*i)->x > p->x || (*i)->x == p->x && (*i)->y <= p->y) {
			break;
		}
	}
	i = status.insert(i, p);
	//Comprovem si hi ha noves interseccions
	if (status.size() >= 2) {
		if (*i != status.front()) {
			i--;
			check(new PairOfSegments((*i)->father, p->father));
			i++;
		}
		if (*i != status.back()) {
			i++;
			check(new PairOfSegments((*i)->father, p->father));
			i--;
		}
	}
}

bool isChecked(vector2f* s, vector2f* q) {
	for (list<PairOfSegments*>::iterator i = checks.begin(); i != checks.end(); i++) {
		if ((*i)->getFirst() == s->father | (*i)->getSecond() == s->father) {
			if ((*i)->getFirst() == q->father | (*i)->getSecond() == q->father) {
				return true;
			}
		}
	}
	return false;
}

void check(PairOfSegments* pair) {
	cout << "CHECK : " << endl;
	cout << pair->getFirst()->print() << endl;
	cout << pair->getSecond()->print() << endl;
	if (pair->checkIntersection()){
		pair->computeIntersection();
		cout << "INTERSECTION: " << pair->print() << endl;
		cout << pair->getFirst()->print() << endl;
		cout << pair->getSecond()->print() << endl;
		save.push_back(pair->getPoint());
		eventList->addPoint(pair->getPoint());
		checks.push_back(pair);
	}
	cout << endl;
}

void swapStatus(PairOfSegments* pair) {
	cout << "SWAP" << endl << endl;

	/*
	status.remove(pair->getFirst()->getStart());
	status.remove(pair->getSecond()->getStart());

	pair->getFirst()->getEnd()->setStart();
	pair->getSecond()->getEnd()->setStart();
	*/



}

void printStatus() {
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

