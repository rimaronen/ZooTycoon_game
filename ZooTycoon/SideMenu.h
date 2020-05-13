#pragma once
#include "GameResources.h"
#include "CommandMenu.h"
#include "Button.h"
#include "Game.h"
#include <string>

class SideMenu
{
public:
	SideMenu(sf::Vector2f location, Game & game);
	// execture command if the button is pressed
	virtual bool executeIfPressed(sf::Vector2f position)=0;
	// check if button is pressed
	virtual bool isPressed(const sf::Vector2f& position);
	//draws side menus
	virtual void draw(sf::RenderWindow& window);
protected:
	//each button is a pair if the button and the name of it
	typedef std::pair<Button, std::string> option;
	//all the button to click
	std::vector <option> m_options;
	//location for the buttons
	sf::Vector2f m_location;
	//gap between the beginning of the enu to where the buttons are  located
	const int GAP = 48;
	Game & m_game;
	//size of button
	const sf::Vector2f m_SideBarButtonSize = { 47.0f, 33.0f };
	sf::Texture *m_sideBarMenuTexture;
	//for textures
	std::unique_ptr<sf::RectangleShape> m_rect = std::make_unique<sf::RectangleShape>();
	
	
};

