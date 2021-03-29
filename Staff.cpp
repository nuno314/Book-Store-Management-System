#include "Staff.h"

extern Library lib;
extern string username, password;

void Staff::addBook() {
	string _title, _bookID, _author, _publisher, _category;
	int _price, _publication;

	cout << "Enter new book information:" << endl;
	cout << "\tTitle: "; cin >> _title;
	cout << "\tBook's ID: "; cin >> _bookID;
	cout << "\tAuthor: "; cin >> _author;
	cout << "\tPublisher: "; cin >> _publisher;
	cout << "\tCategory: "; cin >> _category;
	cout << "\tPrice: "; cin >> _price;
	cout << "\tPublication year: "; cin >> _publication;
	
	Book _book;
	_book.setBook(_title, _bookID, _publisher, _author, _category, _price, _publication);
	lib.BookArray.push_back(_book);
}

void Staff::delBook() {
	cout << "Enter book's ID you want to delete: ";
	string _bookID;
	cin >> _bookID;
	
	for (int i = 0; i < lib.BookArray.size(); i++) {
		if (lib.BookArray[i].getBookID() == _bookID) {
			lib.BookArray.erase(lib.BookArray.begin() + i);
			cout << "Deleted. Exiting..";
			Sleep(2000);
			return;
		}
	}

	cout << "No ID found. Exiting.." << endl;
	Sleep(2000);

}

void Staff::Interface(string username) {
	int choice = -1;
	bool stop = false;
	while (true) {
		system("cls");
		cout << "Welcome " << username << ". You are a Staff." << endl;
		cout << "Choose what you want to do by entering a number: " << endl;
		while (true) {
			cout << "1. List book" << endl;
			cout << "2. Add book" << endl;
			cout << "3. Remove book" << endl;
			cout << "4. Change password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			while (choice < 0 || choice>4) {
				cout << "Invalid number. Please try again~" << endl;
				cin >> choice;
			}
			break;
		}
		switch (choice) {
		case 1: {
			listBook();
			break;
		}
		case 2: {
			addBook();
			break;
		}
		case 3: {
			delBook();
			break;
		}
		case 4: {
			changePsw(username);
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

Staff::~Staff() {
	printBookList();
	printUserList();
}


