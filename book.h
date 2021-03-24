#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Book {
	private:
		string title, bookID, publisher, author, category;
		int publication, cost;

	public:
		Book();

		// Get different information of Book
		string getTitle() const;
		string getBookID() const;
		string getAuthor() const;
		string getPublisher() const;
		string getCategory() const;
		int getCost() const;
		int getPublication() const;
		
		// Change different information of Book
		void setBook(const string& _Title, const string& _BookID, const string& _Publisher, const string& _Author, const string& _Category, const int& _Publication, const int& _Cost);
		void addNewBook(ifstream& inFile);
		void setTitle(const string& _Title);
		void setBookID(const string& _BookID);
		void setAuthor(const string& _Author);
		void setPublisher(const string& _Publisher);
		void setCategory(const string& _Category);
		void setCost(const int& _Cost);
		void setPublication(const int& _Publication);

		void printBook() const;
		void swapBook(Book& b1);
		~Book();
};