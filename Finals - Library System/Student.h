#pragma once

#include "Includes.h"

class Student
{

private:

	string username;
	string password;

	int activeStudent;
	int choice;

	vector<Student> login;

public:

	Student();
	Student(string username, string password);

	void initialize(const string username, const string password);
	void initUser();
	string getAsString() const;

	void loginScreen();
	void mainMenu();

	void registerUser();
	void saveUser();
	void loadUser();


	// Accessors

inline const string& getUsername() const{ return this->username; }
inline const string& getPassword() const { return this->password; }


};

