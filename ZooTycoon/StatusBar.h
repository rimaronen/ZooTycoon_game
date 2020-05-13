#pragma once
#include <SFML/Graphics.hpp>
#include "GameResources.h"
#include "TextBox.h"
#include "Economy.h"
const int FRONTSIZE =30;
class StatusBar
{
public:
	StatusBar();
	// draw status bar
	void draw(sf::RenderWindow& window);
	//update members
	void updateMoney(int CurrentMoney);
	void updateAnimalHappiness(double CurrentHappiness);
	void updatePeopleHappiness(double CurrentHappiness);
	void updateNumberOfVisitiors(int number);

	void saveStatusBar(std::ofstream & file) const ;
	void loadStatusBar(std::string name, std::string data);
	int getMoney()const { return m_money; };
	std::string convertDoubleToInt(double CurrentHappiness);
	~StatusBar();
private:
	// status bar texture and rectangle
	sf::Texture* m_statusBarTexture;
	sf::Texture* m_statusBarHappinessTexture;
	std::unique_ptr<sf::RectangleShape> m_rect = std::make_unique<sf::RectangleShape>();
	std::unique_ptr<sf::RectangleShape> m_rectHappiness = std::make_unique<sf::RectangleShape>();
	//std::unique_ptr<sf::Text> m_text = std::make_unique<sf::Text>();
	//sf::Font font;
	sf::Text m_numberOfVisitorsText;
	sf::Text m_moneytext;
	sf::Text m_animalHappinesstext;
	sf::Text m_peopleHappinessText;
	TextBox m_textBox;
	int m_initNumOfPeople = 0;
	int m_money =150000;
	double m_animalHappiness;
	double m_peopleHappiness;
	int m_numberOfVisitors;
};

