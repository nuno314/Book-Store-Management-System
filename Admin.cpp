#include "Admin.h"

extern Library lib;
extern string username, password;

void Admin::updatePrice() {
	cout << "Enter book's ID: ";
	string _bookID;
	cin >> _bookID;

	for (size_t i = 0; i < lib.BookArray.size(); i++) {

		if (lib.BookArray[i].getBookID() == _bookID) {

			cout << "Current price: " << lib.BookArray[i].getCost() << endl;
			cout << "New price: ";
			int _price; cin >> _price;

			lib.BookArray[i].setCost(_price);
			printBookList();
			cout << "Update successfully! Back to menu.." << endl;
			Sleep(2000);
			break;
		}
	}

	cout << "No book ID found. Exiting..";
	Sleep(2000);
}

void Admin::delUser() {

	listUser();
	string _username;
	cout << "Enter username you want to delete: ";
	cin >> _username;

	for (int i = 0; i < lib.UserArray.size(); i++) {
		
		if (lib.UserArray[i].getUsername() == _username) {

			lib.UserArray.erase(lib.UserArray.begin() + i);
			printUserList();
			cout << "Deleted successfully. Exiting.." << endl;
			Sleep(2000);
			return;
		}
	}

	cout << "Username doesn't exist. Exiting..";
	Sleep(2000);
}

string Admin::getRoleName(int _role) {
	string roleName = "";

	switch (_role)
	{
	case 1:
		roleName = "Customer";
		break;
	case 2:
		roleName = "Staff";
		break;
	case 3:
		roleName = "Admin";
		break;
	default:
		roleName = "Undefined";
		break;
		
	}

	return roleName;
}

void Admin::listUser() {
	cout << "--------USER LIST--------" << endl;
	cout << "_________________________" << endl;
	cout << "|---Username---|--Role--|" << endl;

	for (int i = 0; i < lib.UserArray.size(); i++) {
		cout << "|" << setw(14) << lib.UserArray[i].getUsername() << "|" << setw(8) << getRoleName(lib.UserArray[i].getRole()) << "|" << endl;
	}

	cout << "=========================" << endl;
	system("pause");
}

void Admin::setStaff() {
	listUser();

	string _username;
	cout << "Enter username you want to set Staff: ";
	cin >> _username;

	for (int i = 0; i < lib.UserArray.size(); i++) {
		if (lib.UserArray[i].getUsername() == _username) {

			if (lib.UserArray[i].getRole() == 2) {
				cout << "Account is Staff already. Exiting..";
				Sleep(2000);
			}
			else {
				lib.UserArray[i].setRole(2);
				cout << "Set succesfully. Exiting..";
				Sleep(2000);
			}

			printUserList();
			return;
		}
	}


	cout << "Username doesn't exist. Exiting..";
	Sleep(2000);
	
}

void Admin::Interface(const string& username) {
	int choice;
	
	while (true) {

		system("cls");
		while (true){
			cout << "Welcome " << username << ". You are admin." << endl;
			cout << "1. List book" << endl;
			cout << "2. List user" << endl;
			cout << "3. Delete user" << endl;
			cout << "4. Set staff" << endl;
			cout << "5. Update price" << endl;
			cout << "6. Change password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			
			break;
		}

		switch (choice) {
		case 1: {
			listBook();
			break;
		}
		case 2: {
			listUser();
			break;
		}
		case 3: {
			delUser();
			break;
		}
		case 4: {
			setStaff();
			break;
		}
		case 5: {
			updatePrice();
			break;
		}
		case 6: {
			changePsw(username);
			break;
		}
		case 0: {
			cout << "Good bye. Exiting.." << endl;
			Sleep(2000);
			return;
		}
		}
	}
}



Admin::~Admin() {
	
}