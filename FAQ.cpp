#include <iostream>
//#include <Source.cpp>
using namespace std;


void FAQ();

void main() {
	FAQ();
}

void FAQ() {
	char back;
	cout << "*** Frequently Asked Question ***\n\n";

	cout << "Question : Why the game is frozen?\n";
	cout << "Answer : Check for updates in the application store.\n\n";

	cout << "Question : Why I cannot make a purchase in the game?\n";
	cout << "Answer : Your email is not verified. Verify email of the account.\n\n";

	cout << "Question : What is Error: e-0x512d?\n";
	cout << "Answer : The game is not supported by the device\n\n";

	cout << "Question : Why I didn't receive my coins from advertising videos?\n";
	cout << "Answer : Your game isn't updated. Check for updates.\n\n";

	cout << "Question : What is Error : e-666tx?\n";
	cout << "Answer : Your location is not supported.\n\n";

	cout << "Press B to go back.";
	back = getchar();
	if (back == 'b' || back == 'B') { //back to previous function
		SupportMenu();
	}
}