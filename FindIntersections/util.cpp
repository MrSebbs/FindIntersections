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

vector2f::vector2f(float x, float y, Intersection* intr): x(x), y(y), intr(intr) {
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
	ss << "Segment from " << S->print() << " to " << E->print();
	return ss.str();
}

//class intersection
Intersection::Intersection(vector2f* p): intr(p){
	p->intr = this;
}

Intersection::Intersection(Segment* S, Segment* Q): first(S), second(Q){

}

vector2f* Intersection::getPoint() {
	return intr;
}

Segment* Intersection::getFirst() {
	return first;
}

Segment* Intersection::getSecond() {
	return second;
}

string Intersection::print() {
	stringstream ss;
	ss << "Intersection point: " << intr->print();
	return ss.str();
}


#endif


