#include <iostream>
#include <fstream>
#include "library.h";

using namespace std;

void main()
{
	ifstream book, card;
	Library l(book, card);
	char option = 0;
	while (option != 'q')
	{
		cout << "Welcome to our library!\n";
		cout << "To view books in library enter \'p\'\n";
		cout << "To view cards in library enter \'c\'\n";
		cout << "To create a new card enter \'n\'\n";
		cout << "To view a card account enter \'e\'\n";
		cout << "To return book enter \'b\'\n";
		cout << "To borrow book enter \'r\'\n";
		cout << "To exit enter \'q\'\n";
		cin >> option;
		tolower(option);
		l.doCommand(option);
	}
}