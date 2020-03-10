#include "loadingScreen.h"
#include "admin.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 

loadingScreen::loadingScreen()
{

	running = true;
	maximizeWindow();

	gotoxy(28, 0); cout << " =====================================================";
	gotoxy(28, 1); cout << " =  ============  ====================================";
	gotoxy(28, 2); cout << " =  ============  ====================================";
	gotoxy(28, 3); cout << " =  ============  ====================================";
	gotoxy(28, 4); cout << " =  ========  ==  =====  =   ====   ===  =   ===  =  =";
	gotoxy(28, 5); cout << " =  ============    ===    =  ==  =  ==    =  ==  =  =";
	gotoxy(28, 6); cout << " =  ========  ==  =  ==  ==========  ==  ========    =";
	gotoxy(28, 7); cout << " =  ========  ==  =  ==  ========    ==  ==========  =";
	gotoxy(28, 8); cout << " =  ========  ==  =  ==  =======  =  ==  =======  =  =";
	gotoxy(28, 9); cout << " =        ==  ==    ===  ========    ==  ========   ==";
	gotoxy(28, 10); cout << " =====================================================";

	gotoxy(84, 0); cout << " ===============================================";
	gotoxy(84, 1); cout << " ==      =======================================";
	gotoxy(84, 2); cout << " =  ====  ======================================";
	gotoxy(84, 3); cout << " =  ====  =================  ===================";
	gotoxy(84, 4); cout << " ==  =======  =  ===   ===    ===   ===  =  = ==";
	gotoxy(84, 5); cout << " ====  =====  =  ==  =  ===  ===  =  ==        =";
	gotoxy(84, 6); cout << " ======  ====    ===  =====  ===     ==  =  =  =";
	gotoxy(84, 7); cout << " =  ====  =====  ====  ====  ===  =====  =  =  =";
	gotoxy(84, 8); cout << " =  ====  ==  =  ==  =  ===  ===  =  ==  =  =  =";
	gotoxy(84, 9); cout << " ==      ====   ====   ====   ===   ===  =  =  =";
	gotoxy(84, 10); cout << " ===============================================";
	
	gotoxy(50, 20); cout << " _______________ ";	gotoxy(97, 20); cout << " _______________ ";
	gotoxy(50, 21); cout << "|               |";	gotoxy(97, 21);	cout << "|               |";
	gotoxy(50, 22); cout << "|               |";	gotoxy(97, 22); cout << "|               |";
	gotoxy(50, 23); cout << "|    STUDENT    |";	gotoxy(97, 23); cout << "|     ADMIN     |";
	gotoxy(50, 24); cout << "|               |";	gotoxy(97, 24); cout << "|               |";
	gotoxy(50, 25); cout << "|               |";	gotoxy(97, 25); cout << "|               |";
	gotoxy(50, 26); cout << " --------------- ";	gotoxy(97, 26); cout << " --------------- ";

	gotoxy(62, 30); cout << "Choose with the right or left arrow keys";
}


loadingScreen::~loadingScreen()
{


}


void loadingScreen::mainMenu()
{

	if (GetAsyncKeyState(VK_LEFT))
	{

		gotoxy(47, 23); cout << "-->";

		SetConsoleTextAttribute(h, 2);

		gotoxy(50, 20); cout << " _______________ ";
		gotoxy(50, 21); cout << "|               |";
		gotoxy(50, 22); cout << "|               |";
		gotoxy(50, 23); cout << "|    STUDENT    |";
		gotoxy(50, 24); cout << "|               |";
		gotoxy(50, 25); cout << "|               |";
		gotoxy(50, 26); cout << " --------------- ";
		gotoxy(103, 30);

		SetConsoleTextAttribute(h, 15);

		gotoxy(94, 23); cout << "   ";

		gotoxy(97, 20); cout << " _______________ ";
		gotoxy(97, 21);	cout << "|               |";
		gotoxy(97, 22); cout << "|               |";
		gotoxy(97, 23); cout << "|     ADMIN     |";
		gotoxy(97, 24); cout << "|               |";
		gotoxy(97, 25); cout << "|               |";
		gotoxy(97, 26); cout << " --------------- ";
		gotoxy(103, 30);

		menuChoice = 1;
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{

		gotoxy(94, 23); cout << "-->";

		SetConsoleTextAttribute(h, 2);

		gotoxy(97, 20); cout << " _______________ ";
		gotoxy(97, 21);	cout << "|               |";
		gotoxy(97, 22); cout << "|               |";
		gotoxy(97, 23); cout << "|     ADMIN     |";
		gotoxy(97, 24); cout << "|               |";
		gotoxy(97, 25); cout << "|               |";
		gotoxy(97, 26); cout << " --------------- ";
		gotoxy(103, 30);

		SetConsoleTextAttribute(h, 15);

		gotoxy(47, 23); cout << "   ";

		gotoxy(50, 20); cout << " _______________ ";
		gotoxy(50, 21); cout << "|               |";
		gotoxy(50, 22); cout << "|               |";
		gotoxy(50, 23); cout << "|    STUDENT    |";
		gotoxy(50, 24); cout << "|               |";
		gotoxy(50, 25); cout << "|               |";
		gotoxy(50, 26); cout << " --------------- ";
		gotoxy(103, 30);

		menuChoice = 2;
	}

	if (GetAsyncKeyState(VK_RETURN))
	{

		switch (menuChoice)
		{

			case 1:
		// Dito Lalagay yung menu function ng Student

				system("cls");
				break;
			case 2:
		// Dito Lalagay yung menu function ng admin
				admin adminM;
				adminM.AdminMenu();
				break;
		}
	}

}


void loadingScreen::gotoxy(short x, short y)
{

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void loadingScreen::maximizeWindow() 
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
