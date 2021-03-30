#ifndef USER_H
#define USER_H

#include "Library.h"
#include <conio.h>
#include "Password.h"

class User {
private:
	string username,password;
	int role; // 2 for Administrator, 1 for Customer, 0 for Not exist, 
public:
	User();
	void setUser(const string& _username, const string& _password, const int& role);
	void setUsername(const string& _username);
	void setPassword(const string& _password);
	void setRole(const int& _role);

	string getUsername();
	string getPassword();

	int getRole();
	void listBook();
	void printUserList();
	void printBookList();
	


	void changePsw(string _username);

	//virtual void Interface(const string& username);

	~User();
};

#endif // !USER_H