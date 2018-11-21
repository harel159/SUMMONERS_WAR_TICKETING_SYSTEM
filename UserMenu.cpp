#include <iostream>
using namespace std;

void UserMenu();

void main() {
	UserMenu();
}

void UserMenu() {
	int choice = 0;
	do {
		cout << "Enter one of the following: \n\n";
		cout << "1.Report a problem\n";
		cout << "2.View ticket history\n";
		cout << "3.Back to User login\n";
		cin >>  choice;
		switch (choice) {
		case 1:
			cout << "Report a problem\n";
			break;
		case 2:
			cout << "View ticket history\n";
			break;
		case 3:
			cout << "Back to User login\n";
			//UserLogin();
			break;
		}
	} while (1);
}