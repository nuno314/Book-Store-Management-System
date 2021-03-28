#include "Customer.h"

extern Library lib;
extern string account;

void Customer::buyBook() {
	string _bookID;

	system("cls");
	cout << "Enter book's ID: " << endl;
	cin >> _bookID;

	for (size_t i = 0; i < lib.BookArray.size(); i++) {
		if (_bookID == lib.BookArray[i].getBookID()) {
			cout << "Price: " << lib.BookArray[i].getCost() << endl;
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
				cout << "Bought " << lib.BookArray[i].getTitle() << " succesfully." << endl;
			}
			
			cout << "Back to menu..." << endl;
			
			Sleep(1000);
			return;
		}


	}

	cout << "No book's ID found." << endl;
	cout << "Back to menu.." << endl;
	Sleep(2000);
}



void Customer::Interface(const string& _username) {
	int choice = -1;	
	setUsername(_username);
	
	bool stop = false;
	while (true) {
		system("cls");
		cout << "Welcome " << _username << ". You are a customer." << endl;
		cout << "Choose what you want to do by entering a number: " << endl;
		while (true) {
			cout << "1. Buy book" << endl;
			cout << "2. List book" << endl;
			cout << "3. Search book by Author" << endl;
			cout << "4. Search book by Publisher" << endl;
			cout << "5. Search book by Publication" << endl;
			cout << ". Change password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			while (choice < 0 || choice>5) {
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
			searchByAuthor();
			break;
		}
		case 4: {
			searchByPublisher();
			break;
		}
		case 5: {
			searchByPublication();
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
//void Customer::sortBookByCategory() {
//	
//
//	bool* check = new bool[used];
//	for (int i = 0; i < used; i++) {
//		check[i] = false;
//	}
//
//	int count = 0;
//	string _category = lib.lib.BookArray[0].getCategory();
//
//	while (count < used) {
//		string tmp = _category;
//		for (int i = 0; i < used; i++) {
//			if (lib.BookArray[i].getCategory() == _category) {
//				sorted[count] = lib.BookArray[i];
//				check[i] = true;
//				count++;
//			}
//			else if (check[i] == false) {
//				tmp = lib.BookArray[i].getCategory();
//			}
//		}
//		if (count < used) {
//			if (tmp != _category)
//				_category = tmp;
//		}
//	}
//
//	delete[] lib.BookArray;
//	lib.BookArray = sorted;
//}


void Customer::searchByAuthor() {
	cout << "Enter author name: ";
	string _author;
	cin.ignore();
	getline(cin, _author);

	bool existed = false;

	for (size_t i = 0; i < lib.BookArray.size(); i++) {

		if (lib.BookArray[i].getAuthor() == _author) {

			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << lib.BookArray[i].getTitle() << "|" << setw(10) << lib.BookArray[i].getBookID() << "|" << setw(16)
				<< lib.BookArray[i].getAuthor() << "|" << setw(17) << lib.BookArray[i].getPublisher() << "|" << setw(12) << lib.BookArray[i].getCategory()
				<< "|" << setw(9) << lib.BookArray[i].getCost() << "|" << setw(15) << lib.BookArray[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");
}

void Customer::searchByPublisher() {
	cout << "Enter publisher name: ";
	string _publisher;
	cin.ignore();
	getline(cin, _publisher);

	bool existed = false;

	for (size_t i = 0; i <lib.BookArray.size(); i++) {

		if (lib.BookArray[i].getPublisher() == _publisher) {

			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << lib.BookArray[i].getTitle() << "|" << setw(10) << lib.BookArray[i].getBookID() << "|" << setw(16)
				<< lib.BookArray[i].getAuthor() << "|" << setw(17) << lib.BookArray[i].getPublisher() << "|" << setw(12) << lib.BookArray[i].getCategory()
				<< "|" << setw(9) << lib.BookArray[i].getCost() << "|" << setw(15) << lib.BookArray[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");

}

void Customer::searchByPublication() {
	cout << "Enter publication year: ";
	int _publication;
	cin >> _publication;
	bool existed = false;

	for (size_t i = 0; i < lib.BookArray.size(); i++) {

		if (lib.BookArray[i].getPublication() == _publication) {

			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << lib.BookArray[i].getTitle() << "|" << setw(10) << lib.BookArray[i].getBookID() << "|" << setw(16)
				<< lib.BookArray[i].getAuthor() << "|" << setw(17) << lib.BookArray[i].getPublisher() << "|" << setw(12) << lib.BookArray[i].getCategory()
				<< "|" << setw(9) << lib.BookArray[i].getCost() << "|" << setw(15) << lib.BookArray[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");
}

Customer::~Customer() {
	printBookList();
	printUserList();

}