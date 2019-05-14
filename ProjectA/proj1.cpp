#include <iostream>
#include "proj1.h"
using namespace std;

// Default constructor
date2019::date2019()
{
	// sets the values of day and month to 1 1
	d = 1;
	m = 1;
	total_days = 1;
	// this declaration shows we have not added any plus days yet
	plus_m = -1;
	plus_d = -1;

}
// One parameter Constructor to convert days into months and  days
date2019::date2019(int dd) {

	while (dd <= 0 || dd > 365) {
		cout << " Input days are out of range[1, 365]. Please Enter a valid date.";
		cin >> dd;
	}
	total_days = dd;
	m = 1;
	for (int i = 0; i < 12; i++)
	{
		if (dd > max_days[i]) {
			dd -= max_days[i];
			m++;
		}
		else
			break;
	}
	d = dd;

	// this declaration shows we have not added any plus days yet

	plus_m = -1;
	plus_d = -1;
}
// 2 parameter constructor to take valid date in days and month
date2019::date2019(int dd, int mm) {

	int month = mm - 1;
	while (!(month >= 0 && month < 12 && dd>0 && dd <= max_days[month])) {

		cout << " Input date is out of range. \nPlease Enter a valid date in format dd mm:";
		cin >> dd >> mm;
		month = mm - 1;
	}

	d = dd;
	m = mm;
	total_days = total_d();

	// this declaration shows we have not added any plus days yet

	plus_m = -1;
	plus_d = -1;
}

// Setdate function to take valid date in form of days and months
void date2019::setdate(int dd, int mm) {

	int month = mm - 1;
	while (!(month >= 0 && month < 12 && dd>0 && dd <= max_days[month])) {

		cout << " Input date is out of range. \nPlease Enter a valid date in format dd mm:";
		cin >> dd >> mm;
		month = mm - 1;
	}
	d = dd;
	m = mm;
	total_days = total_d();
	plus_m = -1;
	plus_d = -1;

}
// Print function checks whether days are added in the date or not 
// if added then prints both input date and date after adding additional days
// if not then just prints input date
void date2019::print() {

	if (plus_m != -1 || plus_d != -1) {	// condition if additional days are added or not
		cout << endl << plus_days << "  days  after  " << week[(2 + total_days - 1) % 7] << "  " << month[m - 1] << "  " << d << " ,  2019  is  ";

		if (plus_d != -2 || plus_m != -2)	// checks if totals days after addition are in the calender of 2019 or not.
			cout << week[(2 + plus_total_days - 1) % 7] << "  " << month[plus_m - 1] << "  " << plus_d << " ,  2019 ";

		else //if not then prints this
			cout << " not  in  the  calender  of  2019 \n";
	}
	else { // if additional days are not added
		cout << week[(2 + total_days - 1) % 7] << "  " << month[m - 1] << "  " << d << " ,  2019 \n";
	}
}

// overloaded function of ostream operator
ostream& operator<<(ostream&out, const date2019& date) {
	// same logic ad described above in print function

	if (date.plus_m != -1 || date.plus_d != -1) {

		out << endl << date.plus_days << " days  after " << date.week[(2 + date.total_days - 1) % 7] << "  " << date.month[date.m - 1] << "  " << date.d << " ,  2019 is  ";
		
		if (date.plus_d != -2 || date.plus_m != -2)	// checks if totals days after addition are in the calender of 2019 or not.
			out << date.week[(2 + date.plus_total_days - 1) % 7] << "  " << date.month[date.plus_m - 1] << "  " << date.plus_d << " ,  2019 ";
		
		else	//if not then prints this
			out << "not  in  the  calender  of  2019";
	}
	else {	// if additional days are not added
		out << date.week[(2 + date.total_days - 1) % 7] << " " << date.month[date.m - 1] << " " << date.d << ", 2019";
	}
	return out;
}

// function to add days to input date and then converting valid date into month and days
void date2019::plusday(int days) {

	plus_days = days;
	plus_total_days = days + total_d();

	days += +total_d();

	if (plus_total_days <= 0 || plus_total_days > 365) {
		// as a flag to demonstrate that after adding  days, date goes out of range of 2019

		plus_m = -2;
		plus_d = -2;
	}
	else {

		plus_m = 1;
		// to convert days into month and day
		for (int i = 0; i < 12; i++)
		{
			if (days > max_days[i]) {
				days -= max_days[i];
				plus_m++;	// months after converting days 
			}
			else
				break;
		}
		plus_d = days;	// remaining days after converting them to months
	}
}

// total_d function to convert day and month to oonly days
int date2019::total_d() {

	int total = 0;
	for (int i = 1; i < m; i++) {
		total += max_days[i - 1];
	}
	total += d;
	return total;
}

// destructor to run after the object goes out of scope
date2019 ::~date2019()
{
	cout << "Class's been closed successfully." << endl;
}