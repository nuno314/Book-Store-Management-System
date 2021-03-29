#pragma once
#include "book.h" 
#include "Library.h";
#include "User.h";
#include "Staff.h"

class Admin : public Staff {

public:
	void Interface(const string& username);
	void updatePrice();
	void delUser();
	void setStaff();
	void listUser();
	string getRoleName(int _role);
	~Admin();
};