#include "Books.h"

Books::Books()
{

	title = "";
	author = "";
	genre = "";

	bookNumber = 0;
	activeBook = 0;

}

Books::Books(string title, string author, string genre, int bookNumber)
{

	this->title = title;
	this->author = author;
	this->genre = genre;

	this->bookNumber = bookNumber;

}

void Books::initBook()
{

	ifstream in;
	in.open("books.txt");

	if (in.is_open())
	{

		this->loadBook();

	}

	in.close();

}

void Books::createBook()
{

	string title = "";
	string author = "";
	string genre = "";

	int bookNumber = 0;

	cout << setw(124) << " _______  ______   ______     _______  _______  _______  ___   _  \n";
	cout << setw(124) << "|   _   ||      | |      |   |  _    ||       ||       ||   | | | \n";
	cout << setw(124) << "|  |_|  ||  _    ||  _    |  | |_|   ||   _   ||   _   ||   |_| | \n";
	cout << setw(124) << "|       || | |   || | |   |  |       ||  | |  ||  | |  ||      _| \n";
	cout << setw(124) << "|       || |_|   || |_|   |  |  _   | |  |_|  ||  |_|  ||     |_  \n";
	cout << setw(124) << "|   _   ||       ||       |  | |_|   ||       ||       ||    _  | \n";
	cout << setw(124) << "|__| |__||______| |______|   |_______||_______||_______||___| |_| \n";

	cout << "\n\n";

	cin.ignore();

	cout << "Enter the book's title: ";
	getline(cin, title);

	cout << "Enter the full name of the book's author: ";
	getline(cin, author);
	
	cout << "Enter the book's genre: ";
	getline(cin, genre);

	cout << "Enter Book ID: ";
	cin >> bookNumber;

	for (size_t i = 0; i < book.size(); i++)
	{

		while (bookNumber == book[i].bookNumber || title == book[i].title && author == book[i].author && genre == book[i].genre)
		{

			cout << "Error, that book already exists in our records.";

			cin.clear();
			cin.ignore(100, '\n');

			cout << "Enter the book's title: ";
			getline(cin, title);

			cout << "Enter the full name of the book's author: ";
			getline(cin, author);

			cout << "Enter the book's genre: ";
			getline(cin, genre);

			cout << "Enter Book ID: ";
			cin >> bookNumber;

		}
	}

	book.push_back(Books());
	activeBook = book.size() - 1;
	book[activeBook].initialize(title, author, genre, bookNumber);

}

string Books::getAsString() const
{

	return to_string(bookNumber) + " " + title + " , " + author
		+ " , " + genre;

}

void Books::initialize(const string title, const string author, const string genre, const int bookNumber)
{

	this->title = title;
	this->author = author;
	this->genre = genre;
	this->bookNumber = bookNumber;

}

void Books::saveBook()
{

	ofstream outFile("books.txt");

	if (outFile.is_open())
	{

		for (size_t i = 0; i < book.size(); i++)
		{

			outFile << this->book[i].getAsString() << endl;

		}

	}

	outFile.close();

}

void Books::editBook()
{

	string oldTitle = book[activeBook].getTitle();
	string oldAuthor = book[activeBook].getAuthor();
	string oldGenre = book[activeBook].getGenre();
	int oldBookNumber = book[activeBook].getBookNumber();

	choice = 0;
	int chosenChoice = 0;

	cout << setw(124) << " _______  ______   ___   _______    _______  _______  _______  ___   _  \n";
	cout << setw(124) << "|       ||      | |   | |       |  |  _    ||       ||       ||   | | | \n";
	cout << setw(124) << "|    ___||  _    ||   | |_     _|  | |_|   ||   _   ||   _   ||   |_| | \n";
	cout << setw(124) << "|   |___ | | |   ||   |   |   |    |       ||  | |  ||  | |  ||      _| \n";
	cout << setw(124) << "|    ___|| |_|   ||   |   |   |    |  _   | |  |_|  ||  |_|  ||     |_  \n";
	cout << setw(124) << "|   |___ |       ||   |   |   |    | |_|   ||       ||       ||    _  | \n";
	cout << setw(126) << "|_______||______| |___|   |___|    |_______||_______||_______||___| |_| \n\n\n";

	for (size_t i = 0; i < book.size(); i++)
	{

		cout << setw(78) << "Index: " << i << endl;
		cout << setw(84) << "Book Number: " << book[i].getBookNumber() << endl;
		cout << setw(78) << "Title: " << book[i].getTitle() << endl;
		cout << setw(79) << "Author: " << book[i].getAuthor() << endl << endl;

	}

	cout << "\nEnter the Book Number of the book you want to edit: ";
	cin >> this->choice;

	chosenChoice = this->choice;

	string line = "";
	int i = 0;

	ifstream inFile("books.txt");

	for (size_t i = 0; i < book.size(); i++)
	{

		if (inFile.is_open())
		{

			if (chosenChoice == book[i].bookNumber)
			{

				activeBook = i;

			}



		}

	}

	inFile.close();

	if (chosenChoice != book[activeBook].bookNumber)
	{

		system("cls");

		editBook();

	}

	cin.ignore();

	cout << "You selected the book: " << this->book[activeBook].getTitle() << endl << endl;
	
	cout << "Enter new Title (Leave blank for no change): ";
	getline(cin, title);
	if (this->title.empty())
		this->title = oldTitle;
	else
		book[activeBook].title = this->title;

	cout << "Enter new Author (Leave blank for no change): ";
	getline(cin, author);
	if (this->author.empty())
		this->author = oldAuthor;
	else
		book[activeBook].author = this->author;

	cout << "Enter new Genre (Leave blank for no change): ";
	getline(cin, genre);
	if (this->genre.empty())
		this->genre = oldGenre;
	else
		book[activeBook].genre = this->genre;

	cout << "Enter new Book Number (Enter 0 for no change): ";
	cin >> this->bookNumber;
	if (this->bookNumber == 0)
		this->bookNumber = oldBookNumber;
	else
		book[activeBook].bookNumber = this->bookNumber;

}

