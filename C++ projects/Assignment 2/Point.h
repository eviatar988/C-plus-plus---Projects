#pragma once
using namespace std;

class Point
{
private:
	int _x;
	int _y;

public:
	int getX() { return _x; }
	int getY() { return _y; }
	void setPoint();
	void printPoint();
};

