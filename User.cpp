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
	cout << " ____________________________________________________________________________________________________________________________________" << endl;
	cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--------Category--------|--Price--|--Publication--|" << endl;
	for (size_t i = 0; i < lib.BookArray.size(); i++) {
		cout << "|" << setw(35) << lib.BookArray[i].getTitle() <<  "|" << setw(10) << lib.BookArray[i].getBookID() << "|" << setw(16)
		<< lib.BookArray[i].getAuthor() << "|" << setw(17) << lib.BookArray[i].getPublisher() << "|" << setw(24) << lib.BookArray[i].getCategory()
		<< "|" << setw(9) << lib.BookArray[i].getCost() << "|" 	<< setw(15) << lib.BookArray[i].getPublication() << "|" << endl;
	}
	cout << "======================================================================================================================================" << endl;
	
	system("pause");
}

void User::printUserList() {
	ofstream outFile("User.txt");
	if (!outFile) {
		cout << "UserList.txt can't open." << endl;
		Sleep(3000);
		return;
	}

	for (size_t i = 0; i < lib.UserArray.size(); i++) {
		outFile << lib.UserArray[i].getUsername() << " " << lib.UserArray[i].getPassword() << " " << lib.UserArray[i].getRole() << endl;
	}

	outFile.close();
}

void User::printBookList() {
	ofstream outFile("Book.txt");
	if (!outFile) {
		cout << "Book.txt can't open." << endl;
		Sleep(3000);
		return;
	}

	for (size_t i = 0; i < lib.BookArray.size(); i++) {
		outFile << lib.BookArray[i].getTitle() << endl;
		outFile << lib.BookArray[i].getBookID() << endl;
		outFile << lib.BookArray[i].getAuthor() << endl;
		outFile << lib.BookArray[i].getPublisher() << endl;
		outFile << lib.BookArray[i].getCategory() << endl;
		outFile << lib.BookArray[i].getCost() << endl;
		outFile << lib.BookArray[i].getPublication() << endl;

		if (i == lib.BookArray.size() - 1) {
			outFile << "END";
		}
		else
			outFile << endl;
	}
	cout << "Print book done!" << endl; Sleep(3000);
}

void User::changePsw(string _username) {
	cout << "Enter current password: " << endl;
	Password psw;
	psw.setPassword();

	for (size_t i = 0; i < lib.UserArray.size(); i++) {
		if (lib.UserArray[i].getUsername() == _username) {
			if (psw.getPassword() != lib.UserArray[i].getPassword()) {
				cout << "Wrong password. Exiting..";
				Sleep(2000);
				return;
			}
			cout << "\nEnter your new password: ";
			Password psw1;
			psw1.setPassword();

			cout << "\nEnter new password again: ";
			Password psw2;
			psw2.setPassword();

			if (psw1.getPassword() == psw2.getPassword()) {
				lib.UserArray[i].setPassword(psw1.getPassword());
			}
			else {
				cout << "\nIncorrect password. Exiting.." << endl;
				Sleep(2000);
			}

			break;
		}
		
	}

	
}


User::~User(){
	
	username = "";
	password = "";
	role = 0;
}