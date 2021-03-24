#include "User.h"
#include "Library.h"


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

void User::listBook() {
	cout << "-----BOOK LIST-----" << endl;
	cout << "__________________________________________________________________________________________________________________________" << endl;
	cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
	for (size_t i = 0; i < lib.Database.getCapacity(); i++) {
		cout << "|" << setw(35) << lib.Database.bookList[i].getTitle() <<  "|" << setw(10) << lib.Database.bookList[i].getBookID() << "|" << setw(16) << lib.Database.bookList[i].getAuthor() << "|" 
		<< setw(17) << lib.Database.bookList[i].getPublisher() << "|" << setw(12) << lib.Database.bookList[i].getCategory() << "|" << setw(9) << lib.Database.bookList[i].getCost() << "|" << setw(15) << lib.Database.bookList[i].getPublication() << "|" << endl;
	}
	cout << "==========================================================================================================================" << endl;
	
	system("pause");
}

void User::printUserList() {
	ofstream outFile("UserList.txt");
	if (!outFile) {
		cout << "UserList.txt can't open." << endl;
		return;
	}

	for (size_t i = 0; i < lib.UserArray.size(); i++) {
		outFile << lib.UserArray[i].getUsername() << " " << lib.UserArray[i].getPassword() << " " << lib.UserArray[i].getRole() << endl;
	}

	outFile.close();
}

void User::changePsw() {
	cout << "Enter current password: " << endl;
	string _password;
	cin >> _password;

	if (this->getPassword() == _password) {
		cout << "Enter your new password: "; 
	}
}

string User::getHiddenPassword() {
	int passwordSize = 10;
	char* s = new char[passwordSize];
	int i = 0;
	for (i = 0; i < passwordSize; i++) {
		s[i] = _getch(); _putch('*');

		if (s[i] == 13) break; // 13 = Enter
	};
	
	string _password;
	for (int i = 0; i < passwordSize; i++) {
		if (s[i] != '\r')
			_password += s[i];
		else break;
	}

	return _password;
}

User::~User(){
	username = "";
	password = "";
	role = 0;
	printUserList();
}