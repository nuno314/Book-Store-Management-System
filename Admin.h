#pragma once
#include "book.h" 
#include "bookDatabase.h"
#include "Library.h";
#include "User.h";

class Admin : public User {

public:
	void Interface(const string& username);
	
};