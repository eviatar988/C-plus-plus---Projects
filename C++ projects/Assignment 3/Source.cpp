#include "Complex.h"
#include <iostream>
#include <stdio.h>     
#include <math.h>



void main() {

	Complex c1; cout << "(defult constructor)"<<endl;//CREATING BY DEFUALT CONSTRUCTOR 
	c1.print();
	

	Complex c2(5, -2); cout << "(a,b constructor)" << endl;//CREATING BY INSET VALUE CONSTRUCTOR 
	c2.print();
	
	Complex c3(c2); cout << "(copy constructor)"<<endl;//CREATING BY COPY CONSTRUCTOR 
	c3.print();

	Complex c5(34, 7);
	
	Complex c4 = c3.add(c5); //c4=c3+c5 // realizing addition func
	c4.print();

	c4 = c5.sub(c2);//c4=c5-c2 // realizing subtruction func
	c4.print();
	
}