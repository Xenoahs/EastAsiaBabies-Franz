#include "Includes.h"
#include "loadingScreen.h"

void maximizeWindow();

int main()
{

	loadingScreen loading;

	maximizeWindow();

	while (loading.getRunning())
	{

	loading.mainMenu();

	}

	return 0;

}

void maximizeWindow() 
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}