#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

using namespace std;
struct report
{
	string userName;
	string code;
	string describeYourIssue;
	string reason;
	string description;
	string status;
	string deparment;
	string date;
}typedef Report;
bool  check_file(ifstream &f)
{
	if (f.fail())
		return false;
	return true;
}
Report saveTicketData(ifstream &f, Report &tmpTicket)
/*
param1:reference to the working file
param2:reference to tmp ticket
return:tmp ticket from file
raise:
*/
{
	string line;
	getline(f, tmpTicket.code);
	getline(f, tmpTicket.userName);
	getline(f, tmpTicket.describeYourIssue);
	getline(f, tmpTicket.reason);
	getline(f, tmpTicket.description);
	getline(f, tmpTicket.status);
	getline(f, tmpTicket.deparment);
	getline(f, tmpTicket.date);
	getline(f, line);
	return tmpTicket;
}
void skipLines(istream& f, int linesSize)
/*
param1:reference to the working file
param2:int the number of lines to skip
return:none
raise: 
*/
{
	std::string s;
	for (; linesSize; --linesSize)
		getline(f, s);
}
int getNumberFileLines(ifstream &f)	
/*
param1:reference to the working file
return:number on lines in the file
raise: reset the cur file to beg
*/
{
	f.seekg(0, ios::beg);
	int count = 0;
	string line;
	while (!f.eof())
	{
		count++;
		getline(f, line);
	}
	f.seekg(0, ios::beg);
	return count;
}

