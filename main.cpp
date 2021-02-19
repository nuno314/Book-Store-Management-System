#include "book.h"
#include "bookDatabase.h"
#include "inputHandler.h"



Library lib;
string username;
User guess;

//int Login(string username, string password) {
//	
//}

void loadData() {
	lib.loadBook();
}

void Session() {
	system("cls");
	cout << "Welcome To The Book Store Management System." << endl;
	cout << "Please log in first--" << endl;
	guess.printListBook();

}

int main() {
	loadData();
	Session();

	// 17.2 done input handler.
}