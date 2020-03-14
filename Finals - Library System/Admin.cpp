#include "Admin.h"
#include "Books.h"
#include "loadingScreen.h"

Books book;

void Admin::loginScreen()
{

	book.initBook();

	running = true;

	cout << setw(124) << "===========================================================================\n";
	cout << setw(124) << "====  ========  ============================  =====  ======================\n";
	cout << setw(124) << "===    =======  ============================   ===   ======================\n";
	cout << setw(124) << "==  ==  ======  ============================  =   =  ======================\n";
	cout << setw(124) << "=  ====  =====  ==  =  = ===  ==  = ========  == ==  ===   ===  = ===  =  =\n";
	cout << setw(124) << "=  ====  ===    ==        ======     =======  =====  ==  =  ==     ==  =  =\n";
	cout << setw(124) << "=        ==  =  ==  =  =  ==  ==  =  =======  =====  ==     ==  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ==  =  ==  =  =  ==  ==  =  =======  =====  ==  =====  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ==  =  ==  =  =  ==  ==  =  =======  =====  ==  =  ==  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ===    ==  =  =  ==  ==  =  =======  =====  ===   ===  =  ===    =\n";
	cout << setw(124) << "===========================================================================\n";

	cout << "\n\n";

	cout << setw(112) << " ___      _______  _______         ___   __    _ " << endl;
	cout << setw(112) << "|   |    |       ||       |       |   | |  |  | |" << endl;
	cout << setw(112) << "|   |    |   _   ||    ___| ____  |   | |   |_| |" << endl;
	cout << setw(112) << "|   |    |  | |  ||   | __ |____| |   | |       |" << endl;
	cout << setw(112) << "|   |___ |  |_|  ||   ||  |       |   | |  _    |" << endl;
	cout << setw(112) << "|       ||       ||   |_| |       |   | | | |   |" << endl;
	cout << setw(112) << "|_______||_______||_______|       |___| |_|  |__|" << endl << endl;

	cout << "\n\n";

	cout << setw(88) << "Username: ";
	cin >> username;

	cout << setw(88) << "Password: ";
	cin >> password;

	while (cin.fail() || username != "admin" || password != "admin")
	{

		cout << setw(100) << "Incorrect username / password." << endl << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << setw(90) << "Username: ";
		cin >> username;

		cout << setw(90) << "Password: ";
		cin >> password;

	}

	if (username == "admin" && password == "admin")
	{

		system("cls");
		
		while (getRunning())
			this->mainMenu();

	}

}

void Admin::mainMenu()
{

	book.initBook();

	loadingScreen loading;

	cout << setw(124) << "===========================================================================\n";
	cout << setw(124) << "====  ========  ============================  =====  ======================\n";
	cout << setw(124) << "===    =======  ============================   ===   ======================\n";
	cout << setw(124) << "==  ==  ======  ============================  =   =  ======================\n";
	cout << setw(124) << "=  ====  =====  ==  =  = ===  ==  = ========  == ==  ===   ===  = ===  =  =\n";
	cout << setw(124) << "=  ====  ===    ==        ======     =======  =====  ==  =  ==     ==  =  =\n";
	cout << setw(124) << "=        ==  =  ==  =  =  ==  ==  =  =======  =====  ==     ==  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ==  =  ==  =  =  ==  ==  =  =======  =====  ==  =====  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ==  =  ==  =  =  ==  ==  =  =======  =====  ==  =  ==  =  ==  =  =\n";
	cout << setw(124) << "=  ====  ===    ==  =  =  ==  ==  =  =======  =====  ===   ===  =  ===    =\n";
	cout << setw(124) << "===========================================================================\n\n";

	cout << "\n\n";

	cout << setw(88) << "[1] Add Book" << endl;
	cout << setw(89) << "[2] Edit Book" << endl;
	cout << setw(91) << "[3] Delete Book" << endl;
	cout << setw(94) << "[4] View All Books" << endl;
	cout << setw(93) << "[5] View Borrowed" << endl;
	cout << setw(84) << "[6] Exit" << endl << endl;

	cout << "\n\n";

	cout << setw(90) << "Enter the number of the task: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 8)
	{

		cout << setw(90) << "Invalid Choice." << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << setw(90) << "Enter the number of the task: ";
		cin >> choice;

	}

	switch (choice)
	{

	case 1:
		system("cls");

		book.createBook();
		book.saveBook();

		system("cls");
		break;

	case 2:
		system("cls");

		book.editBook();
		book.saveBook();

		system("cls");
		break;

	case 3:

		system("cls");

		book.deleteBook();

		system("cls");
		break;

	case 4:

		system("cls");

		book.viewBook();

		system("cls");
		break;

	case 5:
		system("cls");

		cout << setw(138) << " _______  __   __  _______  _______  ___   _  _______  ______     _______  _______  ______    ______    _______  _     _  _______  ______     _______  _______  _______  ___   _  _______  \n";
		cout << setw(138) << "|       ||  | |  ||       ||       ||   | | ||       ||      |   |  _    ||       ||    _ |  |    _ |  |       || | _ | ||       ||      |   |  _    ||       ||       ||   | | ||       | \n";
		cout << setw(138) << "|       ||  |_|  ||    ___||       ||   |_| ||    ___||  _    |  | |_|   ||   _   ||   | ||  |   | ||  |   _   || || || ||    ___||  _    |  | |_|   ||   _   ||   _   ||   |_| ||  _____| \n";
		cout << setw(138) << "|       ||       ||   |___ |       ||      _||   |___ | | |   |  |       ||  | |  ||   |_||_ |   |_||_ |  | |  ||       ||   |___ | | |   |  |       ||  | |  ||  | |  ||      _|| |_____  \n";
		cout << setw(138) << "|      _||       ||    ___||      _||     |_ |    ___|| |_|   |  |  _   | |  |_|  ||    __  ||    __  ||  |_|  ||       ||    ___|| |_|   |  |  _   | |  |_|  ||  |_|  ||     |_ |_____  | \n";
		cout << setw(138) << "|     |_ |   _   ||   |___ |     |_ |    _  ||   |___ |       |  | |_|   ||       ||   |  | ||   |  | ||       ||   _   ||   |___ |       |  | |_|   ||       ||       ||    _  | _____| | \n";
		cout << setw(138) << "|_______||__| |__||_______||_______||___| |_||_______||______|   |_______||_______||___|  |_||___|  |_||_______||__| |__||_______||______|   |_______||_______||_______||___| |_||_______| \n";

	case 6:
		system("cls");
		cin.ignore();
		loading.mainMenu();
		break;

	default:
		break;
	}

}