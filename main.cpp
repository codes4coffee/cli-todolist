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

int main()
{
   ifstream todoFile;

    todoFile.open("todo.txt");

    if(todoFile)
    {
        //Run main program
    }
    else
    {
        //This is the first time the user is running the program so setup the program config
        setUp();
        //Program should then call the actual to do program
    }
}

void setUp()
{
    char response;

    cout << "Welcome to cli to-do list." << endl << "I will now set up your config file" << endl;
    cout << "Before I do, please make sure that there is not a file in the current directory called";
    cout << " todoStore.txt" << endl << "Enter y to continue: ";
    cin >> response;

    while(response != 'y')
    {
        cout << "You did not press y" << endl << "Please enter y to continue: ";
        cin >> response;
    }

    ofstream todoFile("todoStore.txt");

    cout << "File created! Have a very productive day!";

    todoFile.close();

    return;
}