#pragma once
#include "User.h"

class Staff : public User {
public:
	void addBook();
	void delBook();
	void Interface(string username);
	void updateInfoBook();
	~Staff();
};
