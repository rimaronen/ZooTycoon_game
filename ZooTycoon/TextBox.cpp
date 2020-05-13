#include "TextBox.h"
#include "GameResources.h"



TextBox::TextBox()
{
	text.setString("price:");
	text.setFont(*GameResources::instance().getTextFont());
	text.setCharacterSize(20);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);

		m_text.setFont(*GameResources::instance().getTextFont());
	m_text.setCharacterSize(20);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::White);
}


TextBox::~TextBox()
{
}

sf::Text TextBox::build(double money, int CharacterSize, sf::Vector2f pos, sf::Text m_text)
{
	//m_text.setString(std::to_string(m_user_area));
	m_text.setString(std::to_string(money));
	m_text.setFont(*GameResources::instance().getTextFont());
	m_text.setCharacterSize(CharacterSize);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(pos);
	return m_text;
}

