#pragma once
#include <utility>
#include "Button.h"
#include "CommandToolBar.h"
#include "SideMenuAnimals.h"
#include "SideMenuBuildings.h"
#include "SideMenuConstruction.h"
#include "SideMenu.h"
#include "Game.h"

enum side_menu_index_t { ANIMALS_SM, BUILDINGS_SM, CONSTRUCTION_SM, SAVE_SM, DELETE_SM, NONE_SM };
const float X = 100;
const float Y = 50;

class ToolBar
{
public:
	ToolBar(Game& game);
	//fraw the tool bar 
	void draw(sf::RenderWindow& window);
	//preccess the button that was clicked
	bool processMouseClick(sf::Vector2f coords);
	// check if side menu button is pressed 
	bool sideMenuButtonIsPressed(const sf::Vector2f& position);
	void setSideMenuIndex(side_menu_index_t index) { m_sideMenuIndex = (size_t)index; }
	//what was pressed in the side enu
	side_menu_index_t getSideMenuIndex() { return (side_menu_index_t)m_sideMenuIndex; }
	//if the save button was pressed
	void save() { m_save = true; }
	//if delete button was pressed
	void deleteOn() { m_dalete = true; }
	//to check if save was pressed 
	bool getSaveStat() const { return m_save; };
	//to check if tractor was pressed 
	bool getDeleteStat() const { return m_dalete; };
	//set delete status
	void setDeleteStat() { m_dalete = false; };
	// check if toolbar is bounds of press on the window
	bool inBounds(sf::Vector2f coords) const;
private:

	typedef std::pair<Button, std::unique_ptr<CommandToolBar>> option;
	std::vector <option> m_optionsToolBar;

	std::vector<std::unique_ptr<SideMenu>> m_sideMenues;

	std::unique_ptr<sf::RectangleShape> m_rect = std::make_unique<sf::RectangleShape>();
	sf::Texture* m_toolBarTexture;
	size_t m_sideMenuIndex = NONE_SM;

	const sf::Vector2f m_toolBarButtonSize = { 50.0f, 50.0f };
	Game& m_game;
	bool m_save;
	bool m_dalete;

};
