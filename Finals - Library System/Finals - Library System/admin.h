#pragma once
//Declarations
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class admin{
private:

	bool running;

public:

	//BOOK Information
	struct Book {
		char Title[100];
		char genre[100];
		char Author[100];
		char BookID[100];
	}books[100];
	
	//Functions for the Menu
	void addbook();
	void searchbook();
	void editbookinfo();
	void deletebook();
	void displayAllbooks();
	void borrowedbooks();

	
	//The ADMIN MENU 
	int AdminMenu();
	
	int count,temp=0;
	inline bool getRunning() const { return this->running; }
};