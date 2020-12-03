#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
	string name;
	string id;
	string pw;
	string email;
	int accountGrade;
public:
	Account() {

	}

	Account(string name, string id, string pw, string email) {
		this->name = name;
		this->id = id;
		this->pw = pw;
		this->email = email;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setId(string id) {
		this->id = id;
	}
	string getId() {
		return id;
	}
	void setPW(string pw) {
		this->pw = pw;
	}
	string getPW() {
		return pw;
	}
	void setEmail(string email) {
		this->email = email;
	}
	string getEmail() {
		return email;
	}
	void setAccountGrade(int grade) {
		this->accountGrade = grade;
	}
	int getAccountGrade() {
		return this->accountGrade;
	}
};