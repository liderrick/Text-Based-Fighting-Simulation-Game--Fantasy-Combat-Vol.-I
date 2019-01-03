/**************************************************************************************************************
** Program name: Project 3
** Author: Derrick Li
** Date: Feb. 19, 2017
** Description:
** This class specification file contains the Creature base class declaration (an abstract class), as well
** as 5 derived classes as follows: Vampire class, Barbarian class, BlueMen class, Medusa class, and HarryPotter
** class. Each class represents a game character that the user can choose to fight with and has its own
** specifications -- attack potential, defense potential, armor, and strength points. Some classes have special
** abilities.
***************************************************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Die.hpp"

/***************************************************************************************************************
** Description: Creature class. It is an abstract base class. Its data members includes Die class pointers--
** one for attacking (attackDie) and the other for defending (defenseDie), an integer (numOfAttackDie) indicating 
** how many rolls of the attackDie the character gets during an attacking round, an integer (numOfDefenseDie)
** indicating how many rolls of the defenseDie the character gets during a defending round, an integer to indicate
** its armor value, and an integer to indicate its strength. The public member functions includes a constructor
** that initializes the object, a destructor that frees the Die objects held by attackDie and defenseDie, functions
** to get and set strength, a function to attack (i.e. return the sum of the values of the attackDie rolls),
** and a function to defend (i.e. sum the values of the defenseDie rolls and armor. Take this value and
** subtract it from the input damage. If the input damage remains positive, then the character's strength is reduce by this amount).
***************************************************************************************************************/
class Creature
{
protected:
	Die* attackDie;
	Die* defenseDie;

	int numOfAttackDie;
	int numOfDefenseDie;

	int armor;
	int strength;

public:
	Creature();
	virtual ~Creature() = 0;

	int getStrength();
	void setStrength(int inputStrength);

	int getArmor();

	int getNumOfSidesOnAttackDie();
	int getNumOfAttackDie();

	int getNumOfSidesOnDefenseDie();
	int getNumOfDefenseDie();

	virtual int attack();
	virtual void defend(int damage);
};

/***************************************************************************************************************
** Description: Vampire class. A derived class of the Creature base class. It has a constructor that initializes
** the Creature base class data members with its own specifications and a function defend() that overrides
** the function in Creature base class.
** Specifications:
**    Attack: 1 Die - 12 sides
**    Defense: 1 Die - 6 sides
**    Armor: 1
**    Strength: 18
**    Special ability: Charm
**	     When attacked, there is a 50% chance that the Vampire object doesn't receive any damage. 
***************************************************************************************************************/
class Vampire : public Creature
{
public:
	Vampire();
	virtual void defend(int damage) override;
};

/***************************************************************************************************************
** Description: Barbarian class. A derived class of the Creature base class. It has a constructor that initializes
** the Creature base class data members with its own specifications.
** Specifications:
**    Attack: 2 Dies - 6 sides
**    Defense: 2 Dies - 6 sides
**    Armor: 0
**    Strength: 12
**    Special ability: None.
***************************************************************************************************************/
class Barbarian : public Creature
{
public:
	Barbarian();
};

/***************************************************************************************************************
** Description: BlueMen class. A derived class of the Creature base class. It has a constructor that initializes
** the Creature base class data members with its own specifications and a function defend() that overrides
** the function in Creature base class.
** Specifications:
**    Attack: 2 Dies - 10 sides
**    Defense: 3 Dies - 6 sides
**    Armor: 3
**    Strength: 12
**    Special ability: Mob
**	     The defense starts off with 3 Dies. When strength drops to 8, the defense will only have 2 Dies.
**		 And when strength drops to 4, the defense will only have 1 Die.
***************************************************************************************************************/
class BlueMen : public Creature
{
public:
	BlueMen();
	virtual void defend(int damage) override;
};

/***************************************************************************************************************
** Description: Medusa class. A derived class of the Creature base class. It has a constructor that initializes
** the Creature base class data members with its own specifications and a function attack() that overrides
** the function in Creature base class.
** Specifications:
**    Attack: 2 Dies - 6 sides
**    Defense: 1 Die - 6 sides
**    Armor: 3
**    Strength: 8
**    Special ability: Glare
**	     When attaking, if it rolls an attack value of 12. Then the opponent immediately turns to stone and lose
**		 a life.
***************************************************************************************************************/
class Medusa : public Creature
{
public:
	Medusa();
	virtual int attack() override;
};

/***************************************************************************************************************
** Description: HarryPotter class. A derived class of the Creature base class. It has a constructor that initializes
** the Creature base class data members with its own specifications and a function defend() that overrides
** the function in Creature base class.
** Specifications:
**    Attack: 2 Dies - 6 sides
**    Defense: 2 Dies - 6 sides
**    Armor: 0
**    Strength: 10
**    Special ability: Hogwarts
**	     Has an extra life. Once strength decreases to zero or below, the character is automatically revived and strength is
**		 set to 20. This special ability is only able to be used one time.
***************************************************************************************************************/
class HarryPotter : public Creature
{
protected:
	int numOfExtraLives;

public:
	HarryPotter();
	virtual void defend(int damage) override;
};

#endif