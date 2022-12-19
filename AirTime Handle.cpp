//Muhammad Sharjeel Husnain
//Program for storing departure & Arrival time of Flights
//It get time from system
#include <iostream>
#include<iomanip>
#include <string>
#include <ctime>
using namespace std;

class airTime {
private:
	unsigned int hour, min, sec;

public:
	airTime(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}
	void setTimeAuto();
	void setTimeManual();
	void displayTime();
	airTime operator-(airTime& dif);
	airTime operator+(airTime& dif);
	void rangingTime();
	void operator++();
	airTime operator--(int);
	bool operator>=(airTime& t);


};
bool airTime::operator>=(airTime& t)
{
	if (hour >= t.hour)
		return true;
	else if (hour == t.hour && min >= t.min)
		return true;
	else if (hour == t.hour && min == t.min && sec >= t.sec)
		return true;
	else
		return false;

}
void airTime::operator++()  //pre increment
{
	
	++hour;
	++min;
	++sec;
	
}
airTime airTime::operator--(int) //post decrement
{
	airTime temp;
	temp.hour = hour--;
	temp.min =min--;
	temp.sec = sec--;
	return temp;
}

void airTime::rangingTime()
{
	min = min + sec / 60;
	sec = sec % 60;
	hour = hour + min / 60;
	min = min % 60;
	hour = hour % 24;
}
airTime airTime::operator-(airTime& dif)
{
	airTime temp;
	temp.hour = hour - dif.hour;
	temp.min = min - dif.min;
	temp.sec = sec - dif.sec;

	return temp;

}
airTime airTime::operator+(airTime& dif)
{
	airTime temp;
	temp.hour = hour + dif.hour;
	temp.min = min + dif.min;
	temp.sec = sec + dif.sec;
	temp.rangingTime();
	return temp;

}
void airTime::setTimeAuto()
{
	time_t tim = time(0);
	tm* tmp = localtime(&tim);
	hour = tmp->tm_hour;
	min = tmp->tm_min;
	sec = tmp->tm_sec;
}
void airTime::setTimeManual()
{
	cout << "Enter Time hh/mm/sec " << endl;
	cin >> hour >> min >> sec;
}
void airTime::displayTime()
{

	cout << setw(2) << setfill('0') << hour << "/" 
		 << setw(2) << setfill('0') << min << "/" 
		 << setw(2) << setfill('0') << sec << endl;

}
int main()
{
	airTime arr, dep, T3;
	char choice;
	do {


		cout << "Main menu" << endl;
		cout << "1. Arrival Time" << endl;
		cout << "2. Departure Time" << endl;
		cout << "3. Stay Time" << endl;
		cout << "4. Add Time" << endl;
		cout << "5. pre increment" << endl;
		cout << "6. post decrement" << endl;
		cout << "7. compare" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{

		case '1':
		{

			cout << "1. Set Time" << endl;
			cout << "2. Display Time" << endl;
			cout << "Enter your choice" << endl;
			cin >> choice;
			switch (choice)
			{


			case '1':
			{
				cout << "1. Get time from system" << endl;
				cout << "2. Enter Time Manualy" << endl;
				cout << "Enter your choice" << endl;
				cin >> choice;
				switch (choice)
				{
				case '1':
					cout << "ARrival Time is saved" << endl;
					arr.setTimeAuto();
					break;
				case '2':

					arr.setTimeManual();
					cout << "ARrival Time is saved" << endl;
					break;
				}


				break;
			}


			case '2':
			{
				cout << "Arrival time" << endl;
				arr.displayTime();
				break;
			}

			}}break;
		case '2':
		{

			cout << "1. Set Time" << endl;
			cout << "2. Display Time" << endl;
			cout << "Enter your choice" << endl;
			cin >> choice;
			switch (choice)
			{

			case '1':
			{
				cout << "1. Get time from system" << endl;
				cout << "2. Enter Time Manualy" << endl;
				cout << "Enter your choice" << endl;
				cin >> choice;
				switch (choice)
				{

				case '1':
					cout << "ARrival Time is saved" << endl;
					dep.setTimeAuto();
					break;
				case '2':

					dep.setTimeManual();
					cout << "ARrival Time is saved" << endl;
					break;
				}
				break;
			}
			case '2':
			{
				cout << "departure time" << endl;
				dep.displayTime();
				break;
			}
			}break;
		}
		case '3':
			T3 = dep - arr;
			cout << "Flight stayed for: " << endl;;
			T3.displayTime();
			break;
		case '4':
			T3 = dep + arr;
			cout << "Total Time" << endl;
			T3.displayTime();
			break;
		case '5':
			++T3;
			T3.displayTime();

			break;
		case '6' :
			T3--;
			T3.displayTime();
			break;
		case '7':
			if (arr >= dep)
				cout << "yes arr>=dep" << endl;
			else
				cout << "no arr<dep" << endl;
			break;
		case '8':
			exit(0);
			break;
		}
		system("pause");
		system("cls");
	} while (true);
	return 0;

}
