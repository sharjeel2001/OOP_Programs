//Program of student Data Base using classes and objects
//Muhammad Sharjeel Husnain

#include <iostream>
#include <string>
#define SIZE 70
using namespace std;
struct date {
	int day, month, year;
};
class classStudent
{
	date doa, dob;
	int rollNo;
	string stName, fName;
	float cgpa;
public:
	classStudent(int d = 0, float q = 0.0, date={0,0,0}) : rollNo(d), cgpa(q) {}; //initializing values using constructers
	
	void readDataBase();
	void display();
	bool search(int);
};
void disp();
bool classStudent::search(int rolNo){
	if (rolNo == rollNo) {
		return true;
	}
	else {
		return false;
	}
}

void classStudent::readDataBase()
{
		cout << "enter Roll No" << endl;
		cin >> rollNo;
		cout << "enter Student name" << endl;
		cin.ignore(10, '\n');
		getline(cin,stName);
		cout << "enter father name" << endl;

		getline(cin, fName);
		cout << "enter cgpa" << endl;
		cin >> cgpa;
		cout << "enter Date of birth day/month/year" << endl;
		cin >> dob.day;
		cin >> dob.month;
		cin >> dob.year;
		cout << "enter date of admission  day/month/year" << endl;
		cin >> doa.day;
		cin >> doa.month;
		cin >> doa.year;
		
	
}

void classStudent::display()
{

	
		cout << rollNo << "\t"
			<< stName << "\t"
			<< fName << "\t\t"
			<< cgpa << "\t"
			<< dob.day << "/" << dob.month << "/" << dob.year << "\t"
			<< doa.day << "/" << doa.month << "/" << doa.year << "\t" << endl;
		
	
}
	void disp()
	{
	cout << "st#\t"
		<< "Roll No\t"
		<< "Name\t"
		<< "Father name\t"
		<< "cgpa\t"
		<< "dob\t\t"
		<< "doa" << endl;
	}
int main()
{
	int i, rolNo; //roll no that we have to search
	bool found; //returning value of search
	classStudent st[SIZE];
	int n;		 //n max number of students you want to enter 

	do {
		
		char option;
		cout << "*****Main Menu*****" << endl;
		cout << "1. Create Data Base" << endl;
		cout << "2. Append Record" << endl;
		cout << "3. Search Record" << endl;
		cout << "4. Update Record" << endl;
		cout << "5. Delete Data" << endl;
		cout << "6. Display Data" << endl;
		cout << "7. Exit" << endl;
		cout << "Select your desired option" << endl;
		cin >> option;

		switch (option)
		{
		case '1':													//create Data base
			cout << "Please enter number of Students (max " << SIZE << ")" << endl;
			cin >> n;
			while (n > SIZE || n == 0) {
				cout << "you have entered incorrect value" << endl;
				cout << "please enter value between 1 - 70" << endl;
				cin >> n;
			}
			for (i = 0;i < n;i++)
			{
				cout << "student" << i + 1 << endl;
				st[i].readDataBase();

			}

			break;
		case '2':													// append data

			
			st[n++].readDataBase();
			

			break;
		case '3':													// for searching
		{
			cout << "enter roll no you want to search" << endl;
			cin >> rolNo;
			bool flag = 0;
			for (i = 0;i < n;i++)
			{
				found = st[i].search(rolNo);
				
				if (found == true)
				{
					flag = 1;
					disp();
					st[i].display();
					break;
				}
				
			}
			if (flag == 0) {
				cout << "not found";
			}
			system("pause");
			system("cls");
			break;
		}
		case '4':	//for update
		{
			cout << "enter roll no you want to update" << endl;
			cin >> rolNo;
			bool flag = 0;
			for (i = 0;i < n;i++)
			{
				found = st[i].search(rolNo);

				if (found == true)
				{
					disp();
					st[i].display();
					cout << "enter new data" << endl;
					st[i].readDataBase();
					flag = 1;
					break;
				}

			}
			if (flag == 0)
			{
				cout << "roll no not found" << endl;

			}
			
			break;
		}
		case '5':													//for delete
		{	int j;
		cout << "enter roll no you want to delete" << endl;
		cin >> rolNo;

		for (i = 0;i < n;i++)
		{
			found = st[i].search(rolNo);
			if (found == true)
			{
				for (j = i;j < n - 1;j++)
					st[j] = st[j + 1];
				n--;
				i--;
			}
		}
		if (found = true)
			cout << "record deleted" << endl;
		else
			cout << "record not found" << endl;
		break;
		}
		case '6':													// for Display
		{
			disp();
			for (i = 0; i < n; i++)
			{
				cout << i + 1 << "\t";
				st[i].display();
			}
			
		}
		break;
		case '7':
			exit(0);
			break;


		}
		system("pause");
		system("cls");
	} while (true);

}

