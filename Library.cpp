
#include <iostream>
#include "book.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	Date myDate, checkOutDate, dueDate;
	Book myBook[50];
	int  month=0, day=0, year=0, counter = 0;
	string first, last, title, garbage;
	char choice;
	ifstream in;
	ofstream out;

	in.open("library.txt", ios::in);
	in >> first;
	while(in)
	{
		in >> last;
		getline(in, garbage);
		getline(in,title);
		myBook[counter].setFirstName(first);
		myBook[counter].setLastName(last);
		myBook[counter].setTitle(title);
		in >> month >> day >> year;
		myDate.setDate(month, day, year);
		myBook[counter].setCheckOutDate(myDate);
		in >> month >> day >> year;
		myDate.setDate(month, day, year);
		myBook[counter].setDueDate(myDate);
		counter++;
		in >> first;
	}

	in.close();

	cout << "Welcome to CS library program. " << endl;
	cout << "Please enter the date in integers according to the following format- mm dd yyyy: " 
		 << endl;
	cin >> month >> day >> year;
	myDate.setDate(month, day, year);
	checkOutDate = myDate;
	dueDate = checkOutDate;
	dueDate+=14;
	myBook[counter].setDueDate(dueDate);
	
	do
	{
		cout << "Please enter your one letter choice as follows:"
		<< "\nC:  Check out a book"
		<< "\nD:  Check in a book"
	    << "\nT:  Print all books currently checked out"
	    << "\nQ:  quit this program" << endl;
		
		cin >> choice;
		tolower(choice);

		if(choice == 'c')
		{
			cout  << "\nPlease enter one line consisting of the first and last" 
				  << "names of the author followed by the title of the book" << endl;
			cin >> first;
			cin >> last;
			getline(cin,title);
			myBook[counter].setCheckOutDate(checkOutDate);
			myBook[counter].setDueDate(dueDate);
			myBook[counter].setFirstName(first);
			myBook[counter].setLastName(last);
			myBook[counter].setTitle(title);
			counter++;
		}
		
		else if(choice == 'd')
		{
			cout << "\nPlease enter one line consisting of the first and last names"  << endl;
			cout << "of the author followed by the title of the book." << endl;

			cin >> first;
			cin >> last;
			getline(cin,title);

			int i=0;

			while(i < counter && 
				  first != myBook[i].getFirstName() &&
				  last != myBook[i].getLastName() &&
				  title != myBook[i].getTitle())
			{
				i++;
			}

			if(first == myBook[i].getFirstName() &&
				   last == myBook[i].getLastName() &&
				   title == myBook[i].getTitle())
			{

				if(myBook[i].getDueDate() < myDate)
					{cout << "This book is overdue" << endl << endl;}

				myBook[i] = myBook[counter-1];
				counter--;
			}
			else 
				{cout << "Book does not exist" << endl << endl;}
		}
		
		else if(choice == 't')
		{
			cout << left << setw(12) << "Author"
				 << setw(15) << "Title"
				 << setw(23) << "Check Out Date"
				 << "DueDate" << endl << endl;
			for(int i=0; i < counter; i++)
			{
				cout << left << myBook[i].getFirstName() 
					 << ", " << myBook[i].getLastName()
					 << setw(15) << myBook[i].getTitle() 
					 << myBook[i].getCheckOutDate() 
					 << myBook[i].getDueDate() 
					 << endl << endl;
			}
		}

	}while(choice != 'q');

	out.open("library.txt", ios::out);

	for(int i=0; i<counter; i++)
	{
		out << myBook[i].getFirstName() << endl
			<< myBook[i].getLastName() << endl
			<< myBook[i].getTitle() << endl
			<< myBook[i].getCheckOutDate().getMonth() <<endl
			<< myBook[i].getCheckOutDate().getDay() <<endl
			<< myBook[i].getCheckOutDate().getYear() <<endl
			<< myBook[i].getDueDate().getMonth() << endl
			<< myBook[i].getDueDate().getDay() <<endl
			<< myBook[i].getDueDate().getYear() <<endl;
	}

	out.close();
	return 0;
}

