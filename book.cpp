
// Member function definitions for Date class
#include <iostream>
#include "book.h"
#include <string>

Book::Book ( string First, string Last, string titleSet, Date checkOutDate, Date dueDate)
{
	firstName=First;
	lastName=Last;
	title=titleSet;
	checkOut = checkOutDate;
	due = dueDate;
} 

Book::~Book(){}

Book & Book::setCheckOutDate ( Date checkOutDate )
{
	checkOut = checkOutDate;
	return *this;
}

Book & Book::setDueDate( Date dueDate)
{
	due = dueDate;
	return *this;
}

Book &Book::setFirstName(string First)
{
	firstName=First;
	return *this;
}

Book & Book::setLastName ( string Last)
{
	lastName=Last;
	return *this;
}

Book & Book::setTitle ( string titleSet)
{
	title = titleSet;
	return *this;
}

string Book::getFirstName() const
{
	return firstName;
}

string Book::getLastName() const
{
	return lastName;
}

string Book::getTitle() const
{
	return title;
}

Date Book::getCheckOutDate() const
{
	return checkOut;
}

Date Book::getDueDate() const
{
	return due;
}


