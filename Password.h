#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Password {
private:
	string psw;
	int length;

public: 
	Password();
	void setPassword();
	string getPassword();

	~Password();
};
