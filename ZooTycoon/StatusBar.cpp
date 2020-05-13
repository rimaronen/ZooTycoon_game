#include "StatusBar.h"
#include "GameResources.h"
#include <string>
#include <fstream>
#include <sstream>
StatusBar::StatusBar()
	:m_statusBarTexture(GameResources::instance().getStatusBarTexture())
	, m_statusBarHappinessTexture(GameResources::instance().getStatusHappinnesBarTexture())
{
	m_rect->setTexture(m_statusBarTexture);
	m_rect->setSize(sf::Vector2f(600, 70));
	m_rect->setPosition(sf::Vector2f(500,10));
	m_rectHappiness->setTexture(m_statusBarHappinessTexture);
	m_rectHappiness->setSize(sf::Vector2f(500, 100));
	m_rectHappiness->setPosition(sf::Vector2f(1050,600));


	sf::Vector2f posmoneytext = {600,20 };
	sf::Vector2f posanimalHappinesstext = {1170,610 };
	sf::Vector2f pospeopleHappinesstext = { 1400,610 };
	sf::Vector2f posnumPeopletext = { 950, 20 };
	m_moneytext = m_textBox.build(m_money, FRONTSIZE, posmoneytext, m_moneytext);
	m_animalHappinesstext = m_textBox.build(m_animalHappiness, FRONTSIZE, posanimalHappinesstext, m_animalHappinesstext);
	m_peopleHappinessText = m_textBox.build(m_peopleHappiness, FRONTSIZE, pospeopleHappinesstext, m_peopleHappinessText);
	m_numberOfVisitorsText = m_textBox.build(m_initNumOfPeople, FRONTSIZE, posnumPeopletext, m_numberOfVisitorsText);
}


void StatusBar::draw(sf::RenderWindow & window)
{
	window.draw(*m_rect);
	window.draw(*m_rectHappiness);
	window.draw(m_moneytext);
	window.draw(m_animalHappinesstext);
	window.draw(m_peopleHappinessText);
	window.draw(m_numberOfVisitorsText);
}

void StatusBar::updateMoney(int CurrentMoney)
{
	m_moneytext.setString(std::to_string(CurrentMoney));
	m_money = CurrentMoney;
}

void StatusBar::updateAnimalHappiness(double CurrentHappiness)
{
	m_animalHappinesstext.setString(convertDoubleToInt(CurrentHappiness));
	m_animalHappiness = CurrentHappiness;
}

void StatusBar::updatePeopleHappiness(double CurrentHappiness)
{
	m_peopleHappinessText.setString(convertDoubleToInt(CurrentHappiness));
	m_peopleHappiness = CurrentHappiness;
}

void StatusBar::updateNumberOfVisitiors(int number)
{
	m_numberOfVisitors = number;
	m_numberOfVisitorsText.setString(std::to_string(number));
	

}

void StatusBar::saveStatusBar(std::ofstream & file) const
{
	file << "statusBar" << " " << "m_peopleHappiness" << " " << m_peopleHappiness << std::endl;
	file << "statusBar" << " " << "m_animalHappiness" << " " << m_animalHappiness << std::endl;
	file << "statusBar" << " " << "m_money"<< " " <<m_money << std::endl;
	file << "statusBar" << " " << "m_numberOfVisitorsText" << " " << m_numberOfVisitors << std::endl;

}

void StatusBar::loadStatusBar(std::string name, std::string data)
{

	std::string::size_type sz;     // alias of size_t

/*
	float posX = std::stof(x, &sz);
	float posY = std::stof(y, &sz);*/
	 //float n = std::stof(name, &sz);
	 int amount = std::stoi(data, &sz);

	 if (name == "m_money")
		 m_money = amount;
	 else if (name == "m_animalHappiness")
		 m_animalHappiness = amount;
	 else if (name == "m_numberOfVisitors")
		 m_numberOfVisitors = amount;
	else
		m_peopleHappiness = amount;



}


std::string StatusBar::convertDoubleToInt(double CurrentHappiness)
{
	std::ostringstream oss;
	oss.precision(0);
	oss << std::fixed << CurrentHappiness;
	std::string s= oss.str();
	return s;
}

StatusBar::~StatusBar()
{
}
