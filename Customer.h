#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "Library.h"
#include "User.h"
#include <Windows.h>

class Customer : public User {

public:
	void Interface(const string& username);
	void buyBook();
	
};

#endif _CUSTOMER_H