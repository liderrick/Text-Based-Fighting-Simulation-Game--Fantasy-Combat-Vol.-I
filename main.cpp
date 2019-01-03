/**************************************************************************************************************
** Program name: Project 3
** Author: Derrick Li
** Date: Feb. 19, 2017
** Description:
** This program is a game that simulates a battle between two characters that the user is prompted to select.
** Each creature has its own specifications and abilities. After the creatures are selected, the game auto-plays
** the battle between the creatures using digital dice (Die class objects) to randomly generate attack and
** defense points. The battle is over when one creature's health/strength reaches zero.
***************************************************************************************************************/

#include "Creature.hpp"
#include "Die.hpp"
#include "Game.hpp"
#include "menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

int main()
{
	setRandomSeed();

	int userChoice = 0;

	system("clear");
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Welcome to FANTASY COMBAT VOL. I" << endl;

	userChoice = mainMenu();

	if (userChoice == 1)
	{
		system("clear");
		Game play;
		play.playGame();
	}

	cout << endl << "Goodbye." << endl << endl;

	return 0;
}