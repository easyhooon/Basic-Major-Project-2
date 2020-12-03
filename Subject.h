#pragma once
#include<iostream>
#include<string>

using namespace std;

class Subject {
private:
	string subName;
	int subNum;
	int subCredit;
	int subLimit;
	string subDay, subDay2;
	int subStart, subStart2;
	int subFinish, subFinish2;
	string subRoom, subRoom2;
public:
	Subject() {

	}

	Subject(string subName, int subNum, int subCredit, int subLimit, string subDay, int subStart, int subFinish, string subRoom) {
		this->subName = subName;
		this->subNum = subNum;
		this->subDay = subDay;
		this->subStart = subStart;
		this->subFinish = subFinish;
		this->subRoom = subRoom;
		this->subCredit = subCredit;
		this->subLimit = subLimit;
	}

	Subject(string subName, int subNum, int subCredit, int subLimit, string subDay, int subStart, int subFinish, string subRoom,
		string subDay2, int subStart2, int subFinish2, string subRoom2) {
		this->subName = subName;
		this->subNum = subNum;
		this->subDay = subDay;
		this->subStart = subStart;
		this->subFinish = subFinish;
		this->subRoom = subRoom;
		this->subDay2 = subDay2;
		this->subStart2 = subStart2;
		this->subFinish2 = subFinish2;
		this->subRoom2 = subRoom2;
		this->subCredit = subCredit;
		this->subLimit = subLimit;
	}

	void setSubName(string name) {
		this->subName = name;
	}

	string getSubName() {
		return this->subName;
	}

	void setSubNum(int num) {
		this->subNum = num;
	}

	int getSubNum() {
		return this->subNum;
	}

	void setSubDay(string day) {
		this->subDay = day;
	}

	string getSubDay() {
		return this->subDay;
	}

	void setSubDay2(string day2) {
		this->subDay2 = day2;
	}

	string getSubDay2() {
		return this->subDay2;
	}

	void setSubStart(int start) {
		this->subStart = start;
	}

	int getSubStart() {
		return this->subStart;
	}

	void setSubStart2(int start2) {
		this->subStart2 = start2;
	}

	int getSubStart2() {
		return this->subStart2;
	}

	void setSubFinsh(int finish) {
		this->subFinish = finish;
	}

	int getSubFinish() {
		return this->subFinish;
	}

	void setSubFinsh2(int finish2) {
		this->subFinish2 = finish2;
	}

	int getSubFinish2() {
		return this->subFinish2;
	}

	void setSubRoom(string room) {
		this->subRoom = room;
	}

	string getSubRoom() {
		return this->subRoom;
	}

	void setSubRoom2(string room2) {
		this->subRoom2 = room2;
	}

	string getSubRoom2() {
		return this->subRoom2;
	}

	void setSubCredit(int credit) {
		this->subCredit = credit;
	}

	int getSubCredit() {
		return this->subCredit;
	}

	void setSubTime(int start, int finish) {
		this->subStart = start;
		this->subFinish = finish;
	}

	void setSubTime(int start, int finish, int start2, int finish2) {
		this->subStart = start;
		this->subFinish = finish;
		this->subStart2 = start2;
		this->subFinish = finish2;
	}

	int getSubLimit() {
		return this->subLimit;
	}
	void setSubLimit(int subLimit) {
		this->subLimit = subLimit;
	}
};


