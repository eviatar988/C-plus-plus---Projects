#pragma once
#include<iostream>
using namespace std;
#define PI 3.14159265


class Complex
{
 private:

	int _x;
	int _y;

public:
	int getX() { return this->_x; }
	int getY() { return this->_y; }
	void set(int a, int b);

	double absComplex();
	double phase();

	Complex();
	Complex(const Complex& c);
	Complex(int a, int b);

	Complex add(Complex c1);
	Complex sub(Complex c1);
	void print();

		
};

