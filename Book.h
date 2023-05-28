#include <iostream>
using namespace std;


class Book
{
	string title;
	string author;
	string category;
	int numOfPages;


public:
	Book()
	{
		this->title = "";
		this->author = "";
		this->category = "";
		this->numOfPages = 0;
	}

	Book(string title, string author, string category, int numOfPages)
	{
		this->title = title;
		this->author = author;
		this->category = category;
		this->numOfPages = numOfPages;
	}

	//setters
	void SetTitle(string title)
	{
		this->title = title;
	}
	void SetAuthor(string author)
	{
		this->author = author;
	}
	void SetCategory(string category)
	{
		this->category = category;
	}
	void SetNum(int numOfPages)
	{
		this->numOfPages = numOfPages;
	}

	//Getters
	string GetTitle()
	{
		return title;
	}
	string GetAuthor()
	{
		return author;
	}
	string GetCategory()
	{
		return category;
	}
	int GetNum()
	{
		return numOfPages;
	}


	void print()
	{
		cout << "Title: " << title << endl
			<< "Author: " << author << endl
			<< "Category: " << category << endl
			<< "NumOfPages: " << numOfPages << endl << endl;
	}

	//operator
	bool operator<(const Book& ob)
	{
		if (this->title < ob.title)
			return true;
		else
			return false;
	}
};
