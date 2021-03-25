#pragma once
#include "book.h" 
#include "bookDatabase.h"
#include "Library.h";
#include "User.h";
#include "Staff.h"

class Admin : public Staff {

public:
	void Interface(const string& username);
	void updatePrice();
	
};