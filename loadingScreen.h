#pragma once

// Declarations

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;



class loadingScreen
{

private:

	bool running;
	int menuChoice;

public:
	loadingScreen();
	~loadingScreen();

	// Functions

	void gotoxy(short x, short y);
	void maximizeWindow();
	void mainMenu();

	// Accessors
	inline bool getRunning() const {return this->running;}

};

