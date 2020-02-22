#include "Game.h"
#include "Functions.h"
#include "Character.h"

Game::Game()
{

	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";

}


Game::~Game()
{



}

//Functions
void Game::initGame()
{
	
	createNewCharacter();

}
void Game::mainMenu()
{

	std::cout << "MAIN MENU\n" << std::endl;
	std::cout << "0.) Quit" << std::endl;
	std::cout << "1.) Travel" << std::endl;
	std::cout << "2.) Shop" << std::endl;
	std::cout << "3.) Level Up" << std::endl;
	std::cout << "4.) Rest" << std::endl;
	std::cout << "5.) Character Information" << std::endl;
	std::cout << "6.) Create New Character" << std::endl;
	std::cout << "7.) Save Character" << std::endl;
	std::cout << "8.) Load Character" << std::endl;

	std::cout << "\nEnter your choice: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{

	case 0:
		playing = false;
		break;

	case 5:
		characters[activeCharacter].printStats();
		break;

	case 6:
		std::cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;

	case 7:
		saveCharacters();
		break;

	case 8:
		loadCharacters();
		break;

	default:
		break;

	}
}

void Game::createNewCharacter()
{

	std::string name = "";
	std::cout << "Name your Character: ";

	getline(std::cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);

}

void Game::saveCharacters()
{

	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{

		for (size_t i = 0; i < characters.size(); i++)
		{

			outFile << characters[i].getAsString() << std::endl;

		}

	}

	outFile.close();

}

void Game::loadCharacters()
{



}
