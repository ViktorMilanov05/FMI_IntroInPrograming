#include <iostream>
using namespace std;

void time(){
	int hours, minutes;
	cin >> hours >> minutes;
	(minutes += 15) %= 60;
	if (minutes < 15) {
		++hours %= 24;
	}
	if (hours < 10)
		cout << '0';
	cout << hours << ':';
	if (minutes < 10)
		cout << '0';
	cout << minutes;
}