#pragma once

#include "Includes.h"

class loadingScreen
{
private:

	bool running;
	string choice;

public:
	void mainMenu();


	// Accessors

	inline bool getRunning() const { return this->running; }
	inline const string& getChoice() const { return this->choice; }

};

