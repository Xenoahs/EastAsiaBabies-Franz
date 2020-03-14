#include "Student.h"
#include "loadingScreen.h"
#include "Books.h"

loadingScreen loading;

Student::Student()
{

	username = "";
	password = "";

	activeStudent = 0;
	choice = 0;

}

Student::Student(string username, string password)
{

	this->username = username;
	this->password = password;

}

void Student::loginScreen()
{

	
	initUser();

	cout << setw(129) << "=======================================================================================\n";
	cout << setw(129) << "==      ===================  ===========================  =====  ======================\n";
	cout << setw(129) << "=  ====  ==================  ===========================   ===   ======================\n";
	cout << setw(129) << "=  ====  ===  =============  =================  ========  =   =  ======================\n";
	cout << setw(129) << "==  =======    ==  =  =====  ===   ===  = ===    =======  == ==  ===   ===  = ===  =  =\n";
	cout << setw(129) << "====  ======  ===  =  ===    ==  =  ==     ===  ========  =====  ==  =  ==     ==  =  =\n";
	cout << setw(129) << "======  ====  ===  =  ==  =  ==     ==  =  ===  ========  =====  ==     ==  =  ==  =  =\n";
	cout << setw(129) << "=  ====  ===  ===  =  ==  =  ==  =====  =  ===  ========  =====  ==  =====  =  ==  =  =\n";
	cout << setw(129) << "=  ====  ===  ===  =  ==  =  ==  =  ==  =  ===  ========  =====  ==  =  ==  =  ==  =  =\n";
	cout << setw(129) << "==      ====   ===    ===    ===   ===  =  ===   =======  =====  ===   ===  =  ===    =\n";
	cout << setw(129) << "=======================================================================================\n";

	cout << "\n\n";

	cout << setw(108) << " ___      _______  _______         ___   __    _ " << endl;
	cout << setw(108) << "|   |    |       ||       |       |   | |  |  | |" << endl;
	cout << setw(108) << "|   |    |   _   ||    ___| ____  |   | |   |_| |" << endl;
	cout << setw(108) << "|   |    |  | |  ||   | __ |____| |   | |       |" << endl;
	cout << setw(108) << "|   |___ |  |_|  ||   ||  |       |   | |  _    |" << endl;
	cout << setw(108) << "|       ||       ||   |_| |       |   | | | |   |" << endl;
	cout << setw(108) << "|_______||_______||_______|       |___| |_|  |__|" << endl << endl;

	cout << "\n\n";

	cout << setw(90) << "[1] Register " << endl << endl;
	cout << setw(88) << "[2] Log-in " << endl << endl;

	cout << setw(100) << "Enter the number of your choice: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 2)
	{

		cout << setw(100) << "Invalid Choice." << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << setw(100) << "Enter the number of your choice: ";
		cin >> choice;

	}

	if (choice == 1)
	{
		system("cls");

		registerUser();
		saveUser();

		system("cls");

		loginScreen();
	}

	else if (choice == 2)
	{

		string findUser = "";
		string findPass = "";

		cout << "\n\n";

		cout << setw(83) << "Username: ";
		cin >> username;

		cout << setw(83) << "Password: ";
		cin >> password;

		findUser = username;
		findPass = password;

		ifstream inFile;

		inFile.open("logins.txt");

		for (size_t i = 0; i < login.size(); i++)
		{

			if (inFile.is_open())
			{

				if (findUser == login[i].username && findPass == login[i].password)
				{

					activeStudent = i;

				}

			}

		}

		inFile.close();

		if (findUser == login[activeStudent].getUsername() && findPass == login[activeStudent].getPassword())
		{

			system("cls");

			mainMenu();

		}

		else if (findUser != login[activeStudent].getUsername() || findPass != login[activeStudent].getPassword())
		{

			system("cls");

			loginScreen();

		}

	}

}

void Student::mainMenu()
{

	Books book;

	book.initBook();
	int choice = 0;

	cout << setw(129) << "=======================================================================================\n";
	cout << setw(129) << "==      ===================  ===========================  =====  ======================\n";
	cout << setw(129) << "=  ====  ==================  ===========================   ===   ======================\n";
	cout << setw(129) << "=  ====  ===  =============  =================  ========  =   =  ======================\n";
	cout << setw(129) << "==  =======    ==  =  =====  ===   ===  = ===    =======  == ==  ===   ===  = ===  =  =\n";
	cout << setw(129) << "====  ======  ===  =  ===    ==  =  ==     ===  ========  =====  ==  =  ==     ==  =  =\n";
	cout << setw(129) << "======  ====  ===  =  ==  =  ==     ==  =  ===  ========  =====  ==     ==  =  ==  =  =\n";
	cout << setw(129) << "=  ====  ===  ===  =  ==  =  ==  =====  =  ===  ========  =====  ==  =====  =  ==  =  =\n";
	cout << setw(129) << "=  ====  ===  ===  =  ==  =  ==  =  ==  =  ===  ========  =====  ==  =  ==  =  ==  =  =\n";
	cout << setw(129) << "==      ====   ===    ===    ===   ===  =  ===   =======  =====  ===   ===  =  ===    =\n";
	cout << setw(129) << "=======================================================================================\n";

	cout << "\n\n";

	cout << setw(50) << "Student: " << login[activeStudent].username << endl << endl;

	cout << setw(88) << "[1] Search Book" << endl;
	cout << setw(91) << "[2] View All Books" << endl;
	cout << setw(81) << "[3] Exit" << endl << endl;

	cout << "\n\n";

	cout << setw(90) << "Enter the number of the task: ";
	cin >> choice;


	switch(choice)
	{
	case 1:
		system("cls");

		search();

		system("cls");
		break;

	case 2:
		system("cls");
		
		book.viewBook();

		system("cls");

		break;

	case 3:
		system("cls");

		cin.ignore();

		loading.mainMenu();

		break;

	default:
		break;
	}

}

