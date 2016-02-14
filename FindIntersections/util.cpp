#ifndef UTIL
#define UTIL

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class segment;

class vector2f {

public:
	float x;
	float y;
	segment* father;

	vector2f(float x, float y) : x(x), y(y) {}

	void setFather(segment* s) {
		father = s;
	}

	string print() {
		stringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}

	//string printFather();

};

class segment {

private:
	vector2f* S;
	vector2f* E;

public:

	segment(vector2f* A, vector2f* B) {
		S = A;
		S->setFather(this);

		E = B;
		E->setFather(this);
	}

	vector2f* getStart() {
		return S;
	}

	vector2f* getEnd() {
		return E;
	}

	void swap() {
		vector2f* aux = S;
		S = E;
		E = aux;
	}

	string print() {
		stringstream ss;
		ss << "Segment from " << S->print() << " to " << E->print();
		return ss.str();
	}

};


#endif


