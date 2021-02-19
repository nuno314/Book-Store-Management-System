#include "inputHandler.h"

void Library::loadBook(){

	ifstream inFile;
	inFile.open("Test.txt", ios::in);

	Book tmpBook;
	string _title, _author, _bookID, _publisher, _category;
	int _cost, _publication;

	string check;
	getline(inFile, check);

	while (check != "END") {

		_title = check;
		getline(inFile, _bookID);
		getline(inFile, _author);
		getline(inFile, _publisher);
		getline(inFile, _category);
		inFile >> _cost >> _publication;


		tmpBook.setBook(_title, _bookID, _publisher, _author, _category, _publication, _cost);
		Database.addBook(tmpBook);

		while (getline(inFile, check)) {
			if (!check.empty()) {
				break;
			}
		};
	}

	inFile.close();
}

void Library::loadUser() {
	
	ifstream inFile("User.txt");

	
}

