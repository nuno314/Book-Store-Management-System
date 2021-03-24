#ifndef USER_H
#define USER_H

#include "Library.h"
#include <conio.h>

class User {
private:
	string username,password;
	int role;
public:
	User();
	void setUser(const string& _username, const string& _password, const int& role);
	void setUsername(const string& _username);
	void setPassword(const string& _password);
	void setRole(const int& _role);

	string getUsername();
	string getPassword();
	string getHiddenPassword();

	int getRole();
	void listBook();
	void printUserList();
	void changePsw();

	~User();
};

#endif // !USER_H