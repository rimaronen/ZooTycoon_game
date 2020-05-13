#include "TextBoxBuilding.h"
#include "GameResources.h"


TextBoxBuilding::TextBoxBuilding()
{
	text.setPosition(70.0f, 370.0f);
	m_text.setPosition(135.0f, 370.0f);
}


TextBoxBuilding::~TextBoxBuilding()
{
}

void TextBoxBuilding::setPrice(std::string price)
{

	m_text.setString(price);
	
}

void TextBoxBuilding::draw(sf::RenderWindow & window)
{
	window.draw(text);
	window.draw(m_text);
}
