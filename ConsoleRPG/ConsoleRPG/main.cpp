#include "Game.h"
#include "Functions.h"
#include "Character.h"


int main()
{

	srand(time(NULL));

	Game game;
	game.initGame();

	Inventory inv;

	while (game.getPlaying())
	{

		game.mainMenu();

	}

	return 0;
}