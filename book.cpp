#include "book.h"

//string title, bookID, publisher, author;
//int publication, cost

Book::Book() {
	title = "";
	bookID = "";
	publisher = "";
	author = "";
	category = "";
	publication = 0;
	cost = 0;
}

Book::~Book() {
	title = "";
	bookID = "";
	publisher = "";
	author = "";
	category = "";
	publication = 0;
	cost = 0;
}

void Book::setBook(const string& _Title, const string& _BookID, const string& _Publisher, const string& _Author, const string &_Category, const int& _Publication, const int& _Cost) {
	title = _Title;
	bookID = _BookID;
	publisher = _Publisher;
	author = _Author;
	category = _Category;
	publication = _Publication;
	cost = _Cost;
}

void Book::swapBook(Book& des) {
	string tmp;
	
	tmp = this->getTitle();
	this->setTitle(des.getTitle());
	des.setTitle(tmp);

	tmp = this->getBookID();
	this->setBookID(des.getBookID());
	des.setBookID(tmp);

	tmp = this->getAuthor();
	this->setAuthor(des.getAuthor());
	des.setAuthor(tmp);

	tmp = this->getPublisher();
	this->setPublisher(des.getPublisher());
	des.setPublisher(tmp);

	tmp = this->getCategory();
	this->setCategory(des.getCategory());
	des.setCategory(tmp);

	int tmpnum;
	tmpnum = this->getCost();
	this->setCost(des.getCost());
	des.setCost(tmpnum);

	tmpnum = this->getPublication();
	this->setPublication(des.getPublication());
	des.setPublication(tmpnum);
}


void Book::addNewBook(ifstream& inFile){
	if (!inFile)
		return;

	//cout << "Name: ";
	getline(inFile, title);

	//cout << "ID Number: ";
	getline(inFile, bookID);

	//cout << "Author: ";
	getline(inFile, author);

	//cout << "Publisher: ";
	getline(inFile, publisher);

	//cout << "Enter cost: ";
	inFile >> cost;

	inFile >> category;

	// << "Publication: ";
	inFile >> publication;
}

string Book::getTitle() const{
	return title;
}

string Book::getBookID() const {
	return bookID;
}

string Book::getAuthor() const {
	return author;
}

string Book::getCategory() const {
	return category;
}

string Book::getPublisher() const {
	return publisher;
}

int Book::getPublication() const {
	return publication;
}

int Book::getCost() const {
	return cost;
}

void Book::setTitle(const string& _Title){
	title = _Title;
}

void Book::setBookID(const string& _BookID) {
	bookID = _BookID;
}

void Book::setAuthor(const string& _Author) {
	author = _Author;
}

void Book::setPublisher(const string& _Publisher) {
	publisher = _Publisher;
}

void Book::setCategory(const string& _Category) {
	category = _Category;
}

void Book::setCost(const int& _Cost) {
	cost = _Cost;
}

void Book::setPublication(const int& _Publication) {
	publication = _Publication;
}

void Book::printBook() const {
	cout << "Name: " << title << "." << endl;
	cout << "Book ID: " << bookID << "." << endl;
	cout << "Author: " << author << "." << endl;
	cout << "Category: " << category << "." << endl;
	cout << "Publisher: " << publisher << "." << endl;
	cout << "Publication: " << publication << "." << endl;
	cout << "Cost: " << cost << "." << endl;
}







