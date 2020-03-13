#include "Student.h"
#include "loadingScreen.h"
#include "Books.h"

loadingScreen load;
Books use;

Student dothis;

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

		cout << setw(85) << "Username: ";
		cin >> username;

		cout << setw(85) << "Password: ";
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

	cout << setw(45) << "Student: " << login[activeStudent].username << endl << endl;

	cout << setw(88) << "[1] Search Book" << endl;
	cout << setw(88) << "[2] Locate Book" << endl;
	cout << setw(88) << "[3] Borrow Book" << endl;
	cout << setw(91) << "[4] View All Books" << endl;
	cout << setw(81) << "[5] Exit" << endl << endl;

	cout << "\n\n";

	cout << setw(90) << "Enter the number of the task: ";
	cin >> choice;


	switch(choice)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:
		dothis.locate();
		break;
	case 4:
		system("cls");
		use.viewBook();
		system("cls");
		break;
	case 5:
		system("cls");
		cin.ignore();
		load.mainMenu();
		break;
	default:
		break;
	}

}

void Student::locate()
{
	char choice;
	cout << "[G]-General Works\n";
	cout << "[P]-Psychology and Philosophy\n";
	cout << "[R]-Religion\n";
	cout << "[S]-Social Science\n";
	cout << "[L]-Language\n";
	cout << "[N]-Natural Science\n";
	cout << "[A]-Applied Science\n";
	cout << "[F]-Fine Arts and Recreation\n";
	cout << "[I]-Literature\n";
	cout << "[H]-History and Geography\n";

	cin >> choice;

	switch (choice) 
	{	
	case 'G':
	

		system("pause > 0");
		break;
	case 'P':

		break;
	case 'R':

		break;
	case 'S':

		break;
	case 'L':

		break;
	case 'N':

		break;
	case 'A':

		break;
	case 'F':

		break;
	case 'I':

		break;
	case 'H':

		break;

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

		while (username == login[i].username && password == login[i].password)
		{

			cout << "That user already exists in our records.";
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