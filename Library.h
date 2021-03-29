#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "User.h"
#include <vector>

class User;

class Library {
public:
	void loadBook();
	void loadUser();
	void addUser(User _user);
	vector<Book> BookArray;
	vector<User> UserArray;
	bool isExistedUsername(string _username);
	bool isExistedBook(string _bookID);

	 

	~Library();
};

#endif