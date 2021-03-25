#include "book.h"
#include "bookDatabase.h"

BookDatabase::BookDatabase() {
	capacity = 1;
	bookList = new Book[capacity];
	used = 0;
}

void BookDatabase::expandDatabase() {
	Book* tmp = new Book[capacity * 2];
	for (int i = 0; i < used; i++) {
		tmp[i] = bookList[i];
	}

	delete[] bookList;
	bookList = tmp;
	capacity *= 2;
}

void BookDatabase::addBook(const Book& newBook) {
	if (used >= capacity)
		expandDatabase();

	bookList[used] = newBook;
	used++;
}

int BookDatabase::getCapacity() {
	return capacity;
}


void BookDatabase::removeBook(const string& _bookID) {
	for (int i = 0; i < used; i++) {
		if (bookList[i].getBookID() == _bookID) {
			bookList[i].swapBook(bookList[used-1]);
			bookList[used-1].~Book();
			used--;
		}
	}
}

void BookDatabase::sortBookByCategory() {
	Book* sorted = new Book[used];

	bool* check = new bool[used];
	for (int i = 0; i < used; i++) {
		check[i] = false;
	}

	int count = 0;
	string _category = bookList[0].getCategory();
	
	while (count < used) {
		string tmp = _category;
		for (int i = 0; i < used; i++) {
			if (bookList[i].getCategory() == _category) {
				sorted[count] = bookList[i];
				check[i] = true;
				count++;
			}
			else if (check[i] == false) {
				tmp = bookList[i].getCategory();
			}
		}
		if (count < used) {
			if (tmp != _category)
				_category = tmp;
		}
	}

	delete[] bookList;
	bookList = sorted;
}

void BookDatabase::sortBook(const string& _require) {
	if (_require == "")
		return;
}

void BookDatabase::searchByAuthor() {
	cout << "Enter author name: ";
	string _author;
	cin.ignore();
	getline(cin, _author);

	bool existed = false;
	
	for (size_t i = 0; i < getCapacity(); i++) {
		
		if (bookList[i].getAuthor() == _author) {
			
			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << bookList[i].getTitle() << "|" << setw(10) << bookList[i].getBookID() << "|" << setw(16)
			<< bookList[i].getAuthor() << "|" << setw(17) << bookList[i].getPublisher() << "|" << setw(12) << bookList[i].getCategory()
			<< "|" << setw(9) << bookList[i].getCost() << "|" << setw(15) << bookList[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");
}

void BookDatabase::searchByPublisher() {
	cout << "Enter publisher name: ";
	string _publisher;
	cin.ignore();
	getline(cin, _publisher);

	bool existed = false;

	for (size_t i = 0; i < getCapacity(); i++) {

		if (bookList[i].getPublisher() == _publisher) {

			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << bookList[i].getTitle() << "|" << setw(10) << bookList[i].getBookID() << "|" << setw(16)
				<< bookList[i].getAuthor() << "|" << setw(17) << bookList[i].getPublisher() << "|" << setw(12) << bookList[i].getCategory()
				<< "|" << setw(9) << bookList[i].getCost() << "|" << setw(15) << bookList[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");

}

void BookDatabase::searchByPublication() {
	cout << "Enter publication year: ";
	int _publication;
	cin >> _publication;
	bool existed = false;

	for (size_t i = 0; i < getCapacity(); i++) {

		if (bookList[i].getPublication() == _publication) {

			if (existed == false) {
				cout << "__________________________________________________________________________________________________________________________" << endl;
				cout << "|---------------Title---------------|--BookID--|-----Author-----|----Publisher----|--Category--|--Price--|--Publication--|" << endl;
				existed = true;
			}
			cout << "|" << setw(35) << bookList[i].getTitle() << "|" << setw(10) << bookList[i].getBookID() << "|" << setw(16)
				<< bookList[i].getAuthor() << "|" << setw(17) << bookList[i].getPublisher() << "|" << setw(12) << bookList[i].getCategory()
				<< "|" << setw(9) << bookList[i].getCost() << "|" << setw(15) << bookList[i].getPublication() << "|" << endl;
		}
	}

	if (existed)
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	else {
		cout << "No book found!" << endl;
	}
	system("pause");
}

BookDatabase::~BookDatabase() {
	
	capacity = 0;
	delete[] bookList;
}





