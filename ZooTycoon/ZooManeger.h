#pragma once
#include "Economy.h"
#include "AnimalHappiness.h"
#include "PeopleHappiness.h"
class ZooManeger
{
public:
	ZooManeger();
	~ZooManeger();
	// get from economy the current money
	int getMoney() { return m_economy.getCurrentMoney(); };
	// update the current money 
	void decreaseMoney(int price) { m_economy.decreaseMoney(price); }
	void increaseMoney(int price) { m_economy.increaseMoney(price); }
	void changeMoney(int price) { m_economy.changeMoney(price); }
	// get from happiness the current happiness
	double getAnimalHappiness() { return m_animalHappiness.getCurrentHappiness(); };
	// update the current happiness 
	void updateAnimalHappiness(double amount) { m_animalHappiness.update(amount); };

	double getPeopleHappiness() { return m_peopleHappiness.getCurrentHappiness(); };
	// update the current happiness 
	void updatePeopleHappiness(double amount) { m_peopleHappiness.update(amount); };
	//update number of guests in the zoo
	void updateAmountOfGuests(int number) { m_numberOfVisitors = number; };

private:
	///handles the economy happiness and nuber of people in the intire zoo
	Economy m_economy;
	AnimalHappiness m_animalHappiness;
	PeopleHappiness m_peopleHappiness;
	int m_numberOfVisitors;
};

