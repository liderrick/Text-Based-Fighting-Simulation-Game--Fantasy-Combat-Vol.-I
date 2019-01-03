/**************************************************************************************************************
** Program name: Project 3
** Author: Derrick Li
** Date: Feb. 19, 2017
** Description:
** This class implementation file contains the member function definitions for the Game class.
***************************************************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>		// For struct timespec

using std::endl;
using std::cout;
using std::cin;

/***************************************************************************************************************
** Description: The Game class constructor calls on chooseCharacter() functions to prompt user to select
** character for Player 1 and Player 2. Then it calls randomPlayerTurn() to randomly choose who should go first.
***************************************************************************************************************/
Game::Game()
{
	chooseCharacter(1);
	chooseCharacter(2);
	randomPlayerTurn();

	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl << "Press [Enter] to continue.";
	cin.ignore();
}

/***************************************************************************************************************
** Description: The Game class destructor frees the dynamically allocated Creature class objects held in its
** pointer members.
***************************************************************************************************************/
Game::~Game()
{
	delete p1creature;
	p1creature = nullptr;

	delete p2creature;
	p2creature = nullptr;
}

/***************************************************************************************************************
** Description: chooseCharacter() prompts user to select character for Player 1 and Player 2. The function
** takes in an int as an argument to indicate which player the user is selecting the character for -- "1" for
** Player 1 and "2" for Player 2. The user selects the character by inputting the integer corresponding to the
** character after a list of available options shown. The Creature class object is dynamically allocated and
** assigned to the corresponding player's pointer member. The function does not have a return type.
***************************************************************************************************************/
void Game::chooseCharacter(int player)
{
	Creature *character = nullptr;
	bool validInteger = false;
	bool validChoice = false;
	int choice = 0;

	do
	{
		cout << "Choose a character for Player " << player << ":" << endl;
		cout << "1) Vampire" << endl;
		cout << "2) Barbarian" << endl;
		cout << "3) Blue Men" << endl;
		cout << "4) Medusa" << endl;
		cout << "5) Harry Potter" << endl;
		cout << "Choice: ";
		validInteger = inputIntegerValidationV2(choice);

		if (validInteger && choice >= 1 && choice <= 5)
		{
			validChoice = true;

			switch (choice)
			{
			case 1: character = new Vampire();
				break;
			case 2: character = new Barbarian();
				break;
			case 3: character = new BlueMen();
				break;
			case 4: character = new Medusa();
				break;
			case 5: character = new HarryPotter();
				break;
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (validChoice == false);

	if (player == 1)
	{
		p1creature = character;
		character = nullptr;
	}
	else if (player == 2)
	{
		p2creature = character;
		character = nullptr;
	}

	cout << "You have chosen Player " << player << " to be ";
		switch (choice)
		{
		case 1: cout << "Vampire.";
			break;
		case 2: cout << "Barbarian.";
			break;
		case 3: cout << "Blue Men.";
			break;
		case 4: cout << "Medusa.";
			break;
		case 5: cout << "Harry Potter.";
			break;
		}
	cout << endl << endl;
}

/***************************************************************************************************************
** Description: randomPlayerTurn() randomly chooses 1 or 2 and assigns it to the playerTurn data member.
** It represents choosing a random player. The function does not take in any argument and does not have a return type.
***************************************************************************************************************/
void Game::randomPlayerTurn()
{
	playerTurn = rand() % 2 + 1;
}

/***************************************************************************************************************
** Description: nextPlayerTurn() changes the player from 2 to 1 or 1 to 2 when called. It represents advancing
** to the next player in a game. The function does not take in any argument and does not have a return type.
***************************************************************************************************************/
void Game::nextPlayerTurn()
{
	if (playerTurn == 1)
	{
		playerTurn = 2;
	}
	else if (playerTurn == 2)
	{
		playerTurn = 1;
	}
}

/***************************************************************************************************************
** Description: playGame() takes the Creature class objects stored in its pointer members, p1creature and
** p2creature, and battles them until one Creature has no more strength points--at which point the other Creature
** is declared victorious. The Creature's specs are displayed for each player prior to starting the battle.
** For each round of battle, the results are printed to screen (i.e. attack damage rolled, defense points rolled,
** any special ability used). At the end of the battle, a statment is printed to indicate the winner and the user
** is prompted if they would like to play again. The function does not take in any argument and does not have a return type.
***************************************************************************************************************/
void Game::playGame()
{
	int round = 1;
	cout << endl << "Player " << playerTurn << " was randomly chosen to go first." << endl;

	cout << endl << "Player 1:" << endl;
	cout << "   Strength: " << p1creature->getStrength() << endl;
	cout << "   Armor: " << p1creature->getArmor() << endl;
	cout << "   Number of Attack Die: " << p1creature->getNumOfAttackDie() << endl;
	cout << "   Maximum rollable value on Attack Die: " << p1creature->getNumOfSidesOnAttackDie() << endl;
	cout << "   Number of Defense Die: " << p1creature->getNumOfDefenseDie() << endl;
	cout << "   Maximum rollable value on Defense Die: " << p1creature->getNumOfSidesOnDefenseDie() << endl;


	cout << endl << "Player 2:" << endl;
	cout << "   Strength: " << p2creature->getStrength() << endl;
	cout << "   Armor: " << p2creature->getArmor() << endl;
	cout << "   Number of Attack Die: " << p2creature->getNumOfAttackDie() << endl;
	cout << "   Maximum rollable value on Attack Die: " << p2creature->getNumOfSidesOnAttackDie() << endl;
	cout << "   Number of Defense Die: " << p2creature->getNumOfDefenseDie() << endl;
	cout << "   Maximum rollable value on Defense Die: " << p2creature->getNumOfSidesOnDefenseDie() << endl;

	cout << endl << "-----------------------------------------------------------------------------" << endl;
	cout << endl << "Press [Enter] to start the battle!";
	cin.ignore();

	while (p1creature->getStrength() > 0 && p2creature->getStrength() > 0)
	{
		if (playerTurn == 1)
		{
			cout << endl << "Round " << round << ":" << endl;

			cout << endl << "   Player 1:" << endl;
			int attackDamage = p1creature->attack();
			cout << "   Player 1 dealt " << attackDamage << " total damage points." << endl;

			cout << endl << "   Player 2:" << endl;
			p2creature->defend(attackDamage);

			if (p2creature->getStrength() > 0)
			{
				cout << "   Player 2 strength after receiving attack is " << p2creature->getStrength() << "." << endl;
			}
			else
			{
				cout << "   Player 2 has no more strength." << endl;
			}
		}
		else if (playerTurn == 2)
		{
			cout << endl << "Round " << round << ":" << endl;

			cout << endl << "   Player 2:" << endl;
			int attackDamage = p2creature->attack();
			cout << "   Player 2 dealt " << attackDamage << " total damage points." << endl;

			cout << endl << "   Player 1:" << endl;
			p1creature->defend(attackDamage);

			if (p1creature->getStrength() > 0)
			{
				cout << "   Player 1 strength after receiving attack is " << p1creature->getStrength() << "." << endl;
			}
			else
			{
				cout << "   Player 1 has no more strength." << endl;
			}
		}

		// Sleep for 0.5s
		struct timespec req, rem;
		req.tv_sec = 0;
		req.tv_nsec = 500000000;
		nanosleep(&req, &rem);

		round++;
		nextPlayerTurn();
	}

	cout << endl << "-----------------------------------------------------------------------------" << endl;

	if (p1creature->getStrength() > 0)
	{
		cout << endl << "Player 1 is the winner!" << endl;
	}
	else if (p2creature->getStrength() > 0)
	{
		cout << endl << "Player 2 is the winner!" << endl;
	}

	cout << endl << "-----------------------------------------------------------------------------" << endl;

	char playAgain;

	do
	{
		cout << endl << "Would you like to play again [Y/N]? ";
		cin >> playAgain;
		playAgain = toupper(playAgain);
		cin.ignore();

		if (playAgain == 'Y')
		{
			system("clear");
			Game play;
			play.playGame();
		}
		else if (playAgain == 'N')
		{
			cout << endl << "Thank you for playing!";
		}
		else if (playAgain != 'Y' && playAgain != 'N')
		{
			cout << "Invalid choice. Try again." << endl;
		}

	} while (playAgain != 'Y' && playAgain != 'N');
}
