#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> 
#include <vector>
#include <Windows.h>


#define INTRO 13
#define BACKSPACE 8
#define ATTEMPTS 3


using namespace std;


int main()
{
	vector<string> users;
	vector<string> passwords;

	users.push_back("Mateusz");
	users.push_back("Dennis");
	users.push_back("Peter");

	passwords.push_back("0001");
	passwords.push_back("password");
	passwords.push_back("enigma");

	string user, password;
	int counter = 0;
	bool successfullogin = false;

	cout << "Welcome!" << endl;
	Sleep(2500);
	system("cls");

	do
	{
		system("cls");
		cout << "Please enter your username: ";
		getline(cin, user);
		system("cls");

		char character;
		cout << "Please enter your password: ";
		character = _getch();

		password = "";

		while (character != INTRO)
		{

			if (character != BACKSPACE)
			{
				password.push_back(character);
				cout << "*";
			}
			else
			{
				if (password.length() > 0)
				{
					//cout << "";
					password = password.substr(0, password.length() - 1);
				}
			}

			character = _getch();
		}

		for (int i = 0; i < users.size(); i++)
		{
			if (users[i] == user && passwords[i] == password)
			{
				successfullogin = true;
				break;
			}
		}

		if (!successfullogin)
		{
			system("cls");
			cout << "The user or password are incorrect, please try again." << endl;
			Sleep(2000);
			counter++;
		}


	} while (successfullogin == false && counter < ATTEMPTS);

	if (successfullogin == false)
	{
		system("cls");
		cout << "You entered wrong login details too many times. Please try logging in later." << endl;
		Sleep(2000);
	}
	else
	{
		system("cls");
		cout << "You have successfully logged in." << endl;
	}

	getchar;

	return 0;

}