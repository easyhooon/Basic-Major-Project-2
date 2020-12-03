#pragma once

#include "Account.h"

class Administrator: public Account {
public :
	Administrator() : Account() {
		this->setAccountGrade(0);
	}

	Administrator(string name, string id, string pw, string email) : Account(name, id, pw, email) {
		this->setAccountGrade(0);
	}
};