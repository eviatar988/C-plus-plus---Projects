#include "Calander.h"
#include "MyDate.h"
#include <iostream>
#include <string>

using namespace std;

 Calander:: Calander(){
	 for (int i = 0; i < 30; i++)
		 this->_days[i] = NULL;
	 this->_busy = 0;
 }
 Calander:: Calander(Calander& days){
	 for (int i = 0; i < 30; i++)
		 this->_days[i] = days._days[i];
	 this->_busy = days._busy;
 }
 Calander:: ~Calander(){};

void Calander::setDate(int num, MyDate &day){
	this->_days[num] = &day;
	cout << "(setDate func)" << endl;
}
bool Calander::isFree(int num) {
	cout << "(isFree func)" << endl;

	if (this->_days[num] == NULL) {
		cout << "day " <<num<<" is free" << endl;
		return true;
		cout << "day " <<num<< " is busy" << endl;
		return false;
	}
}
bool Calander::firstFree(){
	cout << "(firstFree func)" << endl;
	for (int i = 0; i < 30; i++) {
		if (this->_days[i] == NULL) {
			cout << "the first free day is :"<<i +1<< endl;
			return i;
		}
	}
	cout << "ther is no free days" << endl;
	return false;
}
bool Calander::Insert(MyDate day){
	cout << "(Insert func)" << endl;

	if (firstFree()) {
		this->_days[firstFree()] = &day;
		return true;
	}
	return false;
}
int Calander::oldest(){
	cout << "(oldest func)" << endl;

	int oldestPlace=0;

	for (int i = 0; i < 30; i++) {
		if (this->_days[i] != NULL) {


			if (this->_days[i]->getYear() < this->_days[oldestPlace]->getYear())//בדיקת שנה 
				oldestPlace = i;

			if (this->_days[i]->getYear() == this->_days[oldestPlace]->getYear()) {//בדיקת שנה וחודש 
				if(this->_days[i]->getMonth() < this->_days[oldestPlace]->getMonth())
					oldestPlace = i;
			}

			if ((this->_days[i]->getYear() == this->_days[oldestPlace]->getYear()) && (this->_days[i]->getMonth() == this->_days[oldestPlace]->getMonth())) {//בדיקת שנה חודש ויום 
				if (this->_days[i]->getDay() < this->_days[oldestPlace]->getDay())
					oldestPlace = i;
			}
		}
	}
	return oldestPlace;
}
int Calander::datesNum(){
	cout << "(datesNum func)" << endl;

	int count = 0;
	for (int i = 0; i < 30; i++) {
		if (this->_days[i] != NULL)
			count++;
	}
	cout << "datesNum:" <<count<< endl;
	return count;
}
void Calander::deleteALL(){
	cout << "(deleteALL func)" << endl;

	for (int i = 0; i < 30; i++) {
		this->_days[i] = NULL;
		delete[] _days[i];
	}
}
void Calander::Delete(int num){
	cout << "(Delete func)" << endl;

	if (this->_days[num] != NULL) {
		this->_days[num] = NULL;
		delete[] _days[num];
	}
}
void Calander::print() {
	for (int i = 0; i < 30; i++) {
		if (this->_days[i] != NULL) {
			cout << "days[" << i << "]: ";
			this->_days[i]->printDate();
		}
	}
}

