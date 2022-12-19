/*Question 12:
In this exercise, you will design various classes and write a program to
computerize the billing system of a hospital.
a. Design the class doctorType, inherited from the class
personType, defined in Chapter 12, with an additional data member
to store a doctor’s speciality. Add appropriate constructors and member functions to initialize, access, and manipulate the data members.
b. Design the class billType with data members to store a patient’s ID
and a patient’s hospital charges, such as pharmacy charges for medicine,
doctor’s fee, and room charges. Add appropriate constructors and
member functions to initialize and access and manipulate the data
members.
c. Design the class patientType, inherited from the class
personType, defined in Chapter 12, with additional data members
to store a patient’s ID, age, date of birth, attending physician’s name,
the date when the patient was admitted in the hospital, and the date
when the patient was discharged from the hospital. (Use the class
dateType to store the date of birth, admit date, discharge date, and
the class doctorType to store the attending physician’s name.)
Add appropriate constructors and member functions to initialize,
access, and manipulate the data members.
Muhammad Sharjeel Husnain
4345
compiiler used MS Visual Studio (Community Eddition)

*/
#include <iostream>
#include <string>
using namespace std;
class personType {
	string fName, lName;
public:
	personType(string a = "\0", string b = "\0") :fName(a), lName(b) {}
	void setName();
	void getName();
};
void personType::setName()
{
	cout << "Enter First Name" << endl;
	cin.ignore(3, '\n');
	getline(cin, fName);
	cout << "Enter Last Name" << endl;
	getline(cin, lName);
}
void personType::getName()
{
	cout << "first name : " << fName << endl;
	
		cout << "Last name : " << lName << endl;
}
class doctorType : public personType {

	string specialist, department;
public:
	doctorType() {
		
		specialist = "\0";
		department = "\0";
	}
	void setDoc();
	void getDoc();
};
void doctorType::setDoc() {
	cout << "Enter Doctor's Specialism:" << endl;
	cin.ignore();
	getline(cin, specialist);
	cout << "Enter Doctor's Department:" << endl;

	getline(cin, department);
}
void doctorType::getDoc() {
	cout << "Doctor's Specialism:" << specialist << endl;
	cout << "Doctor's Department:" << department << endl;
}
class dateType {

	unsigned int d1, m1, y1;
	
public:
	dateType() {
		d1  = m1 = y1 = 0;
	}
	void setDate();
	void getDate();
};
void dateType::setDate() {
	cout << "Enter Date dd/mm/yy:" << endl;
	cin >> d1 >> m1 >> y1;
	
}
void dateType::getDate() {
	cout << d1 << "/" << m1 << "/" << y1 << endl;
	
}
class billType {
	float docFee, roomCharges, madicineCharges, total;
public:
	billType() {
		docFee = roomCharges = madicineCharges = total = 0.0;
	}
	void setBill();
	void getBill();
	float totalBill();
};
void billType::setBill()
{
	cout << "Enter Doctor Fees " << endl;
	cin >> docFee;
	cout << "Enter Room Charges " << endl;
	cin >> roomCharges;
	cout << "Enter Madicine Charges:" << endl;
	cin >> madicineCharges;

}
float billType::totalBill()
{
	total = docFee + roomCharges + madicineCharges;
	return total;
}
void billType::getBill()
{
	cout << "Doctor Fees is: " << docFee << endl;
	cout << "Room Charges are " << roomCharges << endl;
	cout << "Madicine Charges are :" << madicineCharges << endl;
	cout << "Total Bill is: " << totalBill() << endl;
}
class patentType :public doctorType
{
	string pId;
	unsigned int age;
public:
	patentType()
	{
		pId = "\0";
		age = 0;
		
	}
	void getPatent();
	void setPatent();
};
void patentType::setPatent() {
	cout << "Enter Patent ID" << endl;
	cin.ignore();
	getline(cin, pId);
	cout << "Enter Patent Age" << endl;
	cin >> age;
}
void patentType::getPatent() {
	cout << "Patent ID is: " << pId << endl;
	cout << "Patent age is :" << age << endl;
}
int main()
{
	dateType DOB,DOA,DOD;
	patentType person;
	billType bill;
	char choice;
	do {
		cout << "Main Menu" << endl;
		cout << "Press 1: Doctor" << endl;
		cout << "Press 2: Patient" << endl;
		cout << "Press 3: Exit" << endl;
		cout << "Select Option:" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Press 1: Set data." << endl;
			cout << "Press 2: Get data." << endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				person.setName();
				person.setDoc();
				break;
			case '2':
				person.getName();
				person.getDoc();
				break;
			}
			break;
		case '2':
			cout << "Press 1: Set data." << endl;
			cout << "Press 2: Get data." << endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				person.setName();
				
				
					person.setPatent();
				cout << "Enter Patent's Doctor Details " << endl;
				person.setName();
				person.setDoc();
				cout << "Enter date of birth" << endl;
				DOB.setDate();
				cout << "Enter date of Admission" << endl;
				DOA.setDate();
				cout << "Enter date of discharge" << endl;
				DOD.setDate();
				bill.setBill();
				break;
			case '2':
				person.getName();
				person.getPatent();
				cout << "Patent's Doctor Details " << endl;
				person.getName();
				person.getDoc();
				cout << " date of birth is" << endl;
				DOB.getDate();
				cout << " date of Admission is " << endl;
				DOA.getDate();
				cout << " date of discharge is" << endl;
				DOD.getDate();
				bill.getBill();

				break;
			}
			break;
		case '3':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (true);
	return 0;
}
