#pragma once
#include "GameResources.h"
#include "SideMenu.h"
class SideMenuBuildings: public SideMenu
{
public:
	//building menu
	SideMenuBuildings(sf::Vector2f location, Game & game);
	virtual bool executeIfPressed(sf::Vector2f position) override;
	virtual void draw(sf::RenderWindow & window);
	void rotateRight();
	void rotateLeft();
	bool rotate(sf::Vector2f position);
private:

	sf::Vector2u m_range = { 0,6 };
};

