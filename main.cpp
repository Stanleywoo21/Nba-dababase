#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BST.h"
#include "BINARY_NODE.h"
#include "currency.h"
#include "HashTable.h"
using namespace std;

/*
This programe demonstrates the use of HashTable, BST through buiding a database of nbaPlayff objects respectively.

In this main progroam, we first build ask the user to enter an input file. hen we will extract data from the file and build a nbaPlayoff data base with both BST and HashTable.
 Then, the user is prompted to choose what to do next from the menu:
 
    1- to add new nbaPlayoff obj to both HashTable, and BST
    2- to remove data from both Hashtable and BST
    3-To search a data from the Hashtable
    4-to list data in with a format of hashtable
    5-to list a bst database in a sorted format based on the adress.
    6-to print the bst in a format of tree
    7-to show the efficiency of the hashtable and functions
    8-to prompt the user to build a list of his/her all time favorite nbaPloyff database and output the database to a file.
    9-to exit from the program.
*/

int getChoice();
int main()
{

       ofstream ofile;
       ofile.open("Output.txt");
       cout << "Please Enter Full Path For Input File: ";
       string x;
       getline(cin, x);

       ofile << x << endl;

       ifstream myFile;
       myFile.open(x);
       int count = 0;
       string line;

       while (getline(myFile, line)) {
           count++;
       }

       myFile.close();

       BST<nbaPlayoff*> *b = NULL;
        HashTable* table = new HashTable(count - 10); //using total line calculation for input
       string yeet;
       ifstream ifile;
       ifile.open(x);

       for (int i = 0; i < count; i++) {
           getline(ifile, yeet);
//           nbaPlayoff*y = new nbaPlayoff;
//           ifile >> y;
           nbaPlayoff *n = new nbaPlayoff();
           stringstream ss(yeet);
           ss >> n->year >> n->champ >> n->runnerUp >> n->fMvp>> n->points >> n->rebounds >> n->assists;
           if (i == 0) {
               b = new BST<nbaPlayoff*>(n);
           }
           else {
               b->add(n);
           }
           table->insert(n);
           //cout << *n << endl;
       }

        int choice;
            do
            {
                choice = getChoice();
                if (choice == 1)
                {
                    nbaPlayoff *newData = new nbaPlayoff();
                    cout << "Input the year of the NBA Finals: ";
                    cin >> newData->year;
                    cout << "Input the " << newData->year << " NBA Finals Champion: ";
                    cin >> newData->champ;
                    cout << "Input the " << newData->year << " NBA Finals Runners Up: ";
                    cin >> newData->runnerUp;
                    cout << "Input the " << newData->year << " NBA Finals MVP: ";
                    cin >> newData->fMvp;
                    cout << "Input the name of the player with the most points "
                    << "in the " << newData->year << " NBA Finals: ";
                    cin >> newData->points;
                    cout << "Input the name of the player with the most rebounds "
                    << "in the " << newData->year << " NBA Finals: ";
                    cin >> newData->rebounds;
                    cout << "Input the name of the player with the most assists "
                    << "in the " << newData->year << " NBA Finals: ";
                    cin >> newData->assists;
                    b->add(newData);
                    table->insert(newData);
                }
                else if (choice == 2)
                {
                    int year;
                    cout << "Input the year of the NBA Finals you would like to delete: ";
                    cin >> year;
                    cout << "What champ do you want to remove: ";
                    std::string champ;
                    cin >> champ;
                    nbaPlayoff* np = new nbaPlayoff();
                    np->year = year;
                    np->champ = champ;
                    b->remove(np);
                    table->remove(np);
                }
                else if (choice == 3)
                {
                    int year;
                    cout << "Which year's data would you like to search for? ";
                    cin >> year;
                    if(year < 1969 || year > 2019)
                    {
                        cout << "We don't have this year in the database. Try again:  ";
                        cin >> year;
                    }
                    nbaPlayoff* yeet = new nbaPlayoff;//change yeet to y if you want more than just year
                    yeet->setYear(year);//and delete this
                    table->search(yeet);
                    delete yeet;
                    cout << endl;
                }
                else if (choice == 4)
                {
                    table->printTable();
                }
                else if (choice == 5)
                {
                    b->displayInOrder(cout);
                    //cout << endl;
                }
                else if (choice == 6)
                {
                    b->displayHorizontalTreeNoRoot(nullptr, false, cout);
                }
                else if (choice == 7)
                {
                    cout << endl;
                    table->printEfficiencies();
                    cout << endl;
                }
                else if (choice == 8)
                {
                    int year;
                    cout << "Which year's data would you like to search for? ";
                    cin >> year;
                    if(year < 1969 || year > 2019)
                    {
                        cout << "We don't have this year in the database. Try again:  ";
                        cin >> year;
                    }
                    cout << "Which champ do you wanna add: ";
                    string input;
                    cin >> input;
                    nbaPlayoff* yeet = new nbaPlayoff;//change yeet to y if you want more than just year
                    yeet->setYear(year);//and delete this
                    yeet->setChamp(input);
                    table->searchOptionEight(yeet);
                    delete yeet;
                    cout << endl;
                    
                }
            } while (choice != 9);
        ifile.close();
        ofile.close();

        system("pause");
        return 0;
        }


        int getChoice()
        {
            cout << "Choose one of the following option numbers: " << endl;
            cout << "(1) Add new data\n(2) Delete data\n(3) Search\n"
                << "(4) List data in hash table\n(5) List data in sorted key\n"
                << "(6) Print indented tree\n(7) Efficiency\n(8) All Time Fav\n"
                << "(9) Quit" << endl << endl;
            int choice;

            do
            {
                cout << "Choice: ";
                cin >> choice;
                if (choice < 1 || choice > 9)
                    cout << "Invalid choice. Please try again." << endl << endl;
            } while (choice < 1 || choice > 9);

            return choice;
        }
