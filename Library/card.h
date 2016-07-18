#pragma once
#include <string>
#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{
private:
	string cardHolder;
	int phoneNum;
	int cardID;
	int bookCheckedOut;
public:
	Card();
	Card(string name, int num);
	string getCardHolder();
	void initializeCardID();
	int getPhoneNum();
	int getCardID();
	int getBookNum();
	void setCardHolder(string name);
	void setPhoneNum(int num);
	void setCheckedOut(int book);
	void setCardID();
	void printCard();
};
#endif