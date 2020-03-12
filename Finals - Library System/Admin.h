#pragma once

#include "Includes.h"

class Admin
{
private:

	bool running;

	string username;
	string password;
	int choice;

public:

	void loginScreen();
	void mainMenu();

	// Accessors

	inline bool getRunning() const { return this->running; }

};

