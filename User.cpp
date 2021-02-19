#include "User.h"
#include "inputHandler.h"

extern Library lib;
extern string username, password;

User::User() {
	username = "";
	password = "";
	role = 0;
}

void User::setUser(const string& _username, const string& _password, const int& _role) {
	this->username = _username;
	this->password = _password;
	this->role = _role;
}

void User::setUsername(const string& _username) {
	this->username = _username;
}

void User::setPassword(const string& _Password) {
	this->password = _Password;
}

void User::setRole(const int& _Role) {
	this->role = _Role;
}

string User::getUsername() {
	return this->username;
}

string User::getPassword() {
	return this->password;
}

int User::getRole() {
	return this->role;
}

void User::printListBook() {
	ofstream outFile;
	outFile.open("Book.txt"); // Open and write Book.txt
	if (!outFile) {
		cout << "Book.txt can't open." << endl;
		return;
	}

	for (size_t i = 0; i < lib.Database.getCapacity(); i++) {
		outFile << lib.Database.bookList[i].getTitle();
	}

	outFile.close();
}

User::~User(){
	username = "";
	password = "";
	role = 0;
}