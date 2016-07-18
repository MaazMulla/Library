#pragma once
/*A Book object needs to be able to initalize itself,
print itself, destroy itself (destructor), copy itself (copy constructor), be assigned
to (operator=), identify itself by returning its book number, get the status, set the
status, get and set who has the book. No other actions are needed.*/

//Maaz Mulla + Raymond Andersen
//Book.h
#ifndef book_H
#define book_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string title;
	string author;
	int ISBN;
	int status;
	int holder;
public:
	Book();//Default
	Book(Book &a);
	Book(string t, string a, int i, int s, int h);//copy
	void setISBN(int i);//sets isbn
	void setTitle(string t);//sets title
	void setAuthor(string a);//sets author
	int getBook();//returns the isbn
	int getStatus();//Status returns -1 out for binding,1 checking out,0 on shelf
	void setStatus(int s);//sets ^
	int getHolder();//Gets holder info
	void setHolder(int h);//Sets holder info
	void print();//print
	~Book();//deconstructor
};
#endif