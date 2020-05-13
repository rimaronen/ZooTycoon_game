#include "SideMenuBuildings.h"
#include "Bathroom.h"
#include "Restaurant.h"
#include "DrinkingStand.h"
#include <string>
#include "Burger.h"
#include "ChickerNugets.h"
#include "CuttonCandy.h"
#include "Fence.h"

const int MIN_NUM_OF_POSITION = 0;
const int MAX_NUM_OF_POSITION = 4;
const std::string ROTATE = "Rotate";
const int FACTOR = 6;
sf::Vector2u MAX_RANGE = { 18,24 };
sf::Vector2u DEFAULT_RANGE = { 0,6 };

SideMenuBuildings::SideMenuBuildings(sf::Vector2f location, Game & game) :SideMenu(location, game)
{
	sf::Vector2f new_location = { location.x + 10, location.y + 60 };


	m_options.emplace_back(option{ Button{ GameResources::instance().getChickenFrontLeft(),
		{new_location.x + GAP ,new_location.y }, m_SideBarButtonSize}, ChickerNugets::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getBurgerFrontLeft(),
	{new_location.x ,new_location.y}, m_SideBarButtonSize}, Burger::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getCuttonCandyLeft(),
	{new_location.x ,new_location.y + 50}, m_SideBarButtonSize}, CuttonCandy::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRestroomFrontLeft(),
	{new_location.x + 50 ,new_location.y + 50}, m_SideBarButtonSize}, Bathroom::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getDrinkFrontLeft(),
	{new_location.x + GAP ,new_location.y + 100 }, m_SideBarButtonSize}, DrinkingStand::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getFenceFrontLeftButtonTexture(),
	{new_location.x  ,new_location.y + 100 }, m_SideBarButtonSize}, Fence::NAME });




	m_options.emplace_back(option{ Button{ GameResources::instance().getChickenFrontRight(),
	{new_location.x + GAP ,new_location.y  }, m_SideBarButtonSize}, ChickerNugets::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getBurgerFrontRight(),
		{new_location.x  ,new_location.y  }, m_SideBarButtonSize}, Burger::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getCuttonCandyRight(),
		{new_location.x ,new_location.y + 50}, m_SideBarButtonSize}, CuttonCandy::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRestroomFrontRight(),
		{new_location.x + 50  ,new_location.y + 50  }, m_SideBarButtonSize}, Bathroom::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getDrinkFrontRight(),
	{new_location.x + GAP ,new_location.y + 100 }, m_SideBarButtonSize}, DrinkingStand::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getFenceFrontRightButtonTexture(),
	{new_location.x  ,new_location.y + 100 }, m_SideBarButtonSize}, Fence::NAME });


	m_options.emplace_back(option{ Button{ GameResources::instance().getChickenBackRight(),
		{new_location.x + GAP ,new_location.y }, m_SideBarButtonSize}, ChickerNugets::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getBurgerBackRight(),
	{new_location.x  ,new_location.y }, m_SideBarButtonSize}, Burger::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getCuttonCandyBackRight(),
	{new_location.x ,new_location.y + 50 }, m_SideBarButtonSize}, CuttonCandy::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRestroomBackRight(),
		{new_location.x + 50 ,new_location.y + 50 }, m_SideBarButtonSize}, Bathroom::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getDrinkBackRight(),
	{new_location.x + GAP ,new_location.y + 100 }, m_SideBarButtonSize}, DrinkingStand::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getFenceRightButtonTexture(),
		{new_location.x  ,new_location.y + 100 }, m_SideBarButtonSize}, Fence::NAME });


	m_options.emplace_back(option{ Button{ GameResources::instance().getChickenBackLeft(),
	{new_location.x + GAP ,new_location.y  }, m_SideBarButtonSize}, ChickerNugets::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getBurgerBacktLeft(),
		{new_location.x ,new_location.y  }, m_SideBarButtonSize}, Burger::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getCuttonCandyBackLeft(),
	{new_location.x ,new_location.y + 50}, m_SideBarButtonSize}, CuttonCandy::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRestroomBacktLeft(),
	{new_location.x + 50 ,new_location.y + 50}, m_SideBarButtonSize}, Bathroom::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getDrinkBacktLeft(),
	{new_location.x + GAP ,new_location.y + 100 }, m_SideBarButtonSize}, DrinkingStand::NAME });

	m_options.emplace_back(option{ Button{ GameResources::instance().getFenceLeftButtonTexture(),
	{new_location.x  ,new_location.y + 100 }, m_SideBarButtonSize}, Fence::NAME });



	m_options.emplace_back(option{ Button{ GameResources::instance().getRotateLeft(),
	{new_location.x + GAP ,new_location.y + 250}, m_SideBarButtonSize}, ROTATE });

	m_options.emplace_back(option{ Button{ GameResources::instance().getRotateRight(),
		{new_location.x ,new_location.y + 250}, m_SideBarButtonSize}, ROTATE });


	m_sideBarMenuTexture = GameResources::instance().getBuildingSideBarTexture();
	m_rect->setTexture(m_sideBarMenuTexture);
	m_rect->setSize(sf::Vector2f((float)m_sideBarMenuTexture->getSize().x + 10, (float)m_sideBarMenuTexture->getSize().y + 10));
	m_rect->setPosition(40.0f, 8.0f);


}

bool SideMenuBuildings::executeIfPressed(sf::Vector2f position)
{

	for (auto & option : m_options) {
		if (option.first.isPressed(position))
		{
			m_game.addBuilding(option.second);
			return true;
		}
		if (rotate(position))
			return false;
	}

	return false;
}



void SideMenuBuildings::draw(sf::RenderWindow & window)
{

	window.draw(*m_rect);
	m_options[24].first.draw(window);
	m_options[25].first.draw(window);

	for (int i = m_range.x; i < m_range.y; ++i)
		m_options[i].first.draw(window);
}

void SideMenuBuildings::rotateRight()
{
	unsigned direction = (unsigned)m_game.getDirection();
	if (m_range.y >= MAX_RANGE.y && m_range.x >= MAX_RANGE.x) {
		m_range = DEFAULT_RANGE;
		m_game.setDirection(FRONT_LEFT);
	}
	else {
		m_range.x += FACTOR;
		m_range.y += FACTOR;
		direction++;
		if (direction > MAX_NUM_OF_POSITION)
			m_game.setDirection(FRONT_LEFT);
		m_game.setDirection((direction_t)direction);
	}

}

void SideMenuBuildings::rotateLeft()
{
	int direction = (int)m_game.getDirection();

	if (m_range.y <= DEFAULT_RANGE.y && m_range.x <= DEFAULT_RANGE.x) {
		m_range = MAX_RANGE;
		m_game.setDirection(BACK_LEFT);
	}
	else {
		m_range.x -= FACTOR;
		m_range.y -= FACTOR;
		direction--;
		if (direction < MIN_NUM_OF_POSITION)
			m_game.setDirection(BACK_RIGHT);
		m_game.setDirection((direction_t)direction);

	}

}

bool SideMenuBuildings::rotate(sf::Vector2f position)
{

	if (m_options[24].first.isPressed(position)) {
		rotateLeft();
		return true;
	}

	else if (m_options[25].first.isPressed(position)) {
		rotateRight();
		return true;
	}
}