void printTicket(Report tick)
/*
param1:ticket struct
return:none
raise:none
*/
{
	string line;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << tick.code  << endl << tick.userName << endl << tick.describeYourIssue << endl;
	cout << tick.reason << endl << tick.description << endl << tick.status << endl;
	cout << tick.deparment << endl << tick.date << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void printPrevCases(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\t Previous cases \t\t\t" << endl;
	cout << "*****************************************************************" << endl;
	string str,line;
	int count=0;
	Report tmpTicket;
	while (!f.eof())
	{
		f.seekg(0, ios::beg);
		skipLines(f,count);
		saveTicketData(f, tmpTicket);
		if (tmpTicket.status== "Status:In Attention")
			printTicket(tmpTicket);
		count += 9;
	}
	f.seekg(0, ios::beg);
}
void printNewCases(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << "*\t\t New cases \t\t\t" << endl;
	cout << "*****************************************************************" << endl;
	string str, line;
	int count = 0;
	Report tmpTicket;
	while (!f.eof())
	{
		f.seekg(0, ios::beg);
		skipLines(f, count);
		saveTicketData(f, tmpTicket);
		if (tmpTicket.status != "Status:In Attention")
			printTicket(tmpTicket);
		count += 9;
	}
	f.seekg(0, ios::beg);
}
void searchAndPrintByCode(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	string code ,line;
	Report tmpTicket;
	int count = 0;
	cout << "*****************************************************************" << endl;
	cout << "Enter the desirabled ticket by code: " << endl;
	cout << "*****************************************************************" << endl;
	cin >> code;
	code = "Code:" + code;
	while (!f.eof())
	{
		f.seekg(0, ios::beg);
		skipLines(f, count);
		saveTicketData(f, tmpTicket);
		if (tmpTicket.code == code)
		{
			printTicket(tmpTicket);
			break;
		}
		count += 9;
		if (f.eof())	/*	if next hitteration the loop will break	*/
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			cout << "There no ticket with entered Code" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return;
		}
	}
	f.seekg(0, ios::beg);
}
void searchAndPrintByUserName(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	string userName, line;
	Report tmpTicket;
	bool ifFoundOne = false;
	int count = 0;
	cout << "*****************************************************************" << endl;
	cout << "Enter the desirabled ticket by Username: " << endl;
	cout << "*****************************************************************" << endl;
	cin >> userName;
	userName = "Username:" + userName;
	while (!f.eof())
	{
		f.seekg(0, ios::beg);
		skipLines(f, count);
		saveTicketData(f, tmpTicket);
		if (tmpTicket.userName == userName && tmpTicket.status=="Status:In Attention")
		{
			printTicket(tmpTicket);
			ifFoundOne = true;
		}
		count += 9;
		if (f.eof() && ifFoundOne == false)	/*	if next hitteration the loop will break	*/
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			cout << "There no ticket with entered Username" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return;
		}
	}
	f.seekg(0, ios::beg);
}
void prevCasesOptions(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	bool flag = true;
	int choice;
	while (flag)
	{
		cout << "*****************************************************************" << endl;
		cout << "1) Search by 'code' " << endl << "2) Search by Username" << endl << "3) back" << endl;
		cout << "*****************************************************************" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:// Search by 'code'
		{
			searchAndPrintByCode(f);
			break;
		}
		case 2: // Search by Username"
		{
			searchAndPrintByUserName(f);
			break;
		}
		case 3: // back
		{
			flag = false;
			return;
		}
		default:
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			cout << " you entered an unavilable choice try again" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		}
	}
}
void changeStatus(ifstream &f, Report report)
/*
param1:reference to the working file
param2:struct of tmp ticket
return:none
raise:none
*/
{
	string line,trash;
	int sizeOfFile=getNumberFileLines(f); 
	/*skipLines(f, curLine);*/
	string *data = new string[sizeOfFile];
	//*data = new char[256];
	for (int i = 0; (!f.eof()); i++)
	{
		getline(f, line);
		if (line == report.code)
		{
			data[i] = line;
			getline(f, data[i + 1]);
			getline(f, data[i + 2]);
			getline(f, data[i + 3]);
			getline(f, data[i + 4]);
			getline(f, trash);	/*old*/
			data[i + 5] = "Status:In Attention"; /*new*/
			getline(f, data[i + 6]);
			getline(f, data[i + 7]);
			getline(f, data[i + 8]);
			i += 8;
			continue;
		}
		data[i] = line;
	}
	ofstream temp;
	temp.open("temp.txt");
	for (int i = 0; i < sizeOfFile; i++)
	{
		temp << data[i] << endl;
	}
	f.close();
	temp.close();
	remove("Tickets.txt");
	rename("temp.txt", "Tickets.txt");
	f.seekg(0, ios::beg);
}
void changeStatusMenu(ifstream &f)
/*
param1:reference to the working file
return:none
raise:none
*/
{
	string code, line;
	Report tmpTicket;
	int count = 0;
	cout << "*****************************************************************" << endl;
	cout << "Enter the 'Code' of the report-status you want to change:" << endl;
	cout << "*****************************************************************" << endl;
	cin >> code;
	code = "Code:" + code;
	while (!f.eof())
	{
		f.seekg(0, ios::beg);
		skipLines(f, count);
		saveTicketData(f, tmpTicket);
		if (tmpTicket.code == code && tmpTicket.status=="Status:Received")
		{
			changeStatus(f, tmpTicket);
			break;
		}
		count += 9;
		if (f.eof())	/*	if next hitteration the loop will break	*/
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			cout << "error : there no ticket with entered Code" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		}
	}
	f.seekg(0, ios::beg);
}
int main()
{
	int choice;
	bool flag = true;
	ifstream ticketsFile("Tickets.txt");
	/*	try open file Tickets.txt	*/
	try
	{
		if (!check_file(ticketsFile))
			throw "error:couldnt open file.. ";
	}
	catch (char* str)
	{
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 4);
		cout << str << endl;
		SetConsoleTextAttribute(hConsole, 7);
		return 0;
	}
	while (flag)
	{
		cout << "*****************************************************************" << endl;
		cout << "*\t\t Admin manu \t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "1) Previous cases " << endl << "2) New cases" << endl << "3) back" << endl;
		cout << "*****************************************************************" << endl;
		cin>>choice;
		switch (choice)
		{
		case 1:// the admin choce go to previous cases
		{
			printPrevCases(ticketsFile);
			prevCasesOptions(ticketsFile);
			break;
		}
		case 2: // the admin choce to see new cases
		{
			printNewCases(ticketsFile);
			changeStatusMenu(ticketsFile);
			break;
		}
		case 3: // the admin choce to go to the previous screen
		{
			flag = false;
			return 0;
		}
		default:
		{
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			cout << "eroor:you entered an unavilable choice try again" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		}
	}
	system("pause");
	return 0;
}