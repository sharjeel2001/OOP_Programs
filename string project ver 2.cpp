#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 80

class myString
{
	char str[SIZE];
public:
	myString() {
		str[SIZE] = NULL;
	
	}
	void strIn();
	void strOut();
	void strStat();
	int mystrlen();
	int strSearch(myString);
	void strdel(int, myString,int,int);
	void strcat(myString, int , int );


};
void myString::strcat(myString st,int l1,int l2)
{ 
	if(l1+l2>SIZE)
	
		cout << "Warning!!! Maximum limit exceeded " << endl;
	else {
		for (int i = 0; i <= l2; i++)
			str[l1 + i] = st.str[i];
	}
}
void myString::strIn()
{

	cin.ignore(5, '\n');
	cin.get(str, SIZE);




}
void myString::strOut()
{
	cout << str << endl;
}

int myString::mystrlen()
{
	int i;
	for (i = 0; str[i] != '\0';)
	{
		i++;
	}return i;
}

void myString::strStat()
{
	int upper = 0, lower = 0, number = 0, special = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		else if (str[i] >= '0' && str[i] <= '9')
			number++;
		else
			special++;
	}
	cout << "Upper case letters: " << upper << endl;
	cout << "Lower case letters : " << lower << endl;
	cout << "Number : " << number << endl;
	cout << "Special characters : " << special << endl;
}
void myString::strdel(int pos,myString st, int l1, int l2)
{
	
	for (int i = pos + l2;i <= l1;i++)
		str[pos++] = str[i];
}
int myString::strSearch(myString st)
{
	int index = 0;
	int i = 0, j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == st.str[j])
		{
			index = i;
			while (str[i] == st.str[j])
			{
				i++;
				j++;
				if (st.str[j] == '\0')
					return index;
			}
		}
		j = 0;
	}
	return -1;
}
int main()
{
	int found = 0;
	do {
		myString string1,string2;
		char choice;

		cout << "Press 1 : SET String" << endl;
		cout << "press 2 : Display String" << endl;
		cout << "press 3 : Size of String" << endl;
		cout << "press 4 : Statitics of String" << endl;
		cout << "press 5 : Searching String" << endl;
		cout << "press 6 : Delete String"<<endl;
		cout << "press 7 : cancatinate 2 Strings"<<endl;
		cout << "press 8 : exit" << endl;


		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "enter string 1" << endl;
			string1.strIn();
			
			break;
		case '2':
			cout << "string 1" << endl;
			string1.strOut();
			
			break;

		case '3':
			cout<<string1.mystrlen()<<endl;
			break;
		case '4':
			string1.strStat();
			break;
		case '5':

			cout << "Enter string you want to search" << endl;
			string2.strIn();
			
			found = string1.strSearch(string2);
			if (found != -1)
				cout << "Found At" << found << endl;
			else
				cout << "not found" << endl;
			break;
		case'6':
		{
			int pos = 0;
			cout << "Enter string you want to delete" << endl;
			string2.strIn();
			pos = string1.strSearch(string2);
			int l1, l2;
			l1=string1.mystrlen();
			l2 = string2.mystrlen();
			if (pos != -1) {
				string1.strdel(pos, string2,l1,l2);
				cout << "Deleted!" << endl;
			}
			else
				cout << "Not Found" << endl;
			break;
		}
		
		case '7':// cancatitation
			cout << "Enter string you want to cancatinate" << endl;
			string2.strIn();
			int l1, l2;
			l1 = string1.mystrlen();
			l2 = string2.mystrlen();
			string1.strcat(string2,l1,l2);
			break;
			
		case '8':
			exit(0);


		}
		system("pause");
		system("cls");
	} while (true);
	return 0;
}