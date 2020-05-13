#pragma once
#include "GameResources.h"
#include "SideMenu.h"
#include "Lion.h"

class SideMenuAnimals: public SideMenu
{
public:
	SideMenuAnimals(sf::Vector2f location, Game &game);
	//creates the objects that was pressed
	virtual bool executeIfPressed(sf::Vector2f position) override;
};