#include <iostream>
#include <string>
using namespace std;

class date2019	//class of calender 2019
{
	friend ostream& operator<<(ostream&out, const date2019& date);	// to overload ostream operator

private:

	// private data members for accessing date and addng days to it
	int d, m, total_days, plus_d, plus_m, plus_days, plus_total_days;
public:

	int max_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };	// number of days in each month

	// array containng names of months
	string month[12] = { "January","February","March", "April","May", "June", "July", "August", "September", "October", "November", "December" };
	
	// array containing days in a week
	string week[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday" };
	
	// prototypes of the constructors & data functions
	date2019();	// default constructor
	
	date2019(int dd); // days parameterized constructor
	
	date2019(int dd, int mm); // days and month parameterized constructor
	
	void setdate(int dd, int mm);	// data function to enter a valid date
	
	void print();	// data function to print the date in given format
	
	void plusday(int days);	// data function to add days to the input date
	
	int total_d();	// a data function to convert months into days
	
	~date2019();	// a destructor 
};

