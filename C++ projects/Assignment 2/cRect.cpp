#include "cRect.h"
#include<iostream>;
using namespace std;

Point cRect::get(int num){

	cout << "The Point Is:" << endl;

	if (num == 0) {
		_p0.printPoint();
		return(_p0);
	}
	if (num == 1) {
		_p1.printPoint();
		return(_p1);
	}
	if (num == 2) {
		_p2.printPoint();
		return(_p2);
	}
	if (num == 3) {
		_p3.printPoint();
		return(_p3);
	}


}

void cRect::set(int num,Point p)
{
	if (num == 0)
		_p0 = p;
	if (num == 1)
		_p1 = p;
	if (num == 2)
		_p2 = p;
	if (num == 3)
		_p3 = p;
}
void cRect::printRect()
{
	

	cout << "The Rectangle Is:" << endl;
	_p0.printPoint();
	_p1.printPoint();
	_p2.printPoint();
	_p3.printPoint();


}
int cRect::calcArea()
{
	
	int side1, side2, area;

	side1 = abs(_p0.getX() - _p1.getX());
	side2 = abs(_p0.getY() - _p3.getY());

	area = side1 * side1;

	cout << "The ariea is:" << area << endl;
	return(area);
};
