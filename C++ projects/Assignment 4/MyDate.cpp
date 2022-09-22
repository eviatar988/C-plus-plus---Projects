#include "MyDate.h"
#include <stdio.h>

#include <string.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <iterator>
#pragma once

int arrMonth1[7] = { 1, 3, 5, 7, 8, 10, 12 };
int arrMonth2[4] = { 4, 6, 9, 11 };

using namespace std;

MyDate::MyDate() {
	this->_day = 1;
	this->_month = 1;
	this->_year = 2020;
}
MyDate::MyDate (int day, int month, int year,const char* note=NULL) {

	this->_day = day;
	this->_month = month;
	this->_year = year;
	this->_note = new char[strlen(note) + 1];
	strcpy_s(this->_note, strlen(note) + 1, note);
}
MyDate::MyDate(MyDate& date) {
	this->_day = date.getDay();
	this->_month = date.getMonth();
	this->_year = date.getYear();
	this->_note = new char[strlen(date._note)];
	strcpy_s(this->_note, strlen(date._note), date._note);


}
MyDate::~MyDate() {
	if(this->_note != NULL)
	this->_note = NULL;
	delete[] this->_note;
}

void MyDate::setDay(int day) {

	if (day < 1 || day>31) {
		cout << "Invalide Day Initialized To 1" << endl;
		this->_day = 1;
		return;
	}
	if (day > 28 && this->getMonth() == 2)
	{
		cout << "Invalide Day Initialized To 1" << endl;
		this->_day = 1;
		return;
	}
	if (day > 30) {
		bool exist = find(begin(arrMonth2), end(arrMonth2), this->getMonth());
		if (exist)
		{
			cout << "Invalide Day Initialized To 1" << endl;
			this->_day = 1;
			return;
		}
	}
	this->_day = day;
}
void MyDate::setMonth(int month) {
	if (month < 1 || month>12)
	{
		cout << "Invalide Month Initialized To 1" << endl;
		this->_month = 1;
		return;
	}
	if (month == 2 && this->_day>>28)
	{
		cout << "Invalide Month Initialized To 1" << endl;
		this->_month = 1;
		return;
	}
	if ((month == 4 || month == 6|| month == 9|| month == 11) && this->_day==31)
	{
		cout << "Invalide Month Initialized To 1" << endl;
		this->_month = 1;
		return;
	}
	this->_month = month;
}
void MyDate::setYear(int year) {
	if (year < 0) {
		cout << "invalid Year Initialized To 1" << endl;
		this->_year = 1;
	}
	this->_year = year;
}
void MyDate::setNote(char* note) {
	this->_note = note;
}
void MyDate::setDate(int year, int month, int day){
	setDay(day);
	setMonth(month);
	setYear(year);
}	
void MyDate::inc() {
	int newDay = getDay() + 1;
		if (getMonth() == 2 && newDay > 28) {
			setDay(1);
			setMonth(3);
		}
		if ((getMonth() == 4|| getMonth() == 6 || getMonth() == 9 || getMonth() == 11)  &&  newDay >30) {
			setDay(1);
			setMonth(getMonth()+1);
		}
		if (getMonth() == 12 && newDay > 31) {
			setDay(1);
			setMonth(1);
			setYear(getYear() + 1);
		}
		if ((getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 || getMonth() == 8 || getMonth() == 10|| getMonth() == 12) && newDay > 31) 
			{
				setDay(1);
				setMonth(1);
				setYear(getYear() + 1);
			}

		else
			this->_day = newDay;

		cout << "(day is inc)" << endl;
		
}; 
void MyDate::init() {
	this->_day = 26;
	this->_month = 12;
	this->_year = 2021;
	cout << "(init func has Realized)" << endl;
}
void MyDate::changeComment(const char* note=NULL) {
	//for (int i = 0; i < strlen(note); i++)
		//this->_note[i] = note[i];
	if (note == NULL)
	{
		this->_note = NULL;
		return;
	}
	if (note != NULL)
	{
		this->_note = NULL;
		delete[] this->_note;
	}
	this->_note = new char[strlen(note)];
		strcpy_s(this->_note, strlen(this->_note+1), note);
		cout << "(comment changed)" << endl;
}
void MyDate::printDate() {
	if (this->getDay() < 10)
		cout << "0";

		cout << this->getDay()<<"/";

	if (this->getMonth() < 10)
			cout << "0";

		cout << this->getMonth() << "/";

		cout << this->getYear();

		cout << "  Note:";
		if (this->_note == NULL) {
			cout << endl;
			return;
		}
		if (this->_note != NULL) {
			for (int i = 0; i < strlen(this->_note); i++)
				cout << this->_note[i];
		}
		cout <<endl;
}

