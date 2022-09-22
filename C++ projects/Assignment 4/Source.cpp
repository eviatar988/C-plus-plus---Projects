#include "MyDate.h"
#include "Calander.h"
#include <iostream>
#include <string>
#include <algorithm> 
#include <iterator>
#pragma once

void main() {

	MyDate d1;
	d1.printDate();
	MyDate d2(4, 3, 2030, "new event");
	d2.printDate();
	d2.changeComment("new day");
	d2.printDate();
	d1.setDate(2022, 3, 19);
	d1.changeComment("father bithday");
	d1.printDate();
	d1.inc();
	d1.printDate();
	MyDate d4(6, 5, 1995, "ABCABC");
	d4.printDate();
	MyDate d5(7, 3, 2021, "XYZYXZ");
	MyDate d6(12, 3, 2022, "MNLMNL");
	Calander cal1;
	cal1.setDate(20, d1);
	cal1.setDate(6, d4);
	cal1.setDate(7, d5);
	cal1.setDate(12, d6);
	cal1.print();
	cal1.isFree(3);
	cal1.isFree(2);
	cal1.Delete(11);
	cout << "dateNum:" << cal1.datesNum() << endl;
	cal1.firstFree();
	cal1.oldest();
	cal1.deleteALL();

}