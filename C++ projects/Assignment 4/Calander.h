#pragma once
#include "MyDate.h"
#include <iostream>
#include <string>
using namespace std;

class Calander
{
private:
	MyDate * _days[30];
	int _busy;

public:
	Calander();
	Calander(Calander &days);
	~Calander();

	void setDate(int num, MyDate &day);
	bool isFree(int num);
	bool firstFree();
	bool Insert(MyDate day);
	int oldest();
	int datesNum();
	void deleteALL();
	void Delete(int num);
	void print();
};

