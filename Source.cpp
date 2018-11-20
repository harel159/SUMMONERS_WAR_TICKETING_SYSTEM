#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
using namespace std;
struct User
{
	string firstname;
	string lastname;
	string username;
	string password;
	string email;
	string gender;
	bool isAdmin;
};
bool isAlpha(char ch) {

		if (!(ch>= 'a' && ch <= 'z' || ch>= 'A' && ch<= 'Z'))
			return false;
	return true;
}
bool isNumerical(char ch) {
	if (!(ch > '0'&&ch <= '9'))
		return false;
	return true;
}
bool isNameValid(string str) {
	int i;
	for (i = 0;i <= (int)str.size()-1;i++) {
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}
bool isUsernameTaken(string str) {
	ifstream myfile;
	string tmp;
	myfile.open("Accounts.txt");
	while (myfile)
	{
		getline(myfile, tmp);
		tmp = tmp.substr(9);
		if (tmp == str)
		{
			myfile.close();
			return false;
		}
		for(int b=0;b<7;b++)
			getline(myfile, tmp);
	}
	myfile.close();
	return true;
}
bool isEmailValid(string adress)
{
	int index;
	string temp;

	if (adress.length() > 100)
		return false;
	index = adress.find('@');
	if (index != adress.find_last_of('@'))
		return false;
	if (index < 1)
		return false;
	temp = adress.substr(adress.length() - 4, 4);
	if ((temp == ".com") || (temp == ".net") || (temp == ".org") || (temp == ".edu"))
		return true;
	return false;
}
bool isUsernameValid(string str) {
	int i;
	for (i = 0;i <= (int)str.size() - 1;i++) {
		if (isAlpha(str[i]) == true|| isNumerical(str[i]) == true)
			continue;
		else
			return false;
	}
	return true;
}
bool isPasswordValid(string str) {
	return isUsernameValid(str);
}
void PrintMainMenu() {
	cout << "*****************************************************************" << endl;
	cout << "*\t\t Welcome to Summoners War \t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "1.Play\n2.Settings\n3.Support\n4.Exit\n";
}
void PlayMenu()
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\t\tSummoners War \t\t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "This is where the player starts to play.\nWe assume the game already exists and do not code it on our own.\n\n";
	cout << "Press any key to continue...";
	getchar();
	system("cls");

}
void SettingsMenu()
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\t\tSummoners War \t\t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "This is where the player adjusts the game's settings.\n\n";
	cout << "Press any key to continue...";
	getchar();
	system("cls");
}
void PrintSupportMenu() {
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\tSummoners War Support System \t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "1.Sign-Up.\n2.Login.\n3.FAQ.\n4.Go back.\n";
}
void LoginMenu()
{

}
bool SignUp()
{
	system("cls");
	string firstname, lastname, username, password, email;
	char gender;

	cout << "*****************************************************************" << endl;
	cout << "*\t\tSummoners War Support-System Sign-Up \t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "First name:";
	cin >> firstname;

	while (isNameValid(firstname) == false){
		cout << "Please use only a~z and A~Z\n";
		cin >> firstname;
}
	cout << "Last name:";
	cin >> lastname;
	while (isNameValid(lastname) == false) {
		cout << "Please use only a~z and A~Z\n";
		cin >> lastname;
	}
	cout << "Username:";
	cin >> username;
	while (isUsernameValid(username)==false|| isUsernameTaken(username) == false) {
		cout << "Something went wrong,please choose a different username!\n";
		cin >> username;
	}
	cout << "Password:";
	cin >> password;
	while (isPasswordValid(password) == false)
	{
		cout << "Please make the password contain only a~z,A~Z and 0~9\n";
		cin >> password;
	}
	cout << "Gender:";
	cin >> gender;
	/*while (gender!='F'||gender!='M')
	{
		cout << "Please choose F/M/ only\n";
		cin >> gender;
	}
	*/
	cout << "Email:";
	cin >> email;
	while (isEmailValid(email) == false) {
		cout << "Invalid Email,please try again.\n";
		cin >> email;
	}
	ofstream myfile;
	myfile.open("Accounts.txt",ios::app);
	myfile << endl << "'''" << endl;
	myfile << "Username:" << username << endl;
	myfile << "Password:" << password << endl;
	myfile << "Firstname:" << firstname << endl;
	myfile << "Lastname:" << lastname << endl;
	myfile << "Email:" << email << endl;
	myfile << "Gender:" << gender << endl;
	myfile << "Admin:" << "N";
	myfile.close();
	return true;
}
void FAQ()
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\t\tSummoners War- FAQ \t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "Question : Why is the game frozen?\n";
	cout << "Answer : Check for updates in the playstore store.\n\n";

	cout << "Question  Why can't I make a purchase in the ingame store?\n";
	cout << "Answer : Make sure your ingame currency is balanced.\n\n";

	cout << "Question : Why am I getting error e-0x512d?\n";
	cout << "Answer : It means your device does not support our game.\n\n";

	cout << "Question : Why didn't I receive my coins from the advertising videos?\n";
	cout << "Answer : Restart the game,once you do the coins would be added.\n\n";

	cout << "Question : Why am I getting error e-666tx?\n";
	cout << "Answer : It means your data files are corrupted, re-downloaded the game from the playstore.\n\n";

	cout << "Press any key to continue...";
	getchar();
}
void SupportMenu()
{
	PrintSupportMenu();
	cout << "Please enter an option (1~4)\n";
	int choice = 0;
	while (choice != 4)
	{

		PrintSupportMenu();
		cout << "Please enter an option (1~4)\n";
		cin>>choice;
		getchar();
		switch (choice) {
		case 1: {
			if (SignUp() == true)
			{
				cout << "Registration complete! Press any key to continue.\n";
				system("pause");
			}
			continue;
		}
		case 2: {
			LoginMenu();
			break;
		}
		case 3: {
			FAQ();
			break;
		}
		case 4: {
			system("cls");
			break;
		}
		default: printf("Invalid.");
			continue;
		}
	}
}
void MainMenu() {
	int choice = 0;
	while (choice != 4)
	{

		PrintMainMenu();
		cout << "Please enter an option (1~4)\n";
		cin>>choice;
		getchar();
		switch (choice) {
		case 1: {
			PlayMenu();
			continue;
		}
		case 2: {
			SettingsMenu();
			break;
		}
		case 3: {
			SupportMenu();
			break;
		}
		case 4: {
			printf("Goodbye.\n");
			cout << "Press any key to continue...";
			getchar();
			break;
		}
		default: cout<<"Invalid. ";
			cout << "Please re-enter.";
			getchar();
			system("cls");
			continue;
		}
	}
}
int main() {
	MainMenu();
}