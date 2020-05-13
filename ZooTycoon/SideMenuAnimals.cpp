#include "SideMenuAnimals.h"
#include "Button.h"
#include "CommandMenu.h"
#include "Lion.h"
#include "PollarBear.h"
#include "Giraffe.h"
#include "Hippo.h"
#include "Elephant.h"
#include <string>
#include "ToolBar.h"

SideMenuAnimals::SideMenuAnimals( sf::Vector2f location, Game & game):SideMenu(location, game)
{
	sf::Vector2f new_location = { location.x + 20, location.y + 30 };

	m_options.emplace_back(option{ Button{ GameResources::instance().getLionButtonTexture(),
		{new_location.x,new_location.y + 5 }, m_SideBarButtonSize }, Lion::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getElephantButtonTexture(),
		{new_location.x,new_location.y + GAP }, m_SideBarButtonSize}, Elephant::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getGiraffeButtonTexture(),
			{new_location.x  ,new_location.y + 2*GAP-5 }, m_SideBarButtonSize }, Giraffe::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getHippoButtonTexture(),
			{new_location.x + 53,new_location.y + 5 }, m_SideBarButtonSize }, Hippo::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getPollarBearButtonTexture(),
		{new_location.x+ 53 ,new_location.y + GAP}, m_SideBarButtonSize }, PollarBear::NAME });


	m_sideBarMenuTexture = GameResources::instance().getAnimalSideBarTexture();
	m_rect->setTexture(m_sideBarMenuTexture);
	m_rect->setSize(sf::Vector2f((float)m_sideBarMenuTexture->getSize().x + 10, (float)m_sideBarMenuTexture->getSize().y + 10));
	m_rect->setPosition(40.0f,8.0f);

}

bool SideMenuAnimals::executeIfPressed(sf::Vector2f position)
{
	for (auto & option : m_options)
		if (option.first.isPressed(position))
		{
			m_game.addAnimal(option.second);
			return true;
		}
	return false;
}


