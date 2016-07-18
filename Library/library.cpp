#include "library.h"
#include <fstream>
#include <iostream>
#include <string>

Library::Library() //no books or cards in the library - default
{
	cAmount = 0;
	bAmount = 0;
	cards[cAmount].initializeCardID();
}
Library::Library(ifstream &b, ifstream &c) //initializer  --- NEED TO FIX THIS
{
	cAmount = 0;
	bAmount = 0;
	cards[cAmount].initializeCardID();
	b.open("book.txt");
	c.open("card.txt");
	//book temps
	int isbn;
	string bookTitle;
	//card temps
	string name;
	int phN, bookN;

	while (b.good())
	{
		b >> isbn; b >> bookTitle; b >> name;

		books[bAmount].setISBN(isbn);
		books[bAmount].setTitle(bookTitle);
		books[bAmount].setAuthor(name);
		books[bAmount].setStatus(0);
		books[bAmount].setHolder(0);

	}
	b.close();
	c >> name; c >> phN; c >> bookN;

	cards[cAmount].setCardHolder(name);
	cards[cAmount].setCardID();
	cards[cAmount].setPhoneNum(phN);
	cards[cAmount].setCheckedOut(bookN);
	cAmount++;
	while (!c.eof())
	{
		c >> name; c >> phN; c >> bookN;

		cards[cAmount].setCardHolder(name);
		cards[cAmount].setCardID();
		cards[cAmount].setPhoneNum(phN);
		cards[cAmount].setCheckedOut(bookN);
		cAmount++;
	}
	c.close();
}
void Library::doCommand(char option) //users access to library functions thru doCommand
{
	switch (option)
	{
	case 'p': printBooks();
		break;
	case 'c': printCards();
		break;
	case 'n':
	{
		string x;
		int y;
		cout << "Enter name and phone number.\n";
		cin >> x >> y;
		Card a(x, y);
		newCard(a);
	}
	break;
	case 'e': existingCard();
		break;
	case 'b':
	{
		int x, y;
		cout << "Enter card holder number:\n";
		cin >> x;
		cout << "Enter book ISBN:\n";
		cin >> y;
		borrowBook(retrieveCard(x), retrieveBook(y));
	}
	break;
	case 'r':
	{
		int x, y;
		cout << "Enter card holder number:\n";
		cin >> x;
		cout << "Enter book ISBN:\n";
		cin >> y;
		returnBook(retrieveCard(x), retrieveBook(y));
	}
	break;
	case 'q':
	{
		cout << "Thanks you. Enjoy the rest of your day and visit again.\n";
	}
	break;
	}
}
void Library::printBooks()
{
	int count;
	cout << "Books in the Library" << endl;
	for (count = 0; count<bAmount; count++)
	{
		cout << books[count].getHolder() << endl;
	}
	cout << endl;
}
void Library::printCards()
{
	int count;
	cout << "Library Card Members" << endl;
	for (count = 0; count<cAmount; count++)
	{
		cards[count].printCard();
	}
	cout << endl;
}

void Library::newCard(Card a)
{
	cards[cAmount] = a;
	printCards();
	cAmount++;
}
void Library::existingCard()
{
	int id;
	cout << "Enter card ID: ";
	cin >> id;
	cout << endl;
	int count;
	for (count = 0; count<cAmount; count++)
	{
		if (cards[count].getCardID() == id)
		{
			cards[count].printCard();
		}
	}

}
void Library::borrowBook(Card &c, Book &b)
{
	if (b.getStatus() == 0)//if books still in lib
	{
		b.setStatus(1);//status is set to borrowed
		c.setCheckedOut(1);
		b.setHolder(c.getCardID());
	}
	else
	{
		cout << "Book is unavaliable right now, try again later\n";
	}

}
void Library::returnBook(Card &a, Book &b)//x isbn
{
	if (b.getStatus() == 1 && b.getHolder() == a.getCardID())//book taken out and is on the acc
	{
		int bb = a.getBookNum();//inorder to decrease the number of books taken out... can be done better...possibly
		bb--;
		a.setCheckedOut(bb);
		b.setStatus(0);
	}
	else
	{
		cout << "No books checked out. Cannot return...\n";
	}

}

Card Library::retrieveCard(int x)
{
	for (int count = 0; count<cAmount; count++)
	{
		if (cards[count].getCardID() == x)
		{
			return cards[count];
		}
	}
}
Book Library::retrieveBook(int z)//gets book in lib. z is isbn
{
	int i = 0;
	while (!z == books[i].getBook() && i<6)//check book is in library compares isbn
	{
		i++;
	}
	if (i == 6)
	{
		cout << "Book not in library.\n";
		Book zero("Error", "Error", -2000012, -1213, -122212);
		return zero;
	}
	else
		return books[i];
}