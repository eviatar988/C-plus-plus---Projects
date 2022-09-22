#include "Complex.h"
#include<iostream>
#include <stdio.h>     
#include <math.h>

using namespace std;


double Complex::absComplex () { //absulout value func
	

	double abs = sqrt(pow(this->getX(), 2) + pow(this->getY(),2));
	return abs;
};


double Complex::phase() {//phase func

	double phase;

	if (this->getX() == 0 && this->getY() == 0)
		return (0.000);

	phase = atan2(this->getY(), this->getX()) * (180 / PI);
	return(phase);
}


void Complex::set(int a, int b) {//set func
	this->_x = a;
	this->_y = b;
}




Complex Complex::add(Complex c1){// add func
	cout << "(addition)" << endl;
	Complex c2;
	c2._x = _x + c1._x;
	c2._y = _y + c1._y;
	return c2;
}

Complex Complex::sub(Complex c1) {//sub func
	cout << "(substuct)" << endl;

	Complex c2;
	c2._x = _x - c1._x;
	c2._y = _y - c1._y;
	return c2;
}




Complex::Complex() { //defulte constructor 

	_x = 0;
	_y = 0;
}
Complex::Complex(const Complex& c) {//CC 
	this->_x = c._x;
	this->_y = c._y;

}
Complex::Complex(int a, int b) {//CONTRUCTOR BY VALUE
	this->_x = a;
	this->_y = b;
}

void Complex::print() { // PRINT COMPLEX
	cout << "The number is:" << this->getX() << " + i" << this->getY() << "  (" << this->absComplex() << "," << this->phase() << ")" << endl;
	double phaze();
}
