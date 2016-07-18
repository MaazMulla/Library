#pragma once
#include "Card.h"
#include "Book.h"

#ifndef LIBRARY_H
#define LIBRARY_H
using namespace std;

class Library
{
public:
	Library();
	Library(ifstream &b, ifstream &c);
	void doCommand(char option);
private:
	void printBooks();
	void printCards();
	void newCard(Card a);
	void existingCard();
	void returnBook(Card &a, Book &b);
	void borrowBook(Card &c, Book &b);
	Card retrieveCard(int x);//gets card in lib
	Book retrieveBook(int z);//gets book in lib
	int cAmount;
	int bAmount;
	Card cards[100];
	Book books[5];
};

#endif