#pragma once
#include "GameResources.h"
#include "SideMenu.h"

class SideMenuConstruction: public SideMenu
{
public:
	//constuction menu
	SideMenuConstruction(sf::Vector2f location, Game & game);
	virtual bool executeIfPressed(sf::Vector2f position) override;
	void changeConstrctionDirection();
};

