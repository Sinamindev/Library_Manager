
// Definition of class Book
#ifndef BOOK1_H
#define BOOK1_H
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

const Date defaultDate=(1,1,1927);

class  Book
{
public:
	Book (  string First = "", string Last = "", string titleSet = "", Date = defaultDate, Date = defaultDate); // Put in default values 
	~Book();
	Book & setCheckOutDate ( Date);
	Book & setDueDate( Date);
	Book & setFirstName ( string );
	Book & setLastName ( string );
	Book & setTitle ( string);
	string  getFirstName() const;
	string  getLastName() const;
	string  getTitle() const;
	Date getCheckOutDate() const;
	Date getDueDate() const;

private:
	string firstName;
	string lastName;
	string title;
	Date   checkOut;
	Date   due;
};

#endif
