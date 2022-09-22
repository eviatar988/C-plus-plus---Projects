#pragma once
#include<string>
#include<iostream>
using namespace std;
class MyMatrix
{
private:
	int _m;
	int _n;
	double** matPtr=NULL;

public:
	
	int getN() const { return this->_n; }
	int getM() const { return this->_m; }
	MyMatrix(const MyMatrix& other);
	MyMatrix(int m, int n);
	MyMatrix();

	~MyMatrix();
	MyMatrix operator+( MyMatrix& other) ;
	MyMatrix operator-( MyMatrix& other);
	MyMatrix operator*( MyMatrix& other);
	MyMatrix operator*(int a);
    friend MyMatrix operator*(int a, MyMatrix& other);
	MyMatrix operator=(MyMatrix other);
	bool operator==( MyMatrix & other);
	friend ostream& operator<<(ostream& out,MyMatrix& other);
	friend istream& operator>>(istream& in,MyMatrix& other);
	double* operator[](int index);


};

