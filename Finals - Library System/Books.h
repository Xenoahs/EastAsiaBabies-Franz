#pragma once

#include "Includes.h"

class Books
{

private:

	vector<Books> book;
	vector<Books> borrow;

	string title;
	string author;
	string genre;

	int choice;
	int activeBook;
	int bookNumber;

public:

	Books();

	Books(string title, string author, string genre, int bookNumber);

	friend class Student;

	void initBook();
	void loadBook();

	void createBook();
	void saveBook();
	void editBook();
	void deleteBook();
	void viewBook();
	void initialize(const string title, const string author, const string genre, const int bookNumber);
	string getAsString() const;


	// Accessors

	inline const string& getTitle() const{ return this->title; }
	inline const string& getAuthor() const { return this->author; }
	inline const string& getGenre() const { return this->genre; }
	inline const int& getBookNumber() const { return this->bookNumber; }

};

