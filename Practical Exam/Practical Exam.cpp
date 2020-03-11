// Includes

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Record
{
public:
	Record();

	Record(int accountNumber, string fullName, float balance);

	// Functions

	void mainMenu();

	void initRecord();
	void createRecord();
	void saveRecord();
	void loadRecord();
	void selectRecord();
	void editRecord();
	void deleteRecord();

	void viewRecord();
	void initialize(const string fullName, const int accountNumber, const float balance);

	string getAsString() const;

	// Accessors

	inline bool getPlaying() const { return this->playing; }
	inline const int& getAccountNumber() const { return this->accountNumber; }
	inline const string& getFullName() const { return this->fullName; }
	inline const float& getBalance() const { return this->balance; }

private:

	// Variables

	int choice;
	bool playing;

	int accountNumber;
	string fullName;
	float balance;

	string fileName;

	vector<Record> record;
	int activeRecord;

};

Record::Record()
{

	choice = 0;
	playing = true;

	accountNumber = 0;
	fullName = "";
	balance = 0.0;

	fileName = "records.txt";
	activeRecord = 0;

}

Record::Record(int accountNumber, string fullName, float balance)
{

	this->accountNumber = accountNumber;

	this->fullName = fullName;

	this->balance = balance;

}

int main()
{
	
	Record records;

	records.initRecord();

	while (records.getPlaying())
	{
		records.mainMenu();
	}

}

// Functions

void Record::initRecord()
{

	// Opening files records.txt

	ifstream in;
	in.open("records.txt");

	if (in.is_open())
	{
		// If there are existing records, it will load them
		this->loadRecord();

	}

	else
	{
		// Else if there aren't, it will force you to create one
		createRecord();
		this->saveRecord();

	}

	// Close file

	in.close();
}

void Record::mainMenu()
{

	cout << " == MAIN MENU == " << endl << endl;

	// Display what account is loaded at the moment
	cout << "Account Number: " << this->record[activeRecord].getAccountNumber() << endl;
	cout << "Name: " << this->record[activeRecord].getFullName() << endl << endl;

	// Switch Cases
	cout << "1: Write Record" << endl;
	cout << "2: Read Record" << endl;
	cout << "3: Search Record" << endl;
	cout << "4: Edit Record" << endl;
	cout << "5: Delete Record" << endl;
	cout << "6: Exit" << endl << endl;

	cout << "Enter choice from [1 - 6]: ";
	cin >> choice;

	while (cin.fail() || choice > 6 || choice < 1)
	{

		cout << "Incorrect Input." << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << endl << "Enter choice from [1 - 6]: ";
		cin >> this->choice;

	}

	cin.ignore(100, '\n');
	cout << endl;

	switch (choice)
	{
	case 1:
		createRecord();
		saveRecord();

		Sleep(2000);
		system("cls");
		break;

	case 2:
		record[activeRecord].viewRecord();

		Sleep(2000);
		system("cls");
		break;

	case 3:
		selectRecord();

		Sleep(2000);
		system("cls");
		break;

	case 4:
		editRecord();
		saveRecord();

		Sleep(2000);
		system("cls");
		break;

	case 5:
		deleteRecord();

		Sleep(2000);
		system("cls");
		break;

	case 6:
		playing = false;

		break;

	default:
		break;
	}
}

void Record::createRecord()
{
	// Initializing data
	int accountNumber = 000000000;
	string fullName = "";
	double balance = 0.0;

	// Asking the user to enter information
	cout << "Enter Full Name: ";
	getline(cin, fullName);

	cout << "Preferred Account Number (enter 9 digits): ";
	cin >> accountNumber;

	//Checking to see if the user entered 9 digit ID
	while (cin.fail() || to_string(accountNumber).length() < 9 || to_string(accountNumber).length() > 9 )
	{

		cout << "Account Number is invalid." << endl;

		cin.clear();
		cin.ignore(100, '\n');

		cout << "Preferred Account Number (enter 9 digits): ";
		cin >> accountNumber;

	}

	for (size_t i = 0; i < this->record.size(); i++)
	{

		while (fullName == this->record[i].getFullName() || accountNumber == this->record[i].getAccountNumber())
		{

			cout << "Error. User already exists in our records." << endl;

			cin.clear();
			cin.ignore(100, '\n');

			cout << "Full Name: ";
			getline(cin, fullName);

			cout << "Preferred Account Number: ";
			cin >> accountNumber;

		}

	}

	// Add element to the vector record
	record.push_back(Record());
	activeRecord = record.size() - 1;
	record[activeRecord].initialize(fullName, accountNumber, balance);
}

void Record::saveRecord()
{

	// Opening of File

	ofstream outFile(fileName);

	if (outFile.is_open())
	{

		for (size_t i = 0; i < this->record.size(); i++)
		{
			// Outputting of info to txt file
			outFile << this->record[i].getAsString() << endl;

		}

	}

	outFile.close();

}

