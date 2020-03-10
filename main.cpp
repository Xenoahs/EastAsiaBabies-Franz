// Name: Library Management System
// Purpose: To create a program using all the lessons during our Finals in Comp Prog 2
// Date Started: March 3, 2020 8:54 AM
// Date Ended: N/A

#include "loadingScreen.h"
#include "admin.h"
int main()

{

	loadingScreen loading;
	loadingScreen();

	while (loading.getRunning())
		loading.mainMenu();

}




