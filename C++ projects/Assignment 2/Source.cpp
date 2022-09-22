#include "Point.h"
#include "cRect.h"
#include<iostream>

using namespace std;

void main() {

	Point p0, p1, p2, p3, pNum;
	cRect rect;
	int number;
	cout << "Left-Up Corner" << endl;
	p0.setPoint();
	cout << "Right-Up Corner" << endl;
	p1.setPoint();
	cout << "Right-Douwn Corner" << endl;
	p2.setPoint();
	cout << "Left-Douwn Corner" << endl;

	p3.setPoint();

	rect.set(0, p0);
	rect.set(1, p1);
	rect.set(2, p2);
	rect.set(3, p3);

	rect.printRect();
	rect.calcArea();

	cout << "Enter Number:" << endl;
	cin>>number;
	pNum = rect.get(number);

	
}
