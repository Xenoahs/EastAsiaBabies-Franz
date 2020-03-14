#pragma once

#include "Includes.h"

class Admin
{
private:

	bool running = true;

	string username;
	string password;
	int choice = 0;

public:

	void loginScreen();
	void mainMenu();

	// Accessors

	inline bool getRunning() const { return this->running; }

};

