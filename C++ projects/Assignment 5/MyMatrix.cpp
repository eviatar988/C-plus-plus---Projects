#pragma once

#include "MyMatrix.h"
#include<string>
#include<iostream>
using namespace std;



MyMatrix::MyMatrix(const MyMatrix& other) {
	//cout << "(copy constructor)" << endl;
	this->_n = other.getN();
	this->_m = other.getM();
	this->matPtr = new double* [other.getM()];

	for (int i = 0; i < other.getM(); i++)
		matPtr[i] = new double[other.getN()];

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++)
			this->matPtr[j][k] = other.matPtr[j][k];
	}


}
MyMatrix::MyMatrix(int m, int n) {
	//cout << "(by value constructor)" << endl;

	this->_n = n;
	this->_m = m;

	this->matPtr = new double* [m];

		for (int i = 0; i < m; i++) {
			matPtr[i] = new double[n];
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++)
				this->matPtr[j][k] = 0;
		}
		
}
MyMatrix::MyMatrix() {
	//cout << "(defult constructor)" << endl;

	this->_n = 3;
	this->_m = 3;

	this->matPtr = new double* [3];

	for (int i = 0; i < 3; i++) {
		matPtr[i] = new double[3];
	}

	for (int k = 0; k < 3; k++) {
		for (int l = 0; l < 3; l++)
			matPtr[k][l] = 0;
	}
}
MyMatrix::~MyMatrix() {
	//cout << "(defult constructor)" << endl;

	for (int k = 0; k < this->getM(); k++) {
		delete[] this->matPtr[k];
		this->matPtr[k] = NULL;
	}
		delete[] this->matPtr;
		this->matPtr = NULL;

	
}

MyMatrix MyMatrix::operator+( MyMatrix& other){
	cout << "(+ operator)" << endl;
	try {
		if (other.getM() != this->getM() || other.getN() != this->getN())
			throw 1;
	}
	catch (int num) {
		if (num == 1)
			cout << " Different Sizes Matrices" << endl;
		
	}
	MyMatrix result(other.getM(), other.getN());

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++)
			result[j][k] = (*this)[j][k] +  other[j][k];
	}
	return result;
}
MyMatrix MyMatrix::operator-( MyMatrix& other){
	cout << "(- operator)" << endl;

	MyMatrix result(other.getM(), other.getN());

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++)
			result[j][k] = (*this)[j][k] - other[j][k];
	}
	return result;
}
MyMatrix MyMatrix::operator*( MyMatrix& other) {
	cout << "(matrix * matrix operator)" << endl;

	MyMatrix result(other.getM(), other.getN());

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++)
			result[j][k] = (*this)[j][k] * other[j][k];
	}
	return result;
}
MyMatrix MyMatrix::operator*(int a){
	cout << "(matrix * int operator)" << endl;

	cout << "(+ operator)" << endl;


	for (int j = 0; j < this->getM(); j++) {
		for (int k = 0; k < this->getN(); k++)
			(*this)[j][k] = (*this)[j][k] * a;
	}
	return *this;
}
MyMatrix operator*(int a, MyMatrix& other) {
	cout << "(int * matrix operator)" << endl;

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k <other.getN(); k++)
			other[j][k] =other[j][k] * a;
	}
	return other;
}
MyMatrix MyMatrix::operator=(MyMatrix other) {
	cout << "(= operator)" << endl;


	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++)
			(*this)[j][k] = other[j][k];
	}
	return (*this);
}
bool MyMatrix :: operator ==(MyMatrix& other){
	cout << "(== operator)" << endl;

	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++) {
			if ((*this)[j][k] != other[j][k])
				return false;
		}
	}
	return true;
}
ostream& operator<<(ostream& out, MyMatrix& other){
	cout << "(<< operator)" << endl;

	out << "The Matrix Is:"<<endl;
	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++) {
			out<<other[j][k];
		}
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, MyMatrix& other) {
	cout << "(>> operator)" << endl;

	cout << "Insert Matrix Values (" << other.getM() << "," << other.getN()<<") :" << endl;
	for (int j = 0; j < other.getM(); j++) {
		for (int k = 0; k < other.getN(); k++) {
			cout << "("<< j<<","<<k<<") :" ;
			in >> other[j][k];
		}
		cout << endl;
	}
	return in;

}
double* MyMatrix:: operator[](int index) {
	return matPtr[index];
}



