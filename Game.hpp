/**************************************************************************************************************
** Program name: Project 3
** Author: Derrick Li
** Date: Feb. 19, 2017
** Description:
** This class specification file contains the Game class declaration. It represents a game between two Creatures.
** Its private members consists of a pointer to Player 1's Creature object, a pointer to Player 2's Creature object,
** and an int (playerTurn) to hold the status of which player's turn it is. Its public members include a
** constructor and destructor, a function to choose character for either Player 1 or Player 2, a function
** to randomly choose a Player to go first, a function to advance to the next Player, and a function to play
** the game.
***************************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Creature.hpp"
#include "menu.hpp"

class Game
{
private:
	Creature* p1creature;
	Creature* p2creature;
	int playerTurn;

public:
	Game();
	~Game();

	void chooseCharacter(int player);

	void randomPlayerTurn();
	void nextPlayerTurn();

	void playGame();
};

#endif