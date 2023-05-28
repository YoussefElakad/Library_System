#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
using namespace std;

void Menu()
{
    cout << "1-> Display all books sorted by title ascendingly" << endl
        << "2-> Display all books sorted by title descendingly" << endl
        << "3-> Remove a book by title" << endl
        << "4-> Add a new book" << endl
        << "5-> Search for a book by title" << endl
        << "6-> Display certain author books" << endl
        << "7-> Display certain category books" << endl
        << "8-> Exit" << endl << endl << endl;
}




int main()
{
    //Declerations
    BST tree;
    string inText;
    Book inBook;
    int x;

    //Reading from file
    readBooks("book.txt", tree);


    do
    {
        Menu();

        cin >> x;
        while (x > 8 || x < 1)
        {
            cout << "Wrong Input !!!" << endl;
            cin >> x;
        }

        switch (x)
        {
        case 1:
            tree.displayAsc();
            break;

        case 2:
            tree.displayDesc();
            break;

        case 3:
            cout << "enter Title: ";
            cin.ignore();
            getline(cin,inText);

            tree.RemoveByTitle(inText);
            break;

        case 4:
            cout << "title: ";
            cin.ignore();
            getline(cin, inText);
            inBook.SetTitle(inText);

            cout << "author: ";

            getline(cin, inText);
            inBook.SetAuthor(inText);

            cout << "category: ";

            getline(cin, inText);
            inBook.SetCategory(inText);

            cout << "number of pages: ";

            getline(cin, inText);
            inBook.SetNum(stoi(inText));

            tree.insert(inBook);
            break;

        case 5:
            cout << "enter Title: ";
            cin.ignore();
            getline(cin, inText);

            tree.SearchByTitle(inText);
            break;

        case 6:
            cout << "enter Author: ";
            cin.ignore();
            getline(cin, inText);

            tree.SearchByAuthor(inText);
            break;

        case 7:
            cout << "enter Category: ";
            cin.ignore();
            getline(cin, inText);

            tree.SearchByCategory(inText);
            break;
        }

    } while (x != 8);

    cout << "Good Bye !!";

    return 0;
}
