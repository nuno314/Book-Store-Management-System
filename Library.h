#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "bookDatabase.h"
#include "User.h"
#include <vector>

class User;

class Library {
public:
	void loadBook();
	void loadUser();
	void addUser(User _user);
	BookDatabase Database;
	vector<User> UserArray;
};

#endif