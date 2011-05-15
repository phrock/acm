#include <iostream>
using namespace std;

int leapYear(int y)
{
    if ((y%400 == 0) || ((y%4 == 0) && (y%100 != 0))) {
	return 1;
    } else {
	return 0;
    }
}

int daysOfYear(int y) {
    int leap = leapYear(y);
    int m[12] = {31, 28+leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days = 0;
    for (int i=0; i<12; i++) {
	days += m[i];
    }

    return days;
}

int main()
{
    int day1900 = daysOfYear(1900);
    int w = day1900 % 7;

    // int sundays = 0;
    // for (int i=1; i<=100; i++) {
    // 	//	sundays += (31+w)/7;
    // 	sundays += (daysOfYear(1900+i)+w)/7;
    // 	int yearDays = daysOfYear(1900+i);
    // 	w = (yearDays+w) % 7;
    // }

    int sundays = 0;
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i=1; i<=100; i++) {
	int leap = leapYear(1900+i);
	for (int j=0; j<12; j++) {
	    int dm = m[j];
	    if (j == 1) {
		dm += leap;
	    }
	    if ((w+1)%7 == 0) {
		sundays++;
	    }
	    w = (dm+w) % 7;
	}
    }

    cout << sundays << endl;
}
