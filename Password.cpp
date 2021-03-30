#include "Password.h"

Password::Password() {
	psw = "";
	length = 0;
}

void Password::setPassword() {
	
	int passwordSize = 10;
	char* s = new char[passwordSize];
	int i = 0;
	for (i = 0; i < passwordSize; i++) {
		s[i] = _getch(); _putch('*');

		if (s[i] == 13) break; // 13 = Enter
	};

	string _password;
	for (int i = 0; i < passwordSize; i++) {
		if (s[i] != '\r')
			psw += s[i];
		else break;
	}

	delete[] s;
}

string Password::getPassword() {
	return psw;
}

Password::~Password() {
	psw = "";
	length = 0;
}