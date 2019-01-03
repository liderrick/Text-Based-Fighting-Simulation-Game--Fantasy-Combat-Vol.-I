/**************************************************************************************************************
** Program name: Project 3
** Author: Derrick Li
** Date: Feb. 19, 2017
** Description:
** This implementation file contains definitions for menu-related functions, including a function
** that seeds the random number generator.
***************************************************************************************************************/

#include "Creature.hpp"
#include "menu.hpp"

#include <iostream>
#include <cstdlib>		//for srand and rand functions
#include <ctime>		//for time functions
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

/***************************************************************************************************************
** Description: setRandomSeed() seeds the random number generator with time(NULL). It should run only once per
** program before any function calls are made to the rand function.
***************************************************************************************************************/
void setRandomSeed()
{
	srand(time(NULL));
}

/***************************************************************************************************************
** Description: mainMenu() function displays the main menu and prompts the user to select an option. The
** input validation ensures a valid option has been chosen. The function returns this integer value.
** It does not take any argument. Revision 06Feb17 to work with inputIntegerValidationV2 function.
***************************************************************************************************************/
int mainMenu()
{
	bool validInteger = false;
	bool validChoice = false;
	int choice = 0;

	do
	{
		cout << endl << "Please select an option:" << endl;
		cout << "1) Play game" << endl;
		cout << "2) Exit" << endl;
		cout << "Choice: ";
		validInteger = inputIntegerValidationV2(choice);

		if (validInteger && choice >= 1 && choice <= 2)
		{
			validChoice = true;
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (validChoice == false);

	return choice;
}

/***************************************************************************************************************
** Description: inputIntegerValidationV2() function validates an integer has been entered. If
** it has, the integer is returned as a reference parameter and true is returned as a bool from the function.
** If not, 0 is returned to its reference parameter and false is returned as a bool from the function.
** Based on original function, inputIntegerValidation. New version can validate negative values. Revision 06Feb17.
***************************************************************************************************************/
bool inputIntegerValidationV2(int &num)
{
	num = 0; //initialize 0 as default

	bool validInteger = false;

	string inputString;
	getline(cin, inputString);

	try
	{
		num = stoi(inputString);
		validInteger = true;
	}
	catch (std::exception const &e)
	{
		validInteger = false;
	}

	return validInteger;
}