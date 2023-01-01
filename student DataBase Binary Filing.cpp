
//Program of student Data Base using classes and objects
//Muhammad Sharjeel Husnain

#include <iostream>
#include <string>
#include<fstream>
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
	classStudent(int d = 0, float q = 0.0, date = { 0,0,0 }) : rollNo(d), cgpa(q) {}; //initializing values using constructers

	void readDataBase();
	void display();
	bool search(int);
	
};
void disp();
bool classStudent::search(int rolNo) {
	if (rolNo == rollNo) {
		return true;
	}
	else {
		return false;
	}
}
void storeData(classStudent st[], int n)
{
	ofstream outData;
	outData.open("Student.DAT", ios::out | ios::binary);
	if (!outData.good())
	{
		cout << "file not created";
		return;
	}
	outData.write((char*)&n, sizeof(int));
	outData.write((char*)st, n * sizeof(classStudent));
	outData.close();
}
void loadData(classStudent st[], int& n)
{
	ifstream inData;
	inData.open("Student.DAT", ios::in | ios::binary);
	if (!inData.good())
	{
		cout << "file can't read";
		return;
	}


	inData.read((char*)&n, sizeof(int));
	inData.read((char*)st, n * sizeof(classStudent));




	inData.close();
}
void loadDataPos(classStudent st[], int& n, int pos)
{
	ifstream inFile;
	inFile.open("Student.DAT", ios::in | ios::binary);
	if (!inFile.good())
	{
		cout << "file can't read";
		return;
	}/*inFile.read((char*)&n, sizeof(int));
	inFile.seekg(0, ios::end);
	int endp = inFile.tellg();
	int o = endp / sizeof(classStudent);
	cout << "total persons are : " << o << endl;
	*/

	
	/*inFile.seekg(pos+(n - 1) * sizeof(classStudent),ios::beg);*/
	/*inFile.read((char*)&n, sizeof(int));
	int neg = sizeof(classStudent);
	inFile.seekg(-1, ios::end);
	inFile.read((char*)st, n*sizeof(classStudent));*/


	inFile.read((char*)&n, sizeof(int));
	inFile.read((char*)st, n * sizeof(classStudent));
	inFile.close();
	pos -= 1;
	for (int i = 0; i < n; i++)
	{
		if (i == pos)
		{
			disp();
			st[i].display();
		}
	}
}
void copyFile(string dest)
{
	string line;
	ifstream inFile;
	ofstream outFile;
	outFile.open(dest, ios::out | ios::binary);
	inFile.open("Student.DAT", ios::in | ios::binary);
	
	if (inFile && outFile) {

		while (getline(inFile, line)) {
			outFile << line << "\n";
		}

		cout << "Copy Finished \n";

	}
	else {
		
		cout<<"Cannot read File";
	}
	inFile.close();
	outFile.close();

}

void classStudent::readDataBase()
{
	cout << "enter Roll No" << endl;
	cin >> rollNo;
	cout << "enter Student name" << endl;
	cin.ignore(10, '\n');
	getline(cin, stName);
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
	int n = 0;		 //n max number of students you want to enter 
	int loadPos=0;
	do {

		char option;
		cout << "*****Main Menu*****" << endl;
		cout << "1. Create Data Base" << endl;
		cout << "2. Append Record" << endl;
		cout << "3. Search Record" << endl;
		cout << "4. Update Record" << endl;
		cout << "5. Delete Data" << endl;
		cout << "6. Display Data" << endl;
		cout << "7. Store Data in Disk" << endl;
		cout << "8. Load Data from Disk" << endl;
		cout << "9. Load specific Data from Disk" << endl;
		cout << "c. Copy Source File " << endl;
		cout << "0. Exit" << endl;
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
			for (i = 0; i < n; i++)
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
			for (i = 0; i < n; i++)
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
			for (i = 0; i < n; i++)
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

		for (i = 0; i < n; i++)
		{
			found = st[i].search(rolNo);
			if (found == true)
			{
				for (j = i; j < n - 1; j++)
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


			storeData(st, n);


			break;
		case '8':
			loadData(st, n);
			break;
		case '9':
		{
		cout << "Eneter Position of which you want to load data" << endl;
		cin >> loadPos;
		loadDataPos(st, n, loadPos);
		}
		break;
		case 'c':
		{
			string dest;
		cout << "enter destination address" << endl;
		cin.ignore();
		getline(cin, dest);
		copyFile(dest);
		}
			break;
		case '0':
			exit(0);
			


		}
		system("pause");
		system("cls");
	} while (true);

}

