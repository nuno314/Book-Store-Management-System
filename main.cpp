#include "book.h"
#include "bookDatabase.h"
#include "Library.h"
#include "Customer.h"
#include <Windows.h>
#include "Manager.h"
#include "Admin.h"

Library lib;
string username, password;
User guess;

int Login(string username, string password) {
	for (size_t i = 0; i < lib.UserArray.size(); i++) {
		if (username == lib.UserArray[i].getUsername()) {
			if (password == lib.UserArray[i].getPassword())
				return lib.UserArray[i].getRole();
			return -1;
		}
	}

	return 0; // No username found
}

void loadData() {
	lib.loadBook();
	lib.loadUser();
}

void Session() {
	system("cls");
	int role = 0;
	int time = 0;
	cout << "Welcome To The Book Store Management System." << endl;
	cout << "Please log in first--" << endl;
	
	while (role == 0) {
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		password = guess.getHiddenPassword();

		role = Login(username, password);

		if (role == 0) {

			cout << "The username is incorrect." << endl;
			cout << "Sign up for a new account? " << endl;
			cout << "1. Yes " << endl;
			cout << "2. No..."  ;
			int choice;
			cin >> choice;

			if (choice == 1) {

				cout << "Username: ";
				cin >> username;
				guess.setUsername(username);

				if (lib.isExistedUsername(username)) {
					cout << "Username existed. Try again.." << endl;
					continue;
				}

				cout << "Password: ";
				cin >> password;
				guess.setPassword(password);

				guess.setRole(1);

				lib.addUser(guess);
			}
			else continue;
		}
		else while (role == -1) {
			time++;
			if (time >= 5) {
				cout << "Incorrect password. Exiting..." << endl;
				return;
			}
			cout << "\nThe password is incorrect. Try again.." << endl;
			cout << "You have " << 5 - time << " chance(s) left." << endl;
			cout << "Password: ";
			password = guess.getHiddenPassword();
			role = Login(username, password);
		}
	}

	switch (role)
	{
	case 1: {
		Customer person;
		person.Interface(username);
		break;
	}
	case 2: {
		Admin person;
		person.Interface(username);
		break;
	}
	default:
		break;
	}
}

int main() {
	
	loadData();
	Session();
	// 17.2 done input handler.
}