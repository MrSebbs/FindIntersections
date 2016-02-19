#ifndef UTIL_CPP
#define UTIL_CPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "util.h"
using namespace std;

// class vector2f
vector2f::vector2f(float x, float y) : x(x), y(y) {
	father = NULL;
	intr = NULL;
}

vector2f::vector2f(float x, float y, PairOfSegments* intr): x(x), y(y), intr(intr) {
	father = NULL;
}

void vector2f::setStart() {
	if (father->getEnd() == this) {
		father->swapStartToEnd();
	}
}

void vector2f::setFather(Segment* s) {
	father = s;
}

string vector2f::print() {
	stringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}

string vector2f::printFather() {
	return "";
}

// class segment
Segment::Segment(vector2f* A, vector2f* B) {
	S = A;
	E = B;
	inStatus = false;
	S->setFather(this);
	if (B != NULL) {
		E->setFather(this);
	}
}

vector2f* Segment::getStart() {
	return S;
}

vector2f* Segment::getEnd() {
	return E;
}

vector2f* Segment::getOpposite(vector2f* A) {
	if (S == A)
		return E;
	else if (E == A)
		return S;
	else
		cout << "getOpposite(vector2f*) ERROR: vector2f not found" << endl;
	return NULL;

}

void Segment::swapStartToEnd() {
	vector2f* aux = S;
	S = E;
	E = aux;
}

string Segment::print() {
	stringstream ss;
	if (S != NULL & E != NULL) {
		ss << "Segment from " << S->print() << " to " << E->print();
	}else if (S != NULL) {
		ss << "Intersection at: " << S->print();
	}
	return ss.str();
}

//class PairOfSegments
PairOfSegments::PairOfSegments(Segment* S, Segment* Q): first(S), second(Q){}

bool PairOfSegments::checkIntersection() {
	vector2f A = *(first->getStart());
	vector2f B = *(first->getEnd());
	vector2f C = *(second->getStart());
	vector2f D = *(second->getEnd());

	vector2f CA = vector2f(A.x - C.x, A.y - C.y);
	vector2f CB = vector2f(B.x - C.x, B.y - C.y);
	vector2f CD = vector2f(D.x - C.x, D.y - C.y);

	float det_CA_CD = CA.x * CD.y - CA.y * CD.x;
	float det_CB_CD = CB.x * CD.y - CB.y * CD.x;
	float producte_C = det_CA_CD * det_CB_CD;

	cout << producte_C << endl;

	vector2f AC = vector2f(C.x - A.x, C.y - A.y);
	vector2f AD = vector2f(D.x - A.x, D.y - A.y);
	vector2f AB = vector2f(B.x - A.x, B.y - A.y);

	float det_AC_AB = AC.x * AB.y - AC.y * AB.x;
	float det_AD_AB = AD.x * AB.y - AD.y * AB.x;
	float producte_A = det_AC_AB * det_AD_AB;

	cout << producte_A << endl;

	if (producte_C < 0 & producte_A < 0) {
		return true;
	}
	else {
		return false;
	}

}

void PairOfSegments::computeIntersection() {
	float m1 = ((first->getEnd())->y - (first->getStart())->y) / ((first->getEnd())->x - (first->getStart())->x);
	float m2 = ((second->getEnd())->y - (second->getStart())->y) / ((second->getEnd())->x - (second->getStart())->x);
	float n1 = (first->getStart())->y - m1 * (first->getStart())->x;
	float n2 = (second->getStart())->y - m2 * (second->getStart())->x;

	float x = (n2 - n1) / (m1 - m2);
	float y = m1 * x + n1;

	intr = new vector2f(x, y, this);
}

vector2f* PairOfSegments::getPoint() {
	return intr;
}

Segment* PairOfSegments::getFirst() {
	return first;
}

Segment* PairOfSegments::getSecond() {
	return second;
}

string PairOfSegments::print() {
	stringstream ss;
	if (intr != NULL) {
		ss << "Intersection point: " << intr->print();
	}
	return ss.str();
}


#endif


