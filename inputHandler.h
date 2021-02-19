#pragma once
#include "book.h"
#include "bookDatabase.h"
#include "User.h"
#include <vector>

class Library {
public:
	void loadBook();
	void loadUser();
	vector<User> customer;
	BookDatabase Database;
};


