#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyDate
{
private:
	int _day;
	int _month;
	int _year;
	char* _note ;


 public:

	MyDate();
	MyDate(int day,int month, int year,const char* note);
	MyDate(MyDate &date);

	~MyDate();

	int getDay() { return this->_day; }
	int getMonth() { return this->_month; }
	int getYear() {return this->_year; }
	char* getNote() { return this->_note; }

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setNote(char* note);
	void setDate(int year, int month, int day );

	void inc();
	void init();
	bool isBefore (MyDate date);
	void changeComment( const char* note);
	void printDate();

	

};

