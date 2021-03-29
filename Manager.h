#pragma once
#include "book.h"
#include "Library.h"
#include "Customer.h"
#include "User.h"

class Manager {
public:
	Library lib;
	string username, password;
	User guess;
	void loadBook();
	void loadUser();
	void addUser();
};