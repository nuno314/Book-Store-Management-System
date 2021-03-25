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
	lib.Database.addBook(_book);
}