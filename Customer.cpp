#include "Customer.h"

extern Library lib;
extern string account;

void Customer::buyBook() {
	string _bookID;

	system("cls");
	cout << "Enter book's ID: " << endl;
	cin >> _bookID;

	for (size_t i = 0; i < lib.Database.getCapacity(); i++) {
		if (_bookID == lib.Database.bookList[i].getBookID()) {
			cout << "Price: " << lib.Database.bookList[i].getCost() << endl;
			cout << "Would you like to buy: " << endl;
			cout << "1. YES" << endl;
			cout << "2. NO" << endl;
			int choice;
			while (true) {
				cin >> choice;
				if (choice < 0 || choice>2) {
					cout << "Invalid number. Please try again." << endl;
					continue;
				}
				break;
			}
			if (choice == 1) {
				cout << "Bought " << lib.Database.bookList[i].getTitle() << " succesfully." << endl;
			}
			
			cout << "Back to menu..." << endl;
			Sleep(1000);
		}
	}
}



void Customer::Interface(const string& username) {
	int choice = -1;	
	bool stop = false;
	while (true) {
		system("cls");
		cout << "Welcome " << username << ". You are a customer." << endl;
		cout << "Choose what you want to do by entering a number: " << endl;
		while (true) {
			cout << "1. Buy book" << endl;
			cout << "2. List book" << endl;
			cout << "3. Change password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			while (choice < 0 || choice>3) {
				cout << "Invalid number. Please try again~" << endl;
				cin >> choice;
			}
			break;
		}
		switch (choice)	{
		case 1: {
			buyBook();
			break;
		}
		case 2: {
			listBook();
			break;
		}
		case 3: {
		
			break;
		}
		default: {
			stop = true;
			cout << "See you next time.." << endl;
			Sleep(1000);
			break;
		}

		}
		if (stop) break;

	}

}