#include <iostream>
#include <string>
#define SIZE 70
using namespace std;
void update();
void createDB();

void display();
void append();
void search();
void delet();
struct Date {
	int day=0, month=0, year=0;
};
struct Student {
	int rollNo=0;
	string stName, fName;
	float CGPA=0;
	Date DOB, DOA;
	
};
Student st[SIZE];
int n;		 //n max number of students you want to enter 
int ilt = 0;  // no of records

int main()
{
	do {
		int option;
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
		case 1:
			createDB();
			break;
		case 2:
			append();
			break;
		case 3:
			search();
			break;
		case 4:
			update();
			break;
		case 5:
			delet();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(0);
			break;

		}
	} while (true);


}
 

void createDB()
{
	cout << "Please enter number of Students (max " << SIZE << ")" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "student" << i + 1 << endl;

		cout << "enter Roll No" << endl;
		cin >> st[ilt].rollNo;
		cout << "enter Student name" << endl;

		cin >> st[ilt].stName;
		cout << "enter father name" << endl;

		cin >> st[ilt].fName;
		cout << "enter CGPA" << endl;
		cin >> st[ilt].CGPA;
		cout << "enter Date of birth day/month/year" << endl;
		cin >> st[ilt].DOB.day;
		cin >> st[ilt].DOB.month;
		cin >> st[ilt].DOB.year;
		cout << "enter date of admission  day/month/year" << endl;
		cin >> st[ilt].DOA.day;
		cin >> st[ilt].DOA.month;
		cin >> st[ilt].DOA.year;
		ilt++;

	}
	main();
}

void display()
{



	cout << "st#\t"
		<< "Roll No\t"
		<< "Name\t"
		<< "Father name\t"
		<< "CGPA\t"
		<< "DOB\t\t"
		<< "DOA" << endl;

	for (int i = 0; i < ilt; i++)
	{

		cout << i +1<< "\t"
			<< st[i].rollNo << "\t"
			<< st[i].stName << "\t"
			<< st[i].fName << "\t\t"
			<< st[i].CGPA << "\t"
			<< st[i].DOB.day << "/" << st[i].DOB.month << "/" << st[i].DOB.year << "\t"
			<< st[i].DOA.day << "/" << st[i].DOA.month << "/" << st[i].DOA.year << "\t" << endl;
	}
	system("pause");
	system("cls");
	main();
}
void append()
{
	cout << "Please enter number of Students (max " << SIZE << ")" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "student" << ilt + 1 << endl;

		cout << "enter Roll No" << endl;
		cin >> st[ilt].rollNo;
		cout << "enter Student name" << endl;

		cin >> st[ilt].stName;
		cout << "enter father name" << endl;

		cin >> st[ilt].fName;
		cout << "enter CGPA" << endl;
		cin >> st[ilt].CGPA;
		cout << "enter Date of birth day/month/year" << endl;
		cin >> st[ilt].DOB.day;
		cin >> st[ilt].DOB.month;
		cin >> st[ilt].DOB.year;
		cout << "enter date of admission  day/month/year" << endl;
		cin >> st[ilt].DOA.day;
		cin >> st[ilt].DOA.month;
		cin >> st[ilt].DOA.year;
		ilt++;

	}
	main();
}
void search()
{
	int i, rolNo,alt=0;
	cout << "enter roll no you want to search" << endl;
	cin >> rolNo;
	for ( i = 0;i < ilt;i++)
	{
		if (rolNo == st[i].rollNo)
		{
			alt = 1;
			break;
		}
	}
		if (alt == 1)
		{
			

			cout<< "Roll No\t"
				<< "Name\t"
				<< "Father name\t"
				<< "CGPA\t"
				<< "DOB\t\t"
				<< "DOA" << endl;


				
				cout<< st[i].rollNo << "\t"
					<< st[i].stName << "\t"
					<< st[i].fName << "\t\t"
					<< st[i].CGPA << "\t"
					<< st[i].DOB.day << "/" << st[i].DOB.month << "/" << st[i].DOB.year << "\t"
					<< st[i].DOA.day << "/" << st[i].DOA.month << "/" << st[i].DOA.year << "\t" << endl;

		}
		else
			cout << "roll no not found" << endl;
	
	main();
}
void update()
{
	int i, rolNo, alt = 0;
	cout << "enter roll no you want to update" << endl;
	cin >> rolNo;
	for (i = 0;i < ilt;i++)
	{
		if (rolNo == st[i].rollNo)
		{
			alt = 1;
			break;
		}
	}
	if (alt == 1)
	{

		cout << "Roll No\t"
			<< "Name\t"
			<< "Father name\t"
			<< "CGPA\t"
			<< "DOB\t\t"
			<< "DOA" << endl;

		cout << st[i].rollNo << "\t"
			<< st[i].stName << "\t"
			<< st[i].fName << "\t\t"
			<< st[i].CGPA << "\t"
			<< st[i].DOB.day << "/" << st[i].DOB.month << "/" << st[i].DOB.year << "\t"
			<< st[i].DOA.day << "/" << st[i].DOA.month << "/" << st[i].DOA.year << "\t" << endl;
		system("pause");
		system("cls");
		cout << "enter new data" << endl;
		cout << "enter Roll No" << endl;
		cin >> st[i].rollNo;
		cout << "enter Student name" << endl;

		cin >> st[i].stName;
		cout << "enter father name" << endl;

		cin >> st[i].fName;
		cout << "enter CGPA" << endl;
		cin >> st[i].CGPA;
		cout << "enter Date of birth day/month/year" << endl;
		cin >> st[i].DOB.day;
		cin >> st[i].DOB.month;
		cin >> st[i].DOB.year;
		cout << "enter date of admission  day/month/year" << endl;
		cin >> st[i].DOA.day;
		cin >> st[i].DOA.month;
		cin >> st[i].DOA.year;
	}
	else
		cout << "roll no not found" << endl;
}
void delet() 
{
	int i, alt = 0, rolNo;
	cout << "enter roll no you want to delete" << endl;
	cin >> rolNo;
	for (i = 0;i < ilt;i++)
	{
		if (rolNo == st[i].rollNo)
		{
			for (int j = i;j < ilt-1;j++)
				st[j] = st[j + 1];
			ilt--;
			i--;
			alt++;
		}
			
	}
	if (alt == 0)
		cout << "record not found" << endl;
	else
		cout << "record deleted" << endl;
	main();
}