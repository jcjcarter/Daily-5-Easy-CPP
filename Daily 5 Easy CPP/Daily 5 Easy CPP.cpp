// Daily 5 Easy CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h> //for getch()
using namespace std;
bool checkLoginInfo(string userUsername, string userPassword);
void commenceWorldDestruction();

int main()
{
	cout << "Welcome to Apature Science Labs." << endl;
	string userUsername, userPassword;

	for (int iii = 0; iii < 5; iii++) //Amount of times they can re-enter information
	{
		cout << "Username: ";
		cin >> userUsername;
		cout << "Password: ";
		cin >> userPassword;

		if (checkLoginInfo(userUsername, userPassword))
		{
			cout << endl << "Hello, " << userUsername << endl;
			cout << "Your last order was to : \"commence world destruction\" " << endl;
			commenceWorldDestruction();
			return 0;
		};

		if (!checkLoginInfo(userUsername, userPassword))
			cerr << "You entered incorrect information. Please try again." << endl << endl;
	}

	cerr << endl << "Max attempts reached." << endl;
	cerr << "Safty measures = world destruction." << endl;
	commenceWorldDestruction();
	return -1;
}

bool checkLoginInfo(string userUsername, string userPassword)
{
	ifstream realUserInfo;
	realUserInfo.open("info.txt");
	string trueUsername, truePassword;

	if (realUserInfo.is_open())
	{
		while (realUserInfo.good())
		{
			getline(realUserInfo, trueUsername);
			getline(realUserInfo, truePassword);
		}
		realUserInfo.close();
	}
	else
	{
		cerr << "Error, could not retrieve info.txt";
		return false;
	}

	if (userUsername == trueUsername && userPassword == truePassword)
	{
		return true;
	}
	else return false;
}

void commenceWorldDestruction()
{
	cout << "World destruction imminent." << endl;
	getch();
	// TODO: endWorld("ATOM_BOMB")
}