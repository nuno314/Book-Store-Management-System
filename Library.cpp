#include "Library.h"
#include "string"

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
	string userInfo;
	User newUser;
	
	while (getline(inFile,userInfo)) {
	
		size_t pos = 0;
		string token;
		char delimeter = '  ' ;
		int count = 0;

		while ((pos != string::npos)) { // npos: "until the end of the string"
			pos = userInfo.find(delimeter);
			token = userInfo.substr(0, pos);
			
			switch (count) {
			case 0:
				newUser.setUsername(token);
				break;
			case 1:
				newUser.setPassword(token);
				break;
			case 2:
				newUser.setRole(stoi(token));
				break;
			}
			cout << token << endl;
			userInfo.erase(0, pos + 1);
			count++;
		}

		UserArray.push_back(newUser);
	}

	inFile.close();
}

void Library::addUser(User _user) {

	ofstream outFile;
	outFile.open("User.txt");
	if (!outFile) {
		cout << "User.txt can't open. " << endl;
		return;
	}

	this->UserArray.push_back(_user);

	for (size_t i = 0; i < this->UserArray.size(); i++) {
		outFile << UserArray[i].getUsername() << " " << UserArray[i].getPassword() << " " << UserArray[i].getRole() << endl;
	}

	outFile.close();
}

