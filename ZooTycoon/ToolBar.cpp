#include "ToolBar.h"
#include "GameResources.h"
#include "AnimalMenuCommand.h"
#include "BuildingMenuCommand.h"
#include "ConstructionMenuCommand.h"
#include "SaveMenuCommand.h"
#include "DeleteMenuCommand.h"
#include "wintools.h"

ToolBar::ToolBar(Game& game)
	:m_game(game)
{
	m_optionsToolBar.emplace_back(option{ Button{ GameResources::instance().getAnimalsButtonTexture(),
		sf::Vector2f({ 7,5 }), m_toolBarButtonSize }, std::make_unique<AnimalMenuCommand>(*this) });

	m_optionsToolBar.emplace_back(option{ Button{ GameResources::instance().getBuildingsButtonTexture(),
			sf::Vector2f({ 7,55 }), m_toolBarButtonSize}, std::make_unique<BuildingMenuCommand>(*this) });

	m_optionsToolBar.emplace_back(option{ Button{ GameResources::instance().getConstructionButtonTexture(),
			sf::Vector2f({ 7 ,110 }), m_toolBarButtonSize }, std::make_unique<ConstructionMenuCommand>(*this) });

	m_optionsToolBar.emplace_back(option{ Button{ GameResources::instance().getSaveButtonTexture(),
			sf::Vector2f({ 7 ,160 }), m_toolBarButtonSize }, std::make_unique<SaveMenuCommand>(*this) });

	m_optionsToolBar.emplace_back(option{ Button{ GameResources::instance().getDeleteButtonTexture(),
			sf::Vector2f({ 7 ,210 }), m_toolBarButtonSize }, std::make_unique<DeleteMenuCommand>(*this) });
	//for (int i = 0; i < m_options.size(); ++i)
	m_sideMenues.emplace_back(std::make_unique<SideMenuAnimals>(sf::Vector2f({ 48,30 }), game));
	m_sideMenues.emplace_back(std::make_unique<SideMenuBuildings>(sf::Vector2f({ 60,20 }), game));
	m_sideMenues.emplace_back(std::make_unique<SideMenuConstruction>(sf::Vector2f({ 60,20 }), game));



	m_toolBarTexture = GameResources::instance().getToolBarTexture();
	m_rect->setTexture(m_toolBarTexture);
	m_rect->setSize(sf::Vector2f((float)m_toolBarTexture->getSize().x + 10, (float)m_toolBarTexture->getSize().y + 10));
	m_rect->setPosition(0.0f, 0.0f);
}

void ToolBar::draw(sf::RenderWindow & window)
{

	if (ANIMALS_SM <= (side_menu_index_t)m_sideMenuIndex &&
		(side_menu_index_t)m_sideMenuIndex < NONE_SM) {
		m_sideMenues[m_sideMenuIndex]->draw(window);
		//if (m_sideMenuIndex == ANIMALS_SM)
		m_game.drawTextBox(window);
		//m_game.drawTextBox(m_sideMenuIndex);


	}
	window.draw(*m_rect);
	for (auto& button : m_optionsToolBar)
	{
		button.first.draw(window);
	}
}

bool ToolBar::processMouseClick(sf::Vector2f coords)
{
	//size_t size = m_optionsToolBar.size();
	for (auto& button : m_optionsToolBar)
	{
		if (button.first.isPressed(coords))
		{
			button.second->execute();
			if (m_sideMenuIndex == SAVE_SM)
				return false;

			if (m_sideMenuIndex == DELETE_SM)
				return false;
			return true;
		}
	}

	if (getSideMenuIndex() == NONE_SM)
		return false;
	if (!m_sideMenues.empty())
		if (m_sideMenues[getSideMenuIndex()]->executeIfPressed(coords))
			return true;

	return false;
}

bool ToolBar::sideMenuButtonIsPressed(const sf::Vector2f & position)
{
	for (size_t index = 0; index < m_sideMenues.size(); ++index)
		if (m_sideMenues[index]->isPressed(position))
			return true;
	return false;
}

bool ToolBar::inBounds(sf::Vector2f coords) const
{
	return m_rect->getGlobalBounds().contains(coords);
}
