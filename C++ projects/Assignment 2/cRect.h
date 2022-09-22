#pragma once
#include "Point.h"
using namespace std;

class cRect
{
private:
	Point  _p0,_p1, _p2, _p3;

public:
	Point get(int num);
	void set(int num,Point p);
	void printRect();
	int calcArea();
	
};

