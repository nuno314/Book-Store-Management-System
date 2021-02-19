#pragma once
#include "book.h"

class BookDatabase{
private:

	int capacity, used;

public:

	Book* bookList;
	BookDatabase();
	void expandDatabase();
	void addBook(const Book& newBook);
	void removeBook(const string& _bookID);
	
	void sortBook(const string& _require);
	void sortBookByCategory();
	void findBookByPublisher(const string& _publisher);
	void findBookByAuthor(const string& _author);
	void updateBookCost(const int& _cost);
	int getCapacity();
	~BookDatabase();
};