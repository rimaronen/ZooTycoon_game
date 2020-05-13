#include "TextBoxConstruction.h"
#include "GameResources.h"


TextBoxConstruction::TextBoxConstruction()
{
	text.setPosition(70.0f, 400.0f);
	m_text.setPosition(135.0f, 400.0f);
}


TextBoxConstruction::~TextBoxConstruction()
{
}

void TextBoxConstruction::setPrice(std::string price)
{
	m_text.setString(price);
}

void TextBoxConstruction::draw(sf::RenderWindow & window)
{
	window.draw(text);
	window.draw(m_text);
}