void Student::search()
{

	Books book;
	string choice = "";

	book.initBook();

	cout << setw(137) << " _______  _______  _______  ______    _______  __   __    _______  _______  _______  ___   _  _______  " << endl;
	cout << setw(137) << "|       ||       ||   _   ||    _ |  |       ||  | |  |  |  _    ||       ||       ||   | | ||       | " << endl;
	cout << setw(137) << "|  _____||    ___||  |_|  ||   | ||  |       ||  |_|  |  | |_|   ||   _   ||   _   ||   |_| ||  _____| " << endl;
	cout << setw(137) << "| |_____ |   |___ |       ||   |_||_ |       ||       |  |       ||  | |  ||  | |  ||      _|| |_____  " << endl;
	cout << setw(137) << "|_____  ||    ___||       ||    __  ||      _||       |  |  _   | |  |_|  ||  |_|  ||     |_ |_____  | " << endl;
	cout << setw(137) << " _____| ||   |___ |   _   ||   |  | ||     |_ |   _   |  | |_|   ||       ||       ||    _  | _____| | " << endl;
	cout << setw(137) << "|_______||_______||__| |__||___|  |_||_______||__| |__|  |_______||_______||_______||___| |_||_______| " << endl;

	char choize;

	cout << "\n\n";

	cout << setw(92) << "[G] - General Works\n";
	cout << setw(104) << "[P] - Psychology and Philosophy\n";
	cout << setw(87) << "[R] - Religion\n";
	cout << setw(93) << "[S] - Social Science\n";
	cout << setw(87) << "[L] - Language\n";
	cout << setw(94) << "[N] - Natural Science\n";
	cout << setw(94) << "[A] - Applied Science\n";
	cout << setw(103) << "[F] - Fine Arts and Recreation\n";
	cout << setw(89) << "[I] - Literature\n";
	cout << setw(101) << "[H] - History and Geography\n\n";

	cout << setw(82) << "[E] - Exit";


	cout << "\n\n\n";

	cout << setw(95) << "Enter the letter of the category: ";
	cin >> choize;

	switch (choize)
	{

	case 'g':
	case 'G':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "General Works")
			{

			cout << endl;
			cout << setw(75) << "Index: " << i << endl;
			cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
			cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
			cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;
			
			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'p':
	case 'P':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Psychology and Philosophy")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case'r':
	case 'R':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Religion")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 's':
	case 'S':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Social Science")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case'l':
	case 'L':
		
		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Language")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'n':
	case 'N':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Natural Science")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'a':
	case 'A':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Applied Science")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'f':
	case 'F':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Fine Arts and Recreation")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'i':
	case 'I':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "Literature")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");
		search();

		break;

	case 'h':
	case 'H':

		for (size_t i = 0; i < book.book.size(); i++)
		{

			if (book.book[i].genre == "History and Geography")
			{

				cout << endl;
				cout << setw(75) << "Index: " << i << endl;
				cout << setw(81) << "Book Number: " << book.book[i].getBookNumber() << endl;
				cout << setw(75) << "Title: " << book.book[i].getTitle() << endl;
				cout << setw(76) << "Author: " << book.book[i].getAuthor() << endl << endl;

			}

		}

		cout << "\n\n";

		cout << setw(94) << "Press Enter to Continue...";

		system("pause > 0");
		system("cls");

		break;

	case 'e':
	case 'E':

		system("cls");

		mainMenu();

	}

	cin.ignore();
}

void Student::initialize(const string username, const string password)
{

	this->username = username;
	this->password = password;

}


void Student::initUser()
{

	ifstream in("logins.txt");

	if (in.is_open())
	{

		this->loadUser();

	}

	in.close();

}

string Student::getAsString() const
{

	return username + ", " + password;

}

void Student::registerUser()
{

	string username = "";
	string password = "";

	cout << "Enter Username: ";
	cin >> username;

	cout << "Enter Password: ";
	cin >> password;

	for (size_t i = 0; i < login.size(); i++)
	{

		while (username == login[i].username || password == login[i].password)
		{

			cout << "\nThat user already exists in our records.";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Enter Username: ";
			cin >> username;

			cout << "Enter Password: ";
			cin >> password;

		}

	}

	login.push_back(Student());
	activeStudent = login.size() - 1;
	login[activeStudent].initialize(username, password);

}

void Student::saveUser()
{

	ofstream outFile("logins.txt");

	if (outFile.is_open())
	{

		for (size_t i = 0; i < login.size(); i++)
		{

			outFile << this->login[i].getAsString() << endl;

		}

	}

	outFile.close();

}

void Student::loadUser()
{

	ifstream inFile;

	inFile.open("logins.txt");

	this->login.clear();

	string username = "";
	string password = "";

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{

		while (getline(inFile, line))
		{

			str.str(line);

			getline(str >> ws, username, ',');
			getline(str >> ws, password);

			Student temp(username, password);

			this->login.push_back(Student(temp));

			str.clear();

		}

	}

}

