#include "Admin.h"
#include "Books.h"

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

	cout << setw(90) << "Username: ";
	cin >> username;

	cout << setw(90) << "Password: ";
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
	cout << setw(100) << "[5] Check Borrowed Books" << endl;
	cout << setw(97) << "[6] Add Announcements" << endl;
	cout << setw(84) << "[7] Exit" << endl << endl;

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
		break;

	case 6:
		break;

	case 7:

		return;

		break;

	default:
		break;
	}

}