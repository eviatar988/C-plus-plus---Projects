#include "MyMatrix.h"
#include<string>
#include<iostream>

using namespace std;

void main() {
	MyMatrix mat1;

	cin >> mat1;
	cout<<mat1;
	cout << "mult' by 2" << endl;
	mat1 = mat1 * 2;
	cout << mat1;
	cout << "mult' by 2";

	mat1 = 2 * mat1;
	cout << mat1;
	MyMatrix mat2(mat1), mat3,mat4;
	mat3 = mat1 + mat2;
	mat4 = mat3 * mat3;

	MyMatrix mat5(6, 7);
	cout << "Unmatch Mtrices" << endl;

	mat4 = mat5 + mat3;
	


}