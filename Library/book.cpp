//Maaz Mulla + Raymond Andersen
//book.cpp
#include <string>
#include <iostream>
#include "book.h"

using namespace std;

Book::Book()//Default
{
	title = "Does not exist.\n";
	author = "Does not exist.\n";
	ISBN = 0;
	status = 1000;
	holder = 0;
}
Book::Book(Book &a)
{
	title = a.title;
	author = a.author;
	ISBN = a.ISBN;
	status = a.status;
	holder = a.holder;
}
Book::Book(string t, string a, int i, int s, int h)//copy
{
	title = t;
	author = a;
	ISBN = i;
	status = s;
	holder = h;
}
void Book::setISBN(int i)
{
	ISBN = i;
}
void Book::setTitle(string t)
{
	title = t;
}
void Book::setAuthor(string a)
{
	author = a;
}
int Book::getBook()//returns the isbn
{
	return ISBN;
}
int Book::getStatus()//Status returns -1 out for binding,1 checking out,0 on shelf
{
	return status;
}
void Book::setStatus(int s)//sets ^
{
	status = s;
}
int Book::getHolder()//Gets holder info
{
	return holder;
}
void Book::setHolder(int h)//Sets holder info
{
	holder = h;
}
void Book::print()//print
{
	cout << "Title: " << title << "\tAuthor: " << author << endl;
	cout << "ISBN: " << ISBN << "\tStatus: " << status << endl;
	cout << "Holder: " << holder << endl;
}
Book::~Book()//deconstructor
{
	title = "Does not exist.\n";
	author = "Does not exist.\n";
	ISBN = 0;
	status = 1000;
	holder = 0;
}