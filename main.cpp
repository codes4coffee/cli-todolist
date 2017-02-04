/*
 *  Programmed by: Jacob Lancaster
 *  Description: This is a simple to-do list app that works in the command line. The app has to-do items that can be
 *  grouped into workflows. An example of a workflow would be school related tasks. The app saves all this data into
 *  text files in the same directory. This was created as a simple remedy to a lack of a to-do app on arch linux.
 */
#include <iostream>
#include <fstream>

using namespace std;

void setUp();
void mainProgram();
int checkUserChoice(int choice);
void displayMenu();

int main()
{
   ifstream todoFile;

    todoFile.open("todoStore.txt"); //MAKE THE NAME OF THE STORAGE FILE A CONST!!!!!!!!

    if(todoFile)
    {
        //Run main program
        mainProgram();
    }
    else
    {
        //This is the first time the user is running the program so setup the program config
        setUp();
        //Program should then call the actual to do program
        mainProgram();
    }
}

void setUp()
{
    char response;

    cout << "Welcome to cli to-do list." << endl << "I will now set up your config file." << endl;
    cout << "Before I do, please make sure that there is not a file in the current directory called";
    cout << " todoStore.txt" << endl << "Enter y to continue: ";
    cin >> response;

    while(response != 'y')
    {
        cout << "You did not press y" << endl << "Please enter y to continue: ";
        cin >> response;
    }

    ofstream todoFile("todoStore.txt");

    cout << "File created! Have a very productive day!" << endl;

    todoFile.close();

    return;
}

void mainProgram()
{
    int menuChoice;

    cout << "CLI To-Do manager v0.1" << endl << "By: Jacob Lancaster" << endl;
    displayMenu();
    cin >> menuChoice;
    menuChoice = checkUserChoice(menuChoice);
}

int checkUserChoice(int choice)
{
    while(choice < 0 || choice > 4)
    {
        cout << "Error! Incorrect menu choice" << endl;
        displayMenu();
        cin >> choice;
    }
    return choice;
}

void displayMenu()
{
    cout << "Main Menu:" << endl << endl;
    cout << "0. Quit Program" << endl;
    cout << "1. Display list" << endl;
    cout << "2. Create Task" << endl;
    cout << "3. Mark task as done" << endl;
    cout << "Please select a menu choice: ";
}