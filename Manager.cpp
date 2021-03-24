#include "Manager.h"

void Manager::loadBook() {
	this->lib.loadBook();
}

void Manager::loadUser() {
	this->lib.loadUser();
}

void Manager::addUser() {
	User _user;
	this->lib.addUser(_user);
}

