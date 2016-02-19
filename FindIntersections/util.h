#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;


class Segment;
class PairOfSegments;

class vector2f
{
public:
	float x;
	float y;
	Segment* father;
	PairOfSegments* intr;
	//vector2f* statusPosition;

	vector2f(float x, float y);
	vector2f(float x, float y, PairOfSegments* intr);
	void setStart();
	void setFather(Segment* s);
	string print();
	string printFather();
};

class Segment
{
private:
	vector2f* S;
	vector2f* E;

public:
	bool inStatus;
	Segment(vector2f* A, vector2f* B);
	vector2f* getStart();
	vector2f* getEnd();
	vector2f* getOpposite(vector2f* A);
	void swapStartToEnd();
	string print();
};

class PairOfSegments
{
private:
	vector2f* intr;
	Segment* first;
	Segment* second;

public:
	PairOfSegments(Segment* S, Segment* Q);
	bool checkIntersection();
	void computeIntersection();
	vector2f* getPoint();
	Segment* getFirst();
	Segment* getSecond();
	string print();
};

#endif
