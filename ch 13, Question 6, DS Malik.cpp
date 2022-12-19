/*
* Muhammad Sharjeel
* 4345
* compiler used Microsoft VS (Community)
question 6: Using classes, design an online address book to keep track of the names,
addresses, phone numbers, and dates of birth of family members, close
friends, and certain business associates. Your program should be able to
handle a maximum of 500 entries.
a. Define a class, addressType, that can store a street address, city,
state, and ZIP code. Use the appropriate functions to print and store the
address. Also, use constructors to automatically initialize the member
variables.
b. Define a class extPersonType using the class personType (as
defined in Example 12-9, Chapter 12), the class dateType (as designed
in this chapter’s Programming Exercise 2), and the class addressType.
Add a member variable to this class to classify the person as a family
788 | Chapter 13: Inheritance and Composition
member, friend, or business associate. Also, add a member variable to store
the phone number. Add (or override) the functions to print and store the
appropriate information. Use constructors to automatically initialize the
member variables.
c. Define the class addressBookType using the previously defined
classes. An object of the type addressBookType should be able to
process a maximum of 500 entries.
The program should perform the following operations:
i. Load the data into the address book from a disk.
ii. Sort the address book by last name.
iii. Search for a person by last name.
iv. Print the address, phone number, and date of birth (if it exists) of a
given person.
v. Print the names of the people whose birthdays are in a given month.
vi. Print the names of all of the people between two last names.
vii. Depending on the user’s request, print the names of all family
members, friends, or business associates*/#include <iostream>
#include <string>
using namespace std;
#define SIZE 500
 

class addressType {

	string city, country, address;
	int zip;
public:
	addressType() {
		city = "\0";
		country = "\0";
		address = "\0";
		zip = 0;
	}
	void set();
	void get();
};

void addressType::set() {
	cout << "Enter address e.g street#, house#:" << endl;
	cin.ignore();
	getline(cin, address);
	
	cout << "Enter city name:" << endl;
	cin.ignore();
		getline(cin, city);
	
	cout << "Enter country name:" << endl;
	cin.ignore();
	getline(cin, country);
	cout << "Enter Zip code:" << endl;
	cin >> zip;
}
void addressType::get() {
	cout << "Address:" << address << endl;
	cout << "City:" << city << endl;
	cout << "State:" << country << endl;
	cout << "Zip Code:" << zip << endl;
}

class dateType {
protected:
	unsigned int dd, mm, yy;
public:
	dateType() {
		dd = 0;
		mm = 0;
		yy = 0;
		
	}
	void setD();
	void getD();
};
void dateType::setD()
{
	cout << "Enter Date Of birth dd/mm/yyyy" << endl;
	cin >> dd;
	cout << "/";
	cin >> mm;
	cout << "/";
	cin >> yy;
	cout << endl;
	
}
void dateType::getD()
{
	cout << "Date of birth is: " << dd << "/" << mm << "/" << yy << endl;
}

class personType {

	string fName, lName;
public:
	personType() {
		fName = lName = "\0";
		

	} 
	void setName();
	void getName();
};

void personType::setName() {
	cout << "Enter First Name:" << endl;
	cin.ignore();
	getline(cin, fName);
	cout << "Enter your Last Name:" << endl;
	cin.ignore(0);
	getline(cin, lName);

}
void personType::getName() {
	cout << "first name :" << fName << endl;
	cout << "last name:" << lName << endl;
}

class extPersonType :virtual public addressType, virtual public personType, virtual public dateType 
{
	string rel;
	long unsigned phone;
public:
	extPersonType()
	{
		rel = "\0";
		phone = 0;
	}
	void setRel();
	void getRel();
	void setPhone();
	void getPhone();
};
void extPersonType::setRel()
{
	cout << "What is Relation? a family member, friend, or business friend ? Enter Below" << endl;
	char choice;
	cout << "1. Family\n"
		<< "2. Friend\n"
		<< "3. Business Friend " << endl;
	cin >> choice;
	switch (choice)
	{
	case '1':
		rel = "Family";
		break;
	case '2':
		rel = "Friend";
		break; 
	case '3':
			rel = "Business Friend";
			break;

	}
}
void extPersonType::getRel() {
	cout << "Relation is " << rel << endl;
}
void extPersonType::setPhone() {
	cout << "Enter phone No" << endl;
	cin >> phone;
}
void extPersonType::getPhone() {
	cout << "Phone Number : " << phone << endl;
}

class addressBookType {
	extPersonType list[SIZE];
public:
	void setter(int);
	void getter(int);
}; 
void addressBookType::setter(int n)
{
	for (int i = 0; i < n; i++)
	{
		list[i].setName();
		list[i].set();
		list[i].setD();
		list[i].setRel();
		list[i].setPhone();
		system("pause");
		system("cls");
		
	}
}
void addressBookType::getter(int n)
{
	for (int i = 0; i < n; i++)
	{
		list[i].getName();
		list[i].get();
		list[i].getD();
		list[i].getRel();
		list[i].getPhone();
		
		cout<<"\n\n";
	}
}
int main()
{
	addressBookType p;
	int n = 0;
	char choice=0;
	do {
		cout << "***Main Menu***\n"
			<< "Press 1: Create Address Book\n"
			<< "Press 2: Display Address Book\n"
			<< "Press 9: Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "how many address you want to store?" << endl;
			cin >> n;
			p.setter(n);

			break;

		case '2':
			p.getter(n);
			break;
		}
		system("pause");
		system("cls");
	} while (true);
	return 0;
}