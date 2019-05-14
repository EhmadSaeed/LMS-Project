#include <iostream>
#include <fstream>
#include "proj1.h"
using namespace std;

int main() {
	ifstream input;		// ifstream variable to take input from the file

	int d, m, ps;		// variables to store date and to pass them to the functions
	date2019  date;
	input.open("file.txt");		//opening the input file
	if (input.is_open()) {

		while (!input.eof()) {		// to run the loop till end of line

			input >> m;
			input >> d;
			input >> ps;

			date.setdate(d, m);		//setting date and validating it

			date.plusday(ps);	 // adding extra days 

			cout << date << endl;
			//date.print();	// print the date
		}
	}
	input.close();	//closing the input file
	/*cout << " Enter days to convert it in Calender format: ";
	cin >> day;
	date2019 d1(day);	// d1 operates with one parameter constructor
	d1.print();
	cout << "\n Enter days to add it to the date:";
	cin >> plusday;
	d1.plusday(plusday);	// adding plusday to the date
	cout << d1 << endl;

	// Entering the date in setdate() in (dd, mm) format
	cout << " Enter month of the date: ";
	cin >> month;
	cout << " Enter date of the month: ";
	cin >> day;
	d2.setdate(day, month);
	cout << d2 << endl;
	cout << " Enter days to add it to the date: ";
	cin >> plusday;
	d2.plusday(plusday);
	cout << d2;*/
	cout << endl;
	system("pause");
	return 0;
}