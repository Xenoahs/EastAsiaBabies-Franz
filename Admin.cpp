#include "admin.h"

void admin::addbook()
{
    Book books[100];
    ofstream File;
    File.open("Book Records.txt");
    cout << "How Many Books Do you want to add: ";
    cin >> count;
  
    cout << "\nKindly Input the Records of each Book !\n\n";
    for (int i = 0; i < count; i++) {
        cout << "Book #" << i+1 << endl;
        cout << "Enter The Title: ";
        cin.ignore();
        cin.getline(books[i].Title,100);
        cin.ignore();

        cout << "Enter The Genre: ";    
        cin.getline(books[i].genre, 100);
        cin.ignore();
        cout << "Enter Author: ";
        
        cin.getline(books[i].Author, 100);  
        cin.ignore();
       
        cout << "Enter Book ID: ";
        cin.getline(books[i].BookID, 100);
        cin.ignore();

        cout << endl;
        File << "Title: " << books[i].Title << "\n Genre: " << books[i].genre <<"\n Author:" << books[i].Author << "\n Book ID " << books[i].BookID << "\n\n";
        system("pause>0");
        cout << "Book data recorded successfully !\n\n";
        temp = i;
    }
    File.close();
}  

void admin::searchbook()
{



}

void admin::editbookinfo()
{



}
void admin::deletebook()
{



}

void admin::displayAllbooks()
{



}

void admin::borrowedbooks()
{



}


admin book;

int admin::AdminMenu()
{
    int choice;
    cout << "ADMIN MENU "<< endl;
    cout << "(1) Add Book" << endl;
    cout << "(2) Edit Book" << endl;
    cout << "(3) Delete Book" << endl;
    cout << "(4) View all Books" << endl;
    cout << "(5) Search Book" << endl;
    cout << "(6) Check Borrowed Books" << endl;
    cout << "(7) Add Announcements" << endl;
    cout << "(8) Exit" << endl;
    cout << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        admin::addbook();
        break;
    case 2:
        admin::searchbook();
        break;

    case 3:
        admin::editbookinfo();
        break;
    case 4:
        admin::deletebook();

        break;
    case 5:
        admin::displayAllbooks();
        break;
    case 6:
        admin::borrowedbooks();
        break;
    case 7:
 
        break;
    case 8:
        exit(1);
        break;
    }

	return 0;
}