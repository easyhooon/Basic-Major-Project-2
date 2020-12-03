#pragma once
#include <iostream>

#include "Account.h"
#include "Subject.h"
class TimeTable;

using namespace std;

class Student: public Account{
private:
	TimeTable* timeTable;
	int subjectList[10];
public:
	Student(): Account() {
		this->setAccountGrade(1);
	}

	Student(string name, string id, string pw, string email): Account(name, id, pw, email) {
		this->setAccountGrade(1);
	}
	TimeTable* getTimeTable() {
		return this->timeTable;
	}
	void setTimeTable(TimeTable* timeTable) {
		this->timeTable = timeTable;
	}
	int* getSubjectList() {
		return this->subjectList;
	}
	void setSubjectList(int subjectNum[]) {
		
	}
};
