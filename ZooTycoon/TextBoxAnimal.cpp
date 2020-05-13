#include "TextBoxAnimal.h"
#include "GameResources.h"


TextBoxAnimal::TextBoxAnimal()
{
	text.setPosition(63.0f, 330.0f);
	m_text.setPosition(125.0f, 330.0f);
}


TextBoxAnimal::~TextBoxAnimal()
{

}

void TextBoxAnimal::setPrice(std::string price)
{
	m_text.setString(price);

}
void TextBoxAnimal::draw(sf::RenderWindow & window)
{
	window.draw(text);
	window.draw(m_text);
}