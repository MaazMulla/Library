#include <string>
#include <iostream>
#include"Card.h"

Card::Card()
{
	cardHolder = "No info";
	phoneNum = 0;
	bookCheckedOut = 0;
}
Card::Card(string name, int num)
{
	initializeCardID();
	cardHolder = name;
	phoneNum = num;
	bookCheckedOut = 0;
	cardID += cardID;
}
void Card::initializeCardID()
{
	cardID = 0;
}
string Card::getCardHolder()
{
	return cardHolder;
}
int Card::getPhoneNum()
{
	return phoneNum;
}
int Card::getCardID()
{
	return cardID;
}
int Card::getBookNum()
{
	return bookCheckedOut;
}
void Card::setCardHolder(string name)
{
	cardHolder = name;
}
void Card::setPhoneNum(int num)
{
	phoneNum = num;
}
void Card::setCheckedOut(int book)
{
	bookCheckedOut = bookCheckedOut + book;
}
void Card::setCardID()
{
	cardID += 1;
}
void Card::printCard()
{
	cout << "Card information: " << endl << cardHolder << ' ' << phoneNum << ' ' << cardID << ' ' << bookCheckedOut << endl;
}