void Record::selectRecord()
{
	int chosenNumber;

	cout << " == SELECT RECORD == " << endl << endl;

	// For "searching" existing records already in the txt file
	for (size_t i = 0; i < this->record.size(); i++)
	{

		cout << "Index: " << i << " = " << this->record[i].getAccountNumber() << " Name: " << this->record[i].getFullName() << endl;

	}

	cout << endl;

	cout << "Enter the account number of the record you want to access: ";
	cin >> this->choice;

	while (cin.fail() || to_string(this->choice).length() > 9 || to_string(this->choice).length() < 9)
	{

		cout << "Incorrect Input." << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Enter the account number of the record you want to access: ";
		cin >> this->choice;

	}

	cin.ignore(100, '\n');
	cout << endl;

	chosenNumber = this->choice;

	stringstream str;
	string line = "";
	int i = 0;

	ifstream inFile;
	
	inFile.open("records.txt");

	for (size_t i = 0; i < record.size(); i++)
	{

		if (inFile.is_open())
		{

			if (chosenNumber == record[i].accountNumber)
			{

				activeRecord = i;

			}

		}

	}
	cout << this->record[this->activeRecord].getFullName() << " is selected." << endl << endl;

}

void Record::loadRecord()
{

	ifstream inFile(fileName);

	// Clearing data to ensure loading is correctly executed

	this->record.clear();

	int accountNumber = 000000000;
	string fullName = "";
	double balance = 0.0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{
		// It will search the txt file for the information of the specific index loaded
		while (getline(inFile, line))
		{

			str.str(line);

			str >> accountNumber;
			str >> balance;
			getline(str >> ws, fullName);

			Record temp(accountNumber, fullName, balance);

			
			this->record.push_back(Record(temp));

			cout << "Account Number " << temp.getAccountNumber() << " is loaded." << endl << endl;

			str.clear();

			system("cls");
		}
	}

}

void Record::viewRecord()
{
	// Viewing of information affiliated with the account number

	cout << "== RECORD == " << endl << endl;
	cout << "Account Number: " << this->accountNumber << endl;
	cout << "Name: " << this->fullName << endl;

	cout << fixed << setprecision(2);

	cout << "Balance: " << this->balance << endl << endl;

}

void Record::deleteRecord()
{

	string line, deleteRec;
	char oldFileName[50] = "records.txt";
	char newFileName[50] = "newRecords.txt";


	deleteRec = record[activeRecord].getAsString();

	ifstream inFile;
	ofstream outFile;
	
	// Opening of "old file"
	inFile.open(oldFileName);

	// Opening of newly created file
	outFile.open(newFileName);

	if (outFile.is_open())
	{

		while (getline(inFile, line))
		{
			//It prints out everythng in the text except the record I am going to delete
			if (line != deleteRec)
			{

				outFile << line << endl;

			}

		}

		inFile.close();
		outFile.close();

		// It deletes the old file

		remove(oldFileName);

		// Then renames a newly created txt file the same name as the previous txt file to "overwrite"
		if (rename(newFileName, oldFileName) != 0)
		{

			perror("Error in deleting record.");

		}

		else
		{

			cout << "Record Deleted Successfully." << endl;

		}

	}

	record.erase(record.begin() + activeRecord);
	activeRecord = activeRecord - 1;

	if (activeRecord < 0)
	{

		this->createRecord();
		this->saveRecord();

	}

}

void Record::editRecord()
{

	// Storing old values in case the user does not want to change them
	int oldAccountNumber = record[activeRecord].getAccountNumber();
	string oldFullName = record[activeRecord].getFullName();
	float oldBalance = record[activeRecord].getBalance();

	
		cout << "== EDIT RECORD == " << endl << endl;
		cout << "Enter new Account Number (Enter 0 if no change): ";
		cin >> this->accountNumber;

		if (this->accountNumber == 0)
			this->accountNumber = oldAccountNumber;

		cout << "Enter new Name (Leave blank if no change): ";
		getline(cin, this->fullName);

		if (this->fullName.empty())
		{
			this->fullName = oldFullName;
		}

		cin.ignore();

		cout << "Enter Balance: ";
		cin >> balance;

		// re-initializes values to store them into the txt file
		record[activeRecord].initialize(fullName, accountNumber, balance);
}

string Record::getAsString() const
{
	// I turned all of the variables into strings to store them into the text file

	cout << fixed << setprecision(2);

	return to_string(accountNumber) + " " + to_string(balance) + " " + fullName;

}

void Record::initialize(const string fullName, const int accountNumber, const float balance)
{

	cout << fixed << setprecision(2);

	this->accountNumber = accountNumber;
	this->fullName = fullName;
	this->balance = balance;

}