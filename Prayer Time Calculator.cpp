//Program to Calculate Prayers Time
//Programmer Name: Muhammad Sharjeel Husnain
//Compilation Date:28/12/2022
//Compiler used: Microsoft visual Studio(Community Eddition)
//Student of Software Engineering 3rd Smeaster (International Islamic University,Islamabad)
//everyone can use This Code without permission
//Remember me in your Prayers





#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
double rangingValues(double value); //to keep value between 360 and 0
double rangingHour(double value); // to keep hours <24
void convertintoHourMin(double number, int& hours, int& minutes); //to convert time into hh:mm
double degToRad(double degree); // to convert degree into radian
double radToDeg(double radian);  //to convert radian into deggree
void mainMenu();
void prayerName();
class prayerTime {
private:
	double julianDate;
	double L, M, lambda, obliquity, alpha, ST, dec, Durinal_Arc, Noon, UT_Noon;//specific attributes for Calculating Prayer Time provided by Islamic Research Centeres
	double asarAlt, asarArc; // for Asar Time calculation
	double fajarArc;//for Fajar Time calculation
	double eshaArc;//for esha Time calculation
	double fajar, sunRise, zuhr, asar, magrib, esha;

public:
	void calculatingAttributes(int, int, int, double, double, int);
	double fajarTime(double, double);
	double sunRiseTime();
	double zuhrTime();
	double asarTime(double, int);
	double magribTime();
	double eshaTime(double, double);

};
void prayerTime::calculatingAttributes(int year, int month, int day, double lat, double lon, int timeZone)//All formulas are collected from http://praytimes.org/
{
	julianDate = (367 * year) - ((year + (int)((month + 9) / 12)) * 7 / 4) + (((int)(275 * month / 9)) + day - 730531.5); //Formula of converting date to Julian Date
	L = 280.461 + 0.9856474 * julianDate;
	L = rangingValues(L); //Function for keep value between 0-360

	M = 357.528 + (0.9856003) * julianDate;
	M = rangingValues(M);   //Function for keep value between 0-360

	lambda = L + 1.915 * sin(degToRad(M)) + 0.02 * sin(degToRad(2 * M));  //converting degree into radian
	lambda = rangingValues(lambda);    //Function for keep value between 0-360

	obliquity = 23.439 - 0.0000004 * julianDate;
	alpha = radToDeg(atan((cos(degToRad(obliquity)) * tan(degToRad(lambda))))); //converting degree to radian & radian to degree
	alpha = rangingValues(alpha);  //Function for keep value between 0-360

	alpha = alpha - (360 * (int)(alpha / 360));
	alpha = alpha + 90 * (floor(lambda / 90) - floor(alpha / 90));//floor is predefined in headerfile cmath, to get maximum integer value without decimal

	ST = 100.46 + 0.985647352 * julianDate;
	dec = radToDeg(asin(sin(degToRad(obliquity)) * sin(degToRad(lambda))));
	Durinal_Arc = radToDeg(acos((sin(degToRad(-0.8333)) - sin(degToRad(dec)) * sin(degToRad(lat))) / (cos(degToRad(dec)) * cos(degToRad(lat)))));//converting degree to radian & radian to degree

	Noon = alpha - ST;
	Noon = rangingValues(Noon);


	UT_Noon = Noon - lon;
	zuhr = UT_Noon / 15 + timeZone; //calculating zuhr time in this functon because we need it in every other function


}


double prayerTime::sunRiseTime() {
	sunRise = zuhr - (Durinal_Arc / 15);
	return sunRise;
}
double prayerTime::zuhrTime()
{

	return zuhr;
}
double prayerTime::asarTime(double lat, int onetwo)
{
	asarAlt = radToDeg(atan(onetwo + tan(degToRad(lat - dec))));
	asarArc = radToDeg(acos((sin(degToRad(90 - asarAlt)) - sin(degToRad(dec)) * sin(degToRad(lat))) / (cos(degToRad(dec)) * cos(degToRad(lat)))));
	asarArc = asarArc / 15;
	asar = zuhr + asarArc;
	return asar;
}
double prayerTime::magribTime()
{
	magrib = zuhr + (Durinal_Arc / 15);
	return magrib;
}
double prayerTime::fajarTime(double lat, double fajarTwilight)
{
	fajarArc = radToDeg(acos((sin(degToRad(fajarTwilight)) - sin(degToRad(dec)) * sin(degToRad(lat))) / (cos(degToRad(dec)) * cos(degToRad(lat)))));
	fajar = zuhr - (fajarArc / 15);
	return fajar;
}
double prayerTime::eshaTime(double lat, double eshaTwilight)
{
	double Esha_Arc = radToDeg(acos((sin(degToRad(eshaTwilight)) - sin(degToRad(dec)) * sin(degToRad(lat))) / (cos(degToRad(dec)) * cos(degToRad(lat)))));

	esha = zuhr + (Esha_Arc / 15);
	return esha;
}


