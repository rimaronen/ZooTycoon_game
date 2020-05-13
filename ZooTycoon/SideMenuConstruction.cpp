#include<typeinfo>
#include "SideMenuConstruction.h"
#include "Fence.h"
#include "Path.h"
#include "Rock.h"
#include "Tree.h"
#include "Dirt.h"
#include "Savannah.h"
#include "Water.h"
#include "Snow.h"
#include "HerbivorFood.h"
#include "PredatorFood.h"



const sf::Vector2f FRON_LEFT_DIRECTION = { 80,50 };
const sf::Vector2f FRONT_RIGHT_DIRECTION = { 128 ,50 };
const sf::Vector2f BACK_LEFT_DIRECTION = { 80,100};
const sf::Vector2f BACK_RIGHT_DIRECTION = { 128,100 };


SideMenuConstruction::SideMenuConstruction(sf::Vector2f location, Game & game) :SideMenu(location, game)
{
	sf::Vector2f new_location = { location.x + 20, location.y + 30 };


	m_options.emplace_back(option{ Button{ GameResources::instance().getPathTexture(),
		{new_location.x ,new_location.y  }, m_SideBarButtonSize}, Path::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRockTexture(),
			{new_location.x + GAP ,new_location.y }, m_SideBarButtonSize }, Rock::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getTreeTexture(),
		{new_location.x,new_location.y + 50}, m_SideBarButtonSize }, Tree::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getdirtTexture(),
		{new_location.x + GAP,new_location.y + 50}, m_SideBarButtonSize}, Dirt::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getsavannahTexture(), 
		{new_location.x ,new_location.y +100 }, m_SideBarButtonSize }, Savannah::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getWaterTexture(),
		{new_location.x + GAP,new_location.y + 100 }, m_SideBarButtonSize }, Water::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getSnowTexture(),
		{new_location.x ,new_location.y +150 }, m_SideBarButtonSize }, Snow::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getherbivorFoodTexture(), //change
		{new_location.x + GAP,new_location.y + 150}, m_SideBarButtonSize }, HerbivorFood::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getpreditorFoodTexture(),
		{new_location.x ,new_location.y + 200 }, m_SideBarButtonSize }, PredatorFood::NAME });


	m_sideBarMenuTexture = GameResources::instance().getConstractionToolBarTexture();
	m_rect->setTexture(m_sideBarMenuTexture);
	m_rect->setSize(sf::Vector2f((float)m_sideBarMenuTexture->getSize().x + 10, (float)m_sideBarMenuTexture->getSize().y + 10));
	m_rect->setPosition(40.0f, 8.0f);
}

bool SideMenuConstruction::executeIfPressed(sf::Vector2f position)
{
	for (auto & option : m_options)
		if (option.first.isPressed(position))
		{
			if (!m_game.addConstruction(option.second))
				m_game.addTerrain(option.second);
			return true;

		}
	return false;
}

void SideMenuConstruction::changeConstrctionDirection()
{
	m_game.getDirection();
}

