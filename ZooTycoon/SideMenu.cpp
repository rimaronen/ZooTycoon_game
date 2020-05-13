#include "SideMenu.h"
#include "GameResources.h"

SideMenu::SideMenu(sf::Vector2f location, Game & game)
	:m_location(location), m_game(game)
{	


}

bool SideMenu::isPressed(const sf::Vector2f& position)
{
	for (auto option : m_options)
		if (option.first.isPressed(position))
			return true;
	return false;
}

void SideMenu::draw(sf::RenderWindow& window)
{
	window.draw(*m_rect);
	for (auto & button : m_options)
	{
		button.first.draw(window);
	}
}