void displaySeharIftaarTimings() {
	// Location: Islamabad, Pakistan
	double latitude = 33.6844;
	double longitude = 73.0479;
	int timeZone = +5;

	ofstream output("Sehar_Iftaar_Timings.txt");
	output << "Sehar and Iftaar Timings for Islamabad, Pakistan\n\n";

	for (int day = 23; day <= 22 + 31; day++) {
		int month = (day <= 31) ? 3 : 4;
		int date = day % 31;
		if (date == 0) date = 31;
		double fajarTwilight = -18;


		prayerTime pt;
		pt.calculatingAttributes(2023, month, date, latitude, longitude, timeZone);
		double sehar = pt.fajarTime(latitude, fajarTwilight);
		double iftaar = pt.magribTime();

		int seharHour, seharMin, iftaarHour, iftaarMin;
		convertintoHourMin(sehar, seharHour, seharMin);
		convertintoHourMin(iftaar, iftaarHour, iftaarMin);

		output << setw(2) << setfill('0') << date << "-" << setw(2) << setfill('0') << month << "-2023: "
			<< setw(2) << setfill('0') << seharHour << ":" << setw(2) << setfill('0') << seharMin << " am"
			<< "   "
			<< setw(2) << setfill('0') << iftaarHour << ":" << setw(2) << setfill('0') << iftaarMin << " pm"
			<< endl;
	}

	output.close();
	cout << "Sehar and Iftaar timings for Islamabad, Pakistan from 23 March 2023 to 22 April 2023 have been saved in Sehar_Iftaar_Timings.txt" << endl;
}

int main()    //main Function
{

	prayerTime p;
	int hour, min, date, month, year, fajarTwilight, eshaTwilight, hs, timeZone; //hs for shaafi and hanafi
	double latitude, longitude;
	char choice;
	do {
		mainMenu();
		cin >> choice;
		switch (choice)
		{
		case '1': //for hanafi
			hs = 2;
			break;
		case '2': //for shaafi
			hs = 1;
			break;
		case '3': //Calculating Time for Islamabad
			/*latitude = 33.6844, longitude = 73.0479, fajarTwilight = -18, eshaTwilight = -18, timeZone = 5, hs = 2;*/
			displaySeharIftaarTimings();
			break;

		case '4':
			exit(-1);
		}

		if (choice != '3') {
			cout << "Enter date/month/year" << endl;
			cin >> date >> month >> year;
			cout << "enter latitude" << endl;
			cin >> latitude;
			cout << "enter longitude" << endl;
			cin >> longitude;
			cout << "enter fajar Twilight (for Pakistan or India enter -18)" << endl;
			cin >> fajarTwilight;
			cout << "enter esha twilight (for Pakistan or India enter -18)" << endl;
			cin >> eshaTwilight;
			cout << "Enter Time Zone" << endl;
			cin >> timeZone;
		}
		p.calculatingAttributes(year, month, date, latitude, longitude, timeZone);
		system("pause");
		system("cls");
		prayerName();
		convertintoHourMin(p.fajarTime(latitude, fajarTwilight), hour, min);
		cout << hour << ":" << min << "\t";

		convertintoHourMin(p.sunRiseTime(), hour, min);
		cout << hour << ":" << min << "\t";

		convertintoHourMin(p.zuhrTime(), hour, min);
		cout << hour << ":" << min << "\t";

		convertintoHourMin(p.asarTime(latitude, hs), hour, min);
		cout << hour << ":" << min << "\t";

		convertintoHourMin(p.magribTime(), hour, min);
		cout << hour << ":" << min << "\t";

		convertintoHourMin(p.eshaTime(latitude, eshaTwilight), hour, min);
		cout << hour << ":" << min << endl;

		system("pause");
		system("cls");
	} while (true);



	return 0;

}
double rangingValues(double value)
{
	while (value > 360 || value < 0)
	{
		if (value > 360)
			value -= 360;

		else if (value < 0)
			value += 360;
	}

	return value;

}
double rangingHour(double value)
{
	while (value > 24 || value < 0)
	{
		if (value > 24)
			value -= 24;

		else if (value < 0)
			value += 24;
	}

	return value;
}
void convertintoHourMin(double number, int& hours, int& minutes)
{
	hours = floor(rangingHour(number));
	minutes = floor(rangingHour(number - hours) * 60);
}
double degToRad(double degree)
{
	return ((3.1415926 / 180) * degree);
}
double radToDeg(double radian)
{
	return (radian * (180 / 3.1415926));
}
void mainMenu() {
	cout << "In the name of Allah, the Most Gracious, the Most Merciful\n"
		<< "*****************Prayer Time Calculator******************\n"
		<< "*********************Main Menu***************************\n"
		<< "			1. Hanafi                           \n"
		<< "			2. Shaafi                           \n"
		<< "			3. Display Time for Islamabad       \n"
		<< "			4. Exit" << endl;
}
void prayerName() {
	cout << "Fajar\tSunRise\tDhuhr\tAsar\tMaghrib\tEsha" << endl;
}