#pragma once

#include "Functions.h"
#include "Character.h"
#include <ctime>
#include <vector>
#include <fstream>

class Game
{

private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void mainMenu();
	void initGame();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();

	// Accessors
	inline bool getPlaying() const { return this->playing; }

	// Modifiers


};



