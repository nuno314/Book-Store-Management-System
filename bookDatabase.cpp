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

BookDatabase::~BookDatabase() {
	capacity = 0;
	delete[] bookList;
}





