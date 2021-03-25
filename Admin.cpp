#include "Admin.h"

extern Library lib;
extern string username, password;

void Admin::updatePrice() {
	cout << "Enter book's ID: ";
	string _bookID;
	cin >> _bookID;

	for (size_t i = 0; i < lib.Database.getCapacity(); i++) {
		if (lib.Database.bookList[i].getBookID() == _bookID) {
			cout << "Current price: " << lib.Database.bookList[i].getCost() << endl;
			cout << "New price: ";
			int _price; cin >> _price;

			lib.Database.bookList[i].setCost(_price);
			break;
		}
	}

	cout << "Update successfully! Back to menu.." << endl;
	Sleep(2000);
}

void Admin::Interface(const string& username) {
	int choice;
	
	while (true) {
		system("cls");
		while (true){
			cout << "Welcome " << username << ". You are admin." << endl;
			cout << "1. Add book" << endl;
			cin >> choice;
			break;
		}

		switch (choice) {
		case 1: {
			addBook();
			break;
		}
		case 2: {
			listBook();
			break;
		}
		}
	}
}