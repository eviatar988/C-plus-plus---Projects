#include "Point.h"
#include<iostream>;
using namespace std;

void Point::setPoint() {
	
	cout << "Enter New Point" << endl;
	cout << " X:" << endl;
	cin >> _x ;
	cout << " Y:" << endl;
	cin >> _y;
	
}


void Point::printPoint() {
	cout << " (" << getX() << "," << getY() << ")" << endl;
}