void Books::loadBook()
{

	ifstream inFile;

	inFile.open("books.txt");

	this->book.clear();

	string title = "";
	string author = "";
	string genre = "";

	int bookNumber = 0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{

		while (getline(inFile, line))
		{

		str.str(line);

		str >> bookNumber;
		getline(str >> ws, title, ',');
		getline(str >> ws, author, ',');
		getline(str >> ws, genre, ',');
		
		
		Books temp(title, author, genre, bookNumber);

		this->book.push_back(Books(temp));

		str.clear();

		}

	}

	inFile.close();

}

void Books::viewBook()
{

	cout << setw(142) << " __   __  ___   _______  _     _    _______  ___      ___        _______  _______  _______  ___   _  _______  \n";
	cout << setw(142) << "|  | |  ||   | |       || | _ | |  |   _   ||   |    |   |      |  _    ||       ||       ||   | | ||       | \n";
	cout << setw(142) << "|  |_|  ||   | |    ___|| || || |  |  |_|  ||   |    |   |      | |_|   ||   _   ||   _   ||   |_| ||  _____| \n";
	cout << setw(142) << "|       ||   | |   |___ |       |  |       ||   |    |   |      |       ||  | |  ||  | |  ||      _|| |_____  \n";
	cout << setw(142) << "|       ||   | |    ___||       |  |       ||   |___ |   |___   |  _   | |  |_|  ||  |_|  ||     |_ |_____  | \n";
	cout << setw(142) << " |     | |   | |   |___ |   _   |  |   _   ||       ||       |  | |_|   ||       ||       ||    _  | _____| | \n";
	cout << setw(144) << "  |___|  |___| |_______||__| |__|  |__| |__||_______||_______|  |_______||_______||_______||___| |_||_______| \n\n\n";


	for (size_t i = 0; i < book.size(); i++)
	{

		cout << setw(75) << "Index: " << i << endl;
		cout << setw(81) << "Book Number: " << book[i].getBookNumber() << endl;
		cout << setw(75) << "Title: " << book[i].getTitle() << endl;
		cout << setw(76) << "Author: " << book[i].getAuthor() << endl << endl;
 
	}

	cout << setw(80) << "\n\n Press Enter to Continue...";

	system("pause > 0");

}

void Books::deleteBook()
{

	string line = "";
	string deleteString = book[activeBook].getAsString();
	int deleteBook;

	char oldFileName[50] = "books.txt";
	char newFileName[50] = "newBooks.txt";

	cout << setw(138) << " ______   _______  ___      _______  _______  _______    _______  _______  _______  ___   _  \n";
	cout << setw(138) << "|      | |       ||   |    |       ||       ||       |  |  _    ||       ||       ||   | | | \n";
	cout << setw(138) << "|  _    ||    ___||   |    |    ___||_     _||    ___|  | |_|   ||   _   ||   _   ||   |_| | \n";
	cout << setw(138) << "| | |   ||   |___ |   |    |   |___   |   |  |   |___   |       ||  | |  ||  | |  ||      _| \n";
	cout << setw(138) << "| |_|   ||    ___||   |___ |    ___|  |   |  |    ___|  |  _   | |  |_|  ||  |_|  ||     |_  \n";
	cout << setw(138) << "|       ||   |___ |       ||   |___   |   |  |   |___   | |_|   ||       ||       ||    _  | \n";
	cout << setw(141) << "|______| |_______||_______||_______|  |___|  |_______|  |_______||_______||_______||___| |_| \n\n\n";

	for (size_t i = 0; i < book.size(); i++)
	{

		cout << setw(78) << "Index: " << i << endl;
		cout << setw(84) << "Book Number: " << book[i].getBookNumber() << endl;
		cout << setw(78) << "Title: " << book[i].getTitle() << endl;
		cout << setw(79) << "Author: " << book[i].getAuthor() << endl << endl;

	}

	cout << "\nEnter the Book Number of the book you want to delete: ";
	cin >> deleteBook;

	ifstream inFile;
	ofstream outFile;

	inFile.open(oldFileName);
	outFile.open(newFileName);

	for (size_t i = 0; i < book.size(); i++)
	{

		if (deleteBook == book[i].bookNumber)
		{

			activeBook = i;

		}

	}

	if (outFile.is_open())
	{

		while (getline(inFile, line))
		{

			if (line != deleteString)
			{

				outFile << line << endl;

			}

		}

	}

	inFile.close();
	outFile.close();

	remove(oldFileName);

	if (rename(newFileName, oldFileName) != 0)
	{

		perror("Error in deleting book.");

	}

	else
		cout << "Book deleted successfully.";

	book.erase(book.begin() + activeBook);
	activeBook = activeBook - 1;

	if (book.size() < 0)
	{

		createBook();
		saveBook();

	}

}


