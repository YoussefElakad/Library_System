/*
Name: Youssef Moustafa Ahmed
ID: 20200673

Name: Moustafa Saeed Abdelhamid
ID: 20201166
*/

#include <iostream>
#include "Book.h"
using namespace std;

class BST {

    //node decleration
    struct Node {
        Book data;
        Node* left;
        Node* right;
    };
    Node* root;

    //insertion
    Node* insert(Book x, Node* t)
    {
        if (t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (t->data < x)
            t->right = insert(x, t->right);
        return t;
    }

    //displaying Ascendingly
    void traverseAsc(Node* t) 
    {
        if (t == NULL)
            return;

        traverseAsc(t->left);
        t->data.print();
        traverseAsc(t->right);
    }

    //displaying Descendingly
    void traverseDesc(Node* t) 
    {
        if (t == NULL)
            return;

        traverseDesc(t->right);
        t->data.print();
        traverseDesc(t->left);
    }

    //returning min node
    Node* findMin(Node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    //removal
    Node* remove(string x, Node* t) 
    {
        Node* temp;
        if (t == NULL)
        {
            cout << "Book Not Found !!!" << endl << endl;
            return NULL;
        }
        else if (x < t->data.GetTitle())
            t->left = remove(x, t->left);
        else if (t->data.GetTitle() < x)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data.GetTitle(), t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
            cout << "Book Deleted" << endl << endl;
        }

        return t;
    }

    //searching title
    void searchTitle(string key,Node* t)
    {
        if (t == NULL)
        {
            cout << "Book Not Found !!!" << endl << endl;
            return;
        }
        if (t->data.GetTitle() == key)
        {
            t->data.print();
            return;
        }

        if (t->data.GetTitle() < key)
        {
            searchTitle(key, t->right);
            return;
        }

        searchTitle(key, t->left);
        return;
    }

    //searching Author
    void searchAuth(string key, Node* t)
    {
        if (t == NULL)
            return;
        if (t->data.GetAuthor() == key)
            t->data.print();

        searchAuth(key, t->left);
        searchAuth(key, t->right);
    }

    //searching Category
    void searchCat(string key, Node* t)
    {
        if (t == NULL)
            return;
        if (t->data.GetCategory() == key)
            t->data.print();

        searchCat(key, t->left);
        searchCat(key, t->right);
    }

    //destructor function
    Node* makeEmpty(Node* t) {
        if (t == NULL)
            return NULL;
        else
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST() 
    {
        root = makeEmpty(root);
    }

    void insert(Book x) 
    {
        root = insert(x, root);
    }

    void displayAsc() 
    {
        traverseAsc(root);
    }

    void displayDesc() 
    {
        traverseDesc(root);
    }

    void RemoveByTitle(string title)
    {
        remove(title, root);
    }

    void SearchByTitle(string title)
    {
        searchTitle(title,root);
    }

    void SearchByAuthor(string Auth)
    {
        searchAuth(Auth, root);
    }

    void SearchByCategory(string Cat)
    {
        searchCat(Cat, root);
    }

};

//global reading function
void readBooks(string filename, BST& tree)
{
    ifstream INF;
    string TextReader;
    Book ob;

    INF.open(filename);

    //Reading Size.
    getline(INF, TextReader);
    int SizeReader = stoi(TextReader);


    //Reading the rest of the file.
    for (int i = 0; i < SizeReader; i++)
    {
        getline(INF, TextReader);
        ob.SetTitle(TextReader);

        getline(INF, TextReader);
        ob.SetAuthor(TextReader);

        getline(INF, TextReader);
        ob.SetCategory(TextReader);

        getline(INF, TextReader);
        ob.SetNum(stoi(TextReader));

        tree.insert(ob);
    }

    INF.close();
}