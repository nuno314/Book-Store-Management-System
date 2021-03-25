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
	
	void searchByAuthor();
	void searchByPublisher();
	void searchByPublication();
	

	int getCapacity();
	~BookDatabase();